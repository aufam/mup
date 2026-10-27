#ifndef MUP_HTML_H
#define MUP_HTML_H

#include <mup/mup.h>

namespace mup::html {

    // Normal (non-void) elements

    template <Attr... attr>
    struct html : Element<true, "html", attr...> {
        using Element<true, "html", attr...>::Element;

        operator std::string() const {
            return "<!DOCTYPE html>\n" + Element<true, "html", attr...>::operator std::string();
        }
    };

    template <Attr... attr>
    using head = Element<true, "head", attr...>;

    template <Attr... attr>
    using title = Element<true, "title", attr...>;

    template <Attr... attr>
    using style = Element<true, "style", attr...>;

    template <Attr... attr>
    using script = Element<true, "script", attr...>;

    template <Attr... attr>
    using noscript = Element<true, "noscript", attr...>;

    template <Attr... attr>
    using body = Element<true, "body", attr...>;

    template <Attr... attr>
    using header = Element<true, "header", attr...>;

    template <Attr... attr>
    using footer = Element<true, "footer", attr...>;

    template <Attr... attr>
    using main = Element<true, "main", attr...>;

    template <Attr... attr>
    using nav = Element<true, "nav", attr...>;

    template <Attr... attr>
    using section = Element<true, "section", attr...>;

    template <Attr... attr>
    using article = Element<true, "article", attr...>;

    template <Attr... attr>
    using aside = Element<true, "aside", attr...>;

    template <Attr... attr>
    using address = Element<true, "address", attr...>;

    template <Attr... attr>
    using h1 = Element<true, "h1", attr...>;

    template <Attr... attr>
    using h2 = Element<true, "h2", attr...>;

    template <Attr... attr>
    using h3 = Element<true, "h3", attr...>;

    template <Attr... attr>
    using h4 = Element<true, "h4", attr...>;

    template <Attr... attr>
    using h5 = Element<true, "h5", attr...>;

    template <Attr... attr>
    using h6 = Element<true, "h6", attr...>;

    template <Attr... attr>
    using p = Element<true, "p", attr...>;

    template <Attr... attr>
    using div = Element<true, "div", attr...>;

    template <Attr... attr>
    using div_ = Element<true, "div", attr...>;

    template <Attr... attr>
    using span = Element<true, "span", attr...>;

    template <Attr... attr>
    using blockquote = Element<true, "blockquote", attr...>;

    template <Attr... attr>
    using pre = Element<true, "pre", attr...>;

    template <Attr... attr>
    using figure = Element<true, "figure", attr...>;

    template <Attr... attr>
    using figcaption = Element<true, "figcaption", attr...>;

    template <Attr... attr>
    using ol = Element<true, "ol", attr...>;

    template <Attr... attr>
    using ul = Element<true, "ul", attr...>;

    template <Attr... attr>
    using li = Element<true, "li", attr...>;

    template <Attr... attr>
    using dl = Element<true, "dl", attr...>;

    template <Attr... attr>
    using dt = Element<true, "dt", attr...>;

    template <Attr... attr>
    using dd = Element<true, "dd", attr...>;

    template <Attr... attr>
    using menu = Element<true, "menu", attr...>;

    template <Attr... attr>
    using a = Element<true, "a", attr...>;

    template <Attr... attr>
    using em = Element<true, "em", attr...>;

    template <Attr... attr>
    using strong = Element<true, "strong", attr...>;

    template <Attr... attr>
    using small = Element<true, "small", attr...>;

    template <Attr... attr>
    using s = Element<true, "s", attr...>;

    template <Attr... attr>
    using cite = Element<true, "cite", attr...>;

    template <Attr... attr>
    using q = Element<true, "q", attr...>;

    template <Attr... attr>
    using dfn = Element<true, "dfn", attr...>;

    template <Attr... attr>
    using abbr = Element<true, "abbr", attr...>;

    template <Attr... attr>
    using data = Element<true, "data", attr...>;

    template <Attr... attr>
    using time = Element<true, "time", attr...>;

    template <Attr... attr>
    using code = Element<true, "code", attr...>;

    template <Attr... attr>
    using var = Element<true, "var", attr...>;

    template <Attr... attr>
    using samp = Element<true, "samp", attr...>;

    template <Attr... attr>
    using kbd = Element<true, "kbd", attr...>;

    template <Attr... attr>
    using sub = Element<true, "sub", attr...>;

    template <Attr... attr>
    using sup = Element<true, "sup", attr...>;

    template <Attr... attr>
    using i = Element<true, "i", attr...>;

    template <Attr... attr>
    using b = Element<true, "b", attr...>;

    template <Attr... attr>
    using u = Element<true, "u", attr...>;

    template <Attr... attr>
    using mark = Element<true, "mark", attr...>;

    template <Attr... attr>
    using ruby = Element<true, "ruby", attr...>;

    template <Attr... attr>
    using rt = Element<true, "rt", attr...>;

    template <Attr... attr>
    using rp = Element<true, "rp", attr...>;

    template <Attr... attr>
    using bdi = Element<true, "bdi", attr...>;

    template <Attr... attr>
    using bdo = Element<true, "bdo", attr...>;

    template <Attr... attr>
    using ins = Element<true, "ins", attr...>;

    template <Attr... attr>
    using del = Element<true, "del", attr...>;

    template <Attr... attr>
    using form = Element<true, "form", attr...>;

    template <Attr... attr>
    using label = Element<true, "label", attr...>;

    template <Attr... attr>
    using button = Element<true, "button", attr...>;

    template <Attr... attr>
    using select = Element<true, "select", attr...>;

    template <Attr... attr>
    using datalist = Element<true, "datalist", attr...>;

    template <Attr... attr>
    using optgroup = Element<true, "optgroup", attr...>;

    template <Attr... attr>
    using option = Element<true, "option", attr...>;

    template <Attr... attr>
    using textarea = Element<true, "textarea", attr...>;

    template <Attr... attr>
    using output = Element<true, "output", attr...>;

    template <Attr... attr>
    using progress = Element<true, "progress", attr...>;

    template <Attr... attr>
    using meter = Element<true, "meter", attr...>;

    template <Attr... attr>
    using fieldset = Element<true, "fieldset", attr...>;

    template <Attr... attr>
    using legend = Element<true, "legend", attr...>;

    template <Attr... attr>
    using table = Element<true, "table", attr...>;

    template <Attr... attr>
    using caption = Element<true, "caption", attr...>;

    template <Attr... attr>
    using colgroup = Element<true, "colgroup", attr...>;

    template <Attr... attr>
    using thead = Element<true, "thead", attr...>;

    template <Attr... attr>
    using tbody = Element<true, "tbody", attr...>;

    template <Attr... attr>
    using tfoot = Element<true, "tfoot", attr...>;

    template <Attr... attr>
    using tr = Element<true, "tr", attr...>;

    template <Attr... attr>
    using th = Element<true, "th", attr...>;

    template <Attr... attr>
    using td = Element<true, "td", attr...>;

    template <Attr... attr>
    using audio = Element<true, "audio", attr...>;

    template <Attr... attr>
    using video = Element<true, "video", attr...>;

    template <Attr... attr>
    using canvas = Element<true, "canvas", attr...>;

    template <Attr... attr>
    using iframe = Element<true, "iframe", attr...>;

    template <Attr... attr>
    using object = Element<true, "object", attr...>;

    template <Attr... attr>
    using picture = Element<true, "picture", attr...>;

    template <Attr... attr>
    using map = Element<true, "map", attr...>;

    template <Attr... attr>
    using details = Element<true, "details", attr...>;

    template <Attr... attr>
    using summary = Element<true, "summary", attr...>;

    template <Attr... attr>
    using dialog = Element<true, "dialog", attr...>;

    template <Attr... attr>
    using slot = Element<true, "slot", attr...>;

    template <Attr... attr>
    using search = Element<true, "search", attr...>;

    template <Attr... attr>
    using svg = Element<true, "svg", attr...>;

    template <Attr... attr>
    using math = Element<true, "math", attr...>;

    // Void elements
    template <Attr... attr>
    constexpr Element<false, "area", attr...> area;

    template <Attr... attr>
    constexpr Element<false, "base", attr...> base;

    template <Attr... attr>
    constexpr Element<false, "br", attr...> br;

    template <Attr... attr>
    constexpr Element<false, "col", attr...> col;

    template <Attr... attr>
    constexpr Element<false, "embed", attr...> embed;

    template <Attr... attr>
    constexpr Element<false, "hr", attr...> hr;

    template <Attr... attr>
    constexpr Element<false, "img", attr...> img;

    template <Attr... attr>
    constexpr Element<false, "input", attr...> input;

    template <Attr... attr>
    constexpr Element<false, "link", attr...> link;

    template <Attr... attr>
    constexpr Element<false, "meta", attr...> meta;

    template <Attr... attr>
    constexpr Element<false, "source", attr...> source;

    template <Attr... attr>
    constexpr Element<false, "track", attr...> track;

    template <Attr... attr>
    constexpr Element<false, "wbr", attr...> wbr;

    // template <Attr... attr>
    // constexpr Element<false, "!DOCTYPE", attr...> doctype;
} // namespace mup::html

#endif
