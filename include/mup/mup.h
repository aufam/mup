#ifndef MUP_MUP_H
#define MUP_MUP_H

#include <string>
#include <vector>

namespace mup {

    template <size_t N>
    struct Attr;

    template <bool self_closing, Attr name, Attr... attr>
    struct Element;

    template <size_t N>
    struct Attr {
        char value[N - 1]{}; // non null terminated

        constexpr Attr() = default;

        constexpr Attr(const char (&s)[N]) {
            for (std::size_t i = 0; i < N - 1; ++i)
                value[i] = s[i];
        }

        constexpr std::size_t size() const {
            return N - 1;
        }

        constexpr std::string_view str() const {
            return {value, N - 1};
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
    };

    template <Attr a>
    consteval auto operator""_attr() {
        return a;
    }

    void __test__() {
        constexpr auto a = "test"_attr;
        constexpr auto b = a.add_attr("foo"_attr);
        constexpr auto c = a.add_attr("foo"_attr, "bar"_attr);
        constexpr auto d = a.add_attr("foo"_attr, "bar"_attr, "baz"_attr);

        static_assert(a.str() == std::string_view("test"));
        static_assert(b.str() == std::string_view("test foo"));
        static_assert(c.str() == std::string_view("test foo bar"));
        static_assert(d.str() == std::string_view("test foo bar baz"));
    }

    template <typename T>
    concept Child = std::convertible_to<T, std::string> || std::is_arithmetic_v<T>;

    std::string child_to_string(Child auto child) {
        using T = decltype(child);
        if constexpr (std::is_same_v<T, bool>) {
            return child ? "true" : "false";
        } else if constexpr (std::convertible_to<T, std::string>) {
            return std::string(std::move(child));
        } else {
            return std::to_string(child);
        }
    }

    template <Attr name, Attr... attr>
    struct Element<true, name, attr...> {
        explicit Element(Child auto... children) {
            std::vector<std::string> vec = {child_to_string(std::move(children))...};

            size_t total_size = 0;
            bool   first      = true;
            for (auto &s : vec) {
                if (!s.empty()) {
                    total_size += (first ? 1 : 0) + s.size() + 1;
                    first = false;
                }
            }

            content.reserve(total_size);
            first = true;
            for (auto &s : vec) {
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
            for (auto attribute : attributes) {
                expected_size += 1 + attribute.size();
            }
            expected_size += content.size();
            expected_size += name.size();
            expected_size += 5;

            std::string res;
            res.reserve(expected_size);

            res += '<';
            res += a.str();
            for (auto attribute : attributes) {
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

        std::vector<std::string_view> attributes;
        std::string                   content;
    };

    template <Attr name, Attr... attr>
    struct Element<false, name, attr...> {
        operator std::string() const {
            constexpr Attr a = name.add_attr(attr...);

            size_t expected_size = a.size();
            for (auto attribute : attributes) {
                expected_size += 1 + attribute.size();
            }
            expected_size += 2;

            std::string res;
            res.reserve(expected_size);

            res += '<';
            res += a.str();
            for (auto attribute : attributes) {
                res += ' ';
                res += attribute;
            }
            res += '>';

            return res;
        }

        std::vector<std::string_view> attributes;
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
