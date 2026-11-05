#ifndef MUP_MUP_H
#define MUP_MUP_H

#include <string>
#include <vector>

namespace mup {

    template <size_t N>
    struct Attr;

    struct RuntimeAttr;

    template <bool not_self_closing, Attr name, Attr... attr>
    struct Element;

    template <typename T>
    concept Value = std::convertible_to<T, std::string> || std::is_arithmetic_v<T>;

    struct RuntimeAttr {
        std::string attr;

        RuntimeAttr operator,(RuntimeAttr other) const {
            if (other.attr.empty())
                return *this;

            return {attr + " " + other.attr};
        }
    };

    template <typename T>
    struct is_attr : std::false_type {};

    template <size_t N>
    struct is_attr<Attr<N>> : std::true_type {};

    template <typename T>
    concept RuntimeAttrConcept = std::is_same_v<T, RuntimeAttr>;

    template <typename T>
    concept ValueOrAttr = Value<T> || RuntimeAttrConcept<T> || is_attr<T>::value;


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
        constexpr Attr<N + M> operator,(const Attr<M> &other) const {
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

        template <size_t M>
        constexpr Attr<N + M> operator,(const char (&s)[M]) const {
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

        template <size_t M>
        constexpr Attr<N + M + 2> operator=(const char (&s)[M]) const {
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

        // assume value string is html escaped
        RuntimeAttr operator=(Value auto v) const {
            using T = decltype(v);

            auto s = std::string(str());
            if constexpr (std::is_same_v<T, bool>) {
                return {v ? s : ""};
            } else if constexpr (std::convertible_to<T, std::string>) {
                return {s + "=\"" + std::string(std::move(v)) + "\""};
            } else {
                return {s + "=\"" + std::to_string(v) + "\""};
            }
        }

        RuntimeAttr operator,(RuntimeAttr other) const {
            return {std::string(str()) + " " + other.attr};
        }
    };

    template <Attr a>
    consteval auto operator""_attr() {
        return a;
    }

    inline void __test__() {
        constexpr Attr a = "a";
        constexpr Attr b = a = "b";

        static_assert(a.str() == std::string_view("a"));
        static_assert(b.str() == std::string_view("a=\"b\""));
    }

    std::string value_to_string(Value auto v) {
        using T = decltype(v);
        if constexpr (std::is_same_v<T, bool>) {
            return v ? "true" : "false";
        } else if constexpr (std::convertible_to<T, std::string>) {
            return std::string(std::move(v));
        } else {
            return std::to_string(v);
        }
    }

    template <Attr name, Attr... attr>
    struct Element<true, name, attr...> {
        explicit Element(ValueOrAttr auto... values) {
            std::vector<std::string> children;

            size_t children_count = 0, attributes_count = 0;
            (
                [&]() {
                    using T = std::remove_cvref_t<decltype(values)>;

                    if constexpr (RuntimeAttrConcept<T>) {
                        attributes_count++;
                    } else if constexpr (is_attr<T>::value) {
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
                    using T = std::remove_cvref_t<decltype(values)>;

                    if constexpr (RuntimeAttrConcept<T>) {
                        attributes.push_back(std::move(values.attr));
                    } else if constexpr (is_attr<T>::value) {
                        attributes.push_back(std::string(values.str()));
                    } else {
                        children.push_back(value_to_string(std::move(values)));
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

        auto operator()(RuntimeAttrConcept auto... attrs) const {
            auto ret = *this;
            ret.attributes.reserve(attributes.size() + sizeof...(attrs));
            (ret.attributes.push_back(attrs.attr), ...);
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
        constexpr Element() = default;

        explicit Element(RuntimeAttrConcept auto... rattr) {
            attributes = {std::move(rattr.attr)...};
        }

        auto operator()(RuntimeAttrConcept auto... attrs) const {
            auto ret = *this;
            ret.attributes.reserve(attributes.size() + sizeof...(attrs));
            (ret.attributes.push_back(attrs.attr), ...);
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

    template <std::ranges::input_range R, typename F>
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
    std::string when(bool test, F &&fn) {
        if (test)
            return std::string(fn());

        return {};
    }
} // namespace mup

#endif
