#ifndef MUP_MUP_H
#define MUP_MUP_H

#include <string>
#include <vector>

namespace mup {

    template <size_t N>
    struct Attr;

    struct RuntimeAttr;

    template <bool self_closing, Attr name, Attr... attr>
    struct Element;

    template <typename T>
    concept Value = std::convertible_to<T, std::string> || std::is_arithmetic_v<T>;

    struct RuntimeAttr {
        std::string attr;
    };

    template <typename T>
    concept RuntimeAttrConcept = std::is_same_v<T, RuntimeAttr>;

    template <typename T>
    concept ValueOrAttr = Value<T> || RuntimeAttrConcept<T>;


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

        template <size_t M>
        constexpr Attr<N + M> concat(const Attr<M> &other, char separator = ' ') const {
            Attr<N + M> res;
            size_t      i = 0;

            for (char ch : this->str())
                res.value[i++] = ch;

            res.value[i++] = separator;

            for (char ch : other.str())
                res.value[i++] = ch;

            return res;
        }

        // concat two string at compile time with separator=' '
        template <size_t M>
        constexpr Attr<N + M> operator+(const Attr<M> &other) const {
            return concat(other);
        }

        template <size_t... M>
        constexpr auto add_attr(const Attr<M> &...attributes) const {
            if constexpr (sizeof...(M) == 0) {
                return *this;
            } else if constexpr (sizeof...(M) == 1) {
                return *this + (attributes, ...);
            } else {
                return *this + (attributes + ...);
            }
        }

        // assume value string is html escaped
        template <size_t M>
        constexpr Attr<N + M + 2> operator==(const char (&s)[M]) const {
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

        constexpr Attr<N> operator==(bool v) const {
            if (v)
                return *this;
            else
                return {};
        }

        // max 7 digit character
        constexpr Attr<N + 7 + 3> operator==(int v) const {
            Attr<N + 7 + 3> res;

            size_t i = 0;

            for (auto ch : str()) {
                res.value[i++] = ch;
            }

            unsigned int n;

            if (v < 0) {
                res.value[i++] = '-';
                n              = static_cast<unsigned int>(-(v + 1)) + 1;
            } else {
                n = static_cast<unsigned int>(v);
            }

            char   digits[10];
            size_t len = 0;

            do {
                digits[len++] = '0' + (n % 10);
                n /= 10;
            } while (n != 0);

            while (len > 0) {
                res.value[i++] = digits[--len];
            }
            res.value[i++] = '"';

            return res;
        }

        constexpr Attr<N + 7 + 3> operator==(double v) const {
            Attr<N + 7 + 3> res;

            size_t i = 0;

            for (auto ch : str()) {
                res.value[i++] = ch;
            }

            res.value[i++] = '=';
            res.value[i++] = '"';

            // Reserve one character for the decimal point and two for decimals.
            constexpr unsigned scale = 100;

            unsigned int n;

            if (v < 0) {
                res.value[i++] = '-';
                v              = -v;
            }

            n = static_cast<unsigned int>(v * scale + 0.5f);

            // Integer part
            unsigned int whole = n / scale;

            char   digits[4];
            size_t len = 0;

            do {
                digits[len++] = '0' + (whole % 10);
                whole /= 10;
            } while (whole != 0);

            while (len > 0) {
                res.value[i++] = digits[--len];
            }

            // Decimal point
            res.value[i++] = '.';

            // Two decimal digits
            res.value[i++] = '0' + ((n / 10) % 10);
            res.value[i++] = '0' + (n % 10);
            res.value[i++] = '"';

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
    };

    template <Attr a>
    consteval auto operator""_attr() {
        return a;
    }

    inline void __test__() {
        constexpr auto a = "test"_attr;
        constexpr auto b = a.add_attr("foo"_attr);
        constexpr auto c = a.add_attr("foo"_attr, "bar"_attr);
        constexpr auto d = a.add_attr("foo"_attr, "bar"_attr, "baz"_attr);

        static_assert(a.str() == std::string_view("test"));
        static_assert(b.str() == std::string_view("test foo"));
        static_assert(c.str() == std::string_view("test foo bar"));
        static_assert(d.str() == std::string_view("test foo bar baz"));
    }

    inline void __test2__() {
        constexpr Attr a = "a";
        constexpr Attr b = a == "b";
        constexpr Attr c = a == 3.14;
        constexpr Attr d = a == true;
        constexpr Attr e = a == false;

        static_assert(a.str() == std::string_view("a"));
        static_assert(b.str() == std::string_view("a=\"b\""));
        static_assert(c.str() == std::string_view("a=\"3.14\""));
        static_assert(d.str() == std::string_view("a"));
        static_assert(e.str().empty());
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

        operator std::string() const {
            constexpr Attr a = name.add_attr(attr...);

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

        operator std::string() const {
            constexpr Attr a = name.add_attr(attr...);

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
