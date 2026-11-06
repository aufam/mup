#ifndef MUP_MUP_H
#define MUP_MUP_H

#include <string>
#include <vector>
#include <optional>

namespace mup {

    /// compile time attribute
    template <size_t N>
    struct Attr;

    template <typename T>
    struct is_attr : std::false_type {};

    template <size_t N>
    struct is_attr<Attr<N>> : std::true_type {};

    /// run time attribute
    struct RuntimeAttr;

    /// mark up element
    template <bool not_self_closing, Attr name, Attr... attr>
    struct Element;


    /*
     * attribute types
     */

    struct RuntimeAttr {
        std::string attr;

        RuntimeAttr operator,(const RuntimeAttr &other) const;

        template <size_t N>
        RuntimeAttr operator,(const Attr<N> &other) const;
    };

    template <size_t N>
    struct Attr {
        char value[N - 1]{}; // non null terminated

        constexpr Attr() = default;

        constexpr Attr(const char (&s)[N]) {
            for (size_t i = 0; i < N - 1; ++i)
                value[i] = s[i];
        }

        constexpr std::size_t size() const {
            for (size_t i = 0; i < N - 1; ++i) {
                if (value[i] == '\0')
                    return i;
            }
            return N - 1;
        }

        constexpr std::string_view str() const {
            return {value, size()};
        }

        template <size_t... M>
        constexpr auto append(const Attr<M> &...attributes) const {
            return (*this, ..., attributes);
        }


        template <size_t M>
        constexpr Attr<N + M + 2> operator=(const char (&s)[M]) const;

        template <typename T>
        RuntimeAttr operator=(T v) const
            requires std::convertible_to<T, std::string> || std::is_arithmetic_v<T>;


        template <size_t M>
        constexpr Attr<N + M> operator,(const Attr<M> &other) const;

        template <size_t M>
        constexpr Attr<N + M> operator,(const char (&s)[M]) const;

        RuntimeAttr operator,(const RuntimeAttr &other) const;
    };

    /*
     * operator=
     */

    template <size_t N>
    template <size_t M>
    inline constexpr Attr<N + M + 2> Attr<N>::operator=(const char (&s)[M]) const {
        Attr<N + M + 2> res;

        size_t i = 0;
        for (; i < N - 1; ++i)
            res.value[i] = value[i];

        res.value[i++] = '=';
        res.value[i++] = '\"';

        for (std::size_t j = 0; j < M - 1; ++j)
            res.value[i++] = s[j];

        res.value[i++] = '\"';

        return res;
    }

    template <size_t N>
    template <typename T>
    inline RuntimeAttr Attr<N>::operator=(T v) const
        requires std::convertible_to<T, std::string> || std::is_arithmetic_v<T>
    {
        auto s = std::string(str());
        if constexpr (std::is_same_v<T, bool>) {
            return {v ? s : ""};
        } else if constexpr (std::convertible_to<T, std::string>) {
            return {s + "=\"" + std::string(std::move(v)) + "\""};
        } else {
            return {s + "=\"" + std::to_string(v) + "\""};
        }
    }


    /*
     * operator,
     */

    template <size_t N>
    template <size_t M>
    inline constexpr Attr<N + M> Attr<N>::operator,(const char (&s)[M]) const {
        Attr<N + M> res;
        size_t      i = 0;

        for (char ch : this->str())
            res.value[i++] = ch;

        if (M == 1) {
            res.value[i++] = '\0';
            return res;
        }

        res.value[i++] = ' ';

        for (char ch : s)
            if (ch != '\0')
                res.value[i++] = ch;

        return res;
    }

    template <size_t N>
    template <size_t M>
    inline constexpr Attr<N + M> Attr<N>::operator,(const Attr<M> &other) const {
        Attr<N + M> res;
        size_t      i = 0;

        for (char ch : this->str())
            res.value[i++] = ch;

        if (other.size() == 0) {
            res.value[i++] = '\0';
            return res;
        }

        res.value[i++] = ' ';

        for (char ch : other.str())
            res.value[i++] = ch;

        return res;
    }

    template <size_t N>
    inline RuntimeAttr Attr<N>::operator,(const RuntimeAttr &other) const {
        return {std::string(str()) + " " + other.attr};
    }

    template <size_t N>
    inline RuntimeAttr RuntimeAttr::operator,(const Attr<N> &other) const {
        const auto str = other.str();
        if (str.empty())
            return *this;

        return {attr + " " + std::string(str)};
    }

    inline RuntimeAttr RuntimeAttr::operator,(const RuntimeAttr &other) const {
        if (other.attr.empty())
            return *this;

        return {attr + " " + other.attr};
    }


    /*
     * element type
     */

    template <Attr name, Attr... attr>
    struct Element<true, name, attr...> {
        template <typename... T>
            requires(
                (is_attr<T>::value || std::is_same_v<T, RuntimeAttr> || std::convertible_to<T, std::string> ||
                 std::is_arithmetic_v<T>) &&
                ...
            )
        explicit Element(T... values) {
            std::vector<std::string> children;

            size_t children_count = 0, attributes_count = 0;
            (
                [&]() {
                    if constexpr (is_attr<T>::value || std::is_same_v<T, RuntimeAttr>) {
                        attributes_count++;
                    } else {
                        children_count++;
                    }
                }(),
                ...);

            children.reserve(children_count);
            attributes.reserve(attributes_count);
            (
                [&]() {
                    if constexpr (is_attr<T>::value) {
                        attributes.push_back(std::string(values.str()));
                    } else if constexpr (std::is_same_v<T, RuntimeAttr>) {
                        attributes.push_back(std::move(values.attr));
                    } else if constexpr (std::is_same_v<T, bool>) {
                        attributes.push_back(values ? "true" : "false");
                    } else if constexpr (std::convertible_to<T, std::string>) {
                        attributes.push_back(std::move(values));
                    } else {
                        attributes.push_back(std::to_string(values));
                    }
                }(),
                ...);

            size_t total_size = 0;
            bool   first      = true;
            for (auto &s : children) {
                if (!s.empty()) {
                    total_size += (first ? 1 : 0) + s.size() + 1;
                    first = false;
                }
            }

            content.reserve(total_size);
            first = true;
            for (auto &s : children) {
                if (!s.empty()) {
                    if (first)
                        content += '\n';
                    content += s;
                    content += '\n';
                    first = false;
                }
            }
        }

        template <typename... T>
        auto operator()(T... attrs) const
            requires((is_attr<T>::value || std::is_same_v<T, RuntimeAttr>) && ...)
        {
            auto ret = *this;
            ret.attributes.reserve(attributes.size() + sizeof...(attrs));
            (
                [&]() {
                    if constexpr (is_attr<T>::value) {
                        ret.attributes.push_back(std::string(attrs.str()));
                    } else {
                        ret.attributes.push_back(std::move(attrs.attr));
                    }
                }(),
                ...);
            return ret;
        }

        operator std::string() const {
            constexpr Attr a = name.append(attr...);

            size_t expected_size = a.size();
            for (auto &attribute : attributes) {
                expected_size += 1 + attribute.size();
            }
            expected_size += content.size();
            expected_size += name.size();
            expected_size += 5;

            std::string res;
            res.reserve(expected_size);

            res += '<';
            res += a.str();
            for (auto &attribute : attributes) {
                res += ' ';
                res += attribute;
            }
            res += '>';
            res += content;
            res += "</";
            res += name.str();
            res += ">";

            return res;
        }

        std::vector<std::string> attributes;
        std::string              content;
    };

    template <Attr name, Attr... attr>
    struct Element<false, name, attr...> {
        template <typename... T>
        constexpr explicit Element(T... attrs)
            requires((is_attr<T>::value || std::is_same_v<T, RuntimeAttr>) && ...)
        {
            if constexpr (sizeof...(attrs) > 0) {
                attributes.reserve(attributes.size() + sizeof...(attrs));
                (
                    [&]() {
                        if constexpr (is_attr<T>::value) {
                            attributes.push_back(std::string(attrs.str()));
                        } else {
                            attributes.push_back(std::move(attrs.attr));
                        }
                    }(),
                    ...);
            }
        }

        template <typename... T>
        auto operator()(T... attrs) const
            requires((is_attr<T>::value || std::is_same_v<T, RuntimeAttr>) && ...)
        {
            auto ret = *this;
            ret.attributes.reserve(attributes.size() + sizeof...(attrs));
            (
                [&]() {
                    if constexpr (is_attr<T>::value) {
                        ret.attributes.push_back(std::string(attrs.str()));
                    } else {
                        ret.attributes.push_back(std::move(attrs.attr));
                    }
                }(),
                ...);
            return ret;
        }

        operator std::string() const {
            constexpr Attr a = name.append(attr...);

            size_t expected_size = a.size();
            for (auto &attribute : attributes) {
                expected_size += 1 + attribute.size();
            }
            expected_size += 2;

            std::string res;
            res.reserve(expected_size);

            res += '<';
            res += a.str();
            for (auto &attribute : attributes) {
                res += ' ';
                res += attribute;
            }
            res += '>';

            return res;
        }

        std::vector<std::string> attributes;
    };


    /*
     * conditional
     */

    template <std::ranges::input_range R, typename F>
        requires std::convertible_to<std::invoke_result_t<F, std::ranges::range_reference_t<R>>, std::string>
    std::string each(R &&rng, F &&fn) {
        std::string res;

        bool first = true;
        for (auto &&item : rng) {
            if (auto s = std::string(fn(item)); !s.empty()) {
                if (!first)
                    res += '\n';
                res += std::string(fn(item));
                first = false;
            }
        }

        return res;
    }

    template <typename F>
    std::string when(bool test, F fn)
        requires std::convertible_to<std::invoke_result_t<F>, std::string>
    {
        if (test)
            return std::string(fn());

        return {};
    }

    template <typename T, typename F>
    std::string when(const std::optional<T> &opt, F fn)
        requires std::convertible_to<std::invoke_result_t<F, const T &>, std::string>
    {
        if (opt.has_value())
            return std::string(fn(*opt));

        return {};
    }


    /// literal operator
    template <Attr a>
    consteval auto operator""_attr() {
        return a;
    }

    /// test
    inline void __test__() {
        constexpr Attr a = "a";
        constexpr Attr b = a = "b";

        static_assert(a.str() == std::string_view("a"));
        static_assert(b.str() == std::string_view("a=\"b\""));

        Element<false, "input"> el1{};
        Element<false, "input"> el2{RuntimeAttr{"hidden"}};
        Element<false, "input"> el3{RuntimeAttr{"hidden"}, RuntimeAttr{"disabled"}};
    }
} // namespace mup

#endif
