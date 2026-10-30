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
    using main_ = Element<true, "main", attr...>;

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
    constexpr Element<false, "link", attr...> link_;

    template <Attr... attr>
    constexpr Element<false, "meta", attr...> meta;

    template <Attr... attr>
    constexpr Element<false, "source", attr...> source;

    template <Attr... attr>
    constexpr Element<false, "track", attr...> track;

    template <Attr... attr>
    constexpr Element<false, "wbr", attr...> wbr;


    // Global attributes

    inline constexpr Attr id_              = "id";
    inline constexpr Attr class_           = "class";
    inline constexpr Attr style_           = "style";
    inline constexpr Attr title_           = "title";
    inline constexpr Attr lang_            = "lang";
    inline constexpr Attr dir_             = "dir";
    inline constexpr Attr hidden_          = "hidden";
    inline constexpr Attr tabindex_        = "tabindex";
    inline constexpr Attr role_            = "role";
    inline constexpr Attr slot_            = "slot";
    inline constexpr Attr draggable_       = "draggable";
    inline constexpr Attr contenteditable_ = "contenteditable";
    inline constexpr Attr spellcheck_      = "spellcheck";
    inline constexpr Attr translate_       = "translate";
    inline constexpr Attr accesskey_       = "accesskey";
    inline constexpr Attr autofocus_       = "autofocus";

    // Form attributes

    inline constexpr Attr name_           = "name";
    inline constexpr Attr value_          = "value";
    inline constexpr Attr type_           = "type";
    inline constexpr Attr placeholder_    = "placeholder";
    inline constexpr Attr required_       = "required";
    inline constexpr Attr disabled_       = "disabled";
    inline constexpr Attr readonly_       = "readonly";
    inline constexpr Attr checked_        = "checked";
    inline constexpr Attr selected_       = "selected";
    inline constexpr Attr multiple_       = "multiple";
    inline constexpr Attr autocomplete_   = "autocomplete";
    inline constexpr Attr minlength_      = "minlength";
    inline constexpr Attr maxlength_      = "maxlength";
    inline constexpr Attr min_            = "min";
    inline constexpr Attr max_            = "max";
    inline constexpr Attr step_           = "step";
    inline constexpr Attr pattern_        = "pattern";
    inline constexpr Attr rows_           = "rows";
    inline constexpr Attr cols_           = "cols";
    inline constexpr Attr wrap_           = "wrap";
    inline constexpr Attr accept_         = "accept";
    inline constexpr Attr capture_        = "capture";
    inline constexpr Attr for_            = "for";
    inline constexpr Attr form_           = "form";
    inline constexpr Attr formaction_     = "formaction";
    inline constexpr Attr formenctype_    = "formenctype";
    inline constexpr Attr formmethod_     = "formmethod";
    inline constexpr Attr formnovalidate_ = "formnovalidate";
    inline constexpr Attr formtarget_     = "formtarget";

    // Link and resource attributes

    inline constexpr Attr href_            = "href";
    inline constexpr Attr src_             = "src";
    inline constexpr Attr alt_             = "alt";
    inline constexpr Attr target_          = "target";
    inline constexpr Attr rel_             = "rel";
    inline constexpr Attr download_        = "download";
    inline constexpr Attr media_           = "media";
    inline constexpr Attr integrity_       = "integrity";
    inline constexpr Attr crossorigin_     = "crossorigin";
    inline constexpr Attr referrerpolicy_  = "referrerpolicy";
    inline constexpr Attr loading_         = "loading";
    inline constexpr Attr fetchpriority_   = "fetchpriority";
    inline constexpr Attr async_           = "async";
    inline constexpr Attr defer_           = "defer";
    inline constexpr Attr width_           = "width";
    inline constexpr Attr height_          = "height";
    inline constexpr Attr srcset_          = "srcset";
    inline constexpr Attr sizes_           = "sizes";
    inline constexpr Attr sandbox_         = "sandbox";
    inline constexpr Attr allow_           = "allow";
    inline constexpr Attr allowfullscreen_ = "allowfullscreen";

    // Table attributes

    inline constexpr Attr colspan_ = "colspan";
    inline constexpr Attr rowspan_ = "rowspan";
    inline constexpr Attr headers_ = "headers";
    inline constexpr Attr scope_   = "scope";

    // Media attributes

    inline constexpr Attr controls_    = "controls";
    inline constexpr Attr autoplay_    = "autoplay";
    inline constexpr Attr loop_        = "loop";
    inline constexpr Attr muted_       = "muted";
    inline constexpr Attr playsinline_ = "playsinline";
    inline constexpr Attr poster_      = "poster";
    inline constexpr Attr preload_     = "preload";

    // Accessibility attributes

    inline constexpr Attr aria_label       = "aria-label";
    inline constexpr Attr aria_labelledby  = "aria-labelledby";
    inline constexpr Attr aria_describedby = "aria-describedby";
    inline constexpr Attr aria_hidden      = "aria-hidden";
    inline constexpr Attr aria_expanded    = "aria-expanded";
    inline constexpr Attr aria_controls    = "aria-controls";
    inline constexpr Attr aria_live        = "aria-live";
    inline constexpr Attr aria_pressed     = "aria-pressed";
    inline constexpr Attr aria_selected    = "aria-selected";
    inline constexpr Attr aria_disabled    = "aria-disabled";
    inline constexpr Attr aria_current     = "aria-current";
    inline constexpr Attr aria_invalid     = "aria-invalid";
    inline constexpr Attr aria_required    = "aria-required";
    inline constexpr Attr aria_haspopup    = "aria-haspopup";

    // HTMX attributes

    inline constexpr Attr hx_get          = "hx-get";
    inline constexpr Attr hx_post         = "hx-post";
    inline constexpr Attr hx_put          = "hx-put";
    inline constexpr Attr hx_patch        = "hx-patch";
    inline constexpr Attr hx_delete       = "hx-delete";
    inline constexpr Attr hx_target       = "hx-target";
    inline constexpr Attr hx_swap         = "hx-swap";
    inline constexpr Attr hx_trigger      = "hx-trigger";
    inline constexpr Attr hx_indicator    = "hx-indicator";
    inline constexpr Attr hx_push_url     = "hx-push-url";
    inline constexpr Attr hx_select       = "hx-select";
    inline constexpr Attr hx_swap_oob     = "hx-swap-oob";
    inline constexpr Attr hx_vals         = "hx-vals";
    inline constexpr Attr hx_headers      = "hx-headers";
    inline constexpr Attr hx_confirm      = "hx-confirm";
    inline constexpr Attr hx_disabled_elt = "hx-disabled-elt";
    inline constexpr Attr hx_include      = "hx-include";
    inline constexpr Attr hx_params       = "hx-params";
    inline constexpr Attr hx_sync         = "hx-sync";
    inline constexpr Attr hx_ext          = "hx-ext";
    inline constexpr Attr hx_boost        = "hx-boost";
    inline constexpr Attr hx_encoding     = "hx-encoding";
    inline constexpr Attr hx_preserve     = "hx-preserve";
    inline constexpr Attr hx_history_elt  = "hx-history-elt";
    inline constexpr Attr hx_history      = "hx-history";
    inline constexpr Attr hx_on           = "hx-on";
    inline constexpr Attr hx_request      = "hx-request";

    // Common event handler attributes

    inline constexpr Attr onclick_      = "onclick";
    inline constexpr Attr ondblclick_   = "ondblclick";
    inline constexpr Attr oninput_      = "oninput";
    inline constexpr Attr onchange_     = "onchange";
    inline constexpr Attr onsubmit_     = "onsubmit";
    inline constexpr Attr onreset_      = "onreset";
    inline constexpr Attr onkeydown_    = "onkeydown";
    inline constexpr Attr onkeyup_      = "onkeyup";
    inline constexpr Attr onkeypress_   = "onkeypress";
    inline constexpr Attr onfocus_      = "onfocus";
    inline constexpr Attr onblur_       = "onblur";
    inline constexpr Attr onload_       = "onload";
    inline constexpr Attr onerror_      = "onerror";
    inline constexpr Attr onmouseover_  = "onmouseover";
    inline constexpr Attr onmouseout_   = "onmouseout";
    inline constexpr Attr onmouseenter_ = "onmouseenter";
    inline constexpr Attr onmouseleave_ = "onmouseleave";
    inline constexpr Attr onscroll_     = "onscroll";
    inline constexpr Attr onwheel_      = "onwheel";

    // Other common attributes

    inline constexpr Attr datetime_       = "datetime";
    inline constexpr Attr cite_           = "cite";
    inline constexpr Attr open_           = "open";
    inline constexpr Attr start_          = "start";
    inline constexpr Attr reversed_       = "reversed";
    inline constexpr Attr manifest_       = "manifest";
    inline constexpr Attr nonce_          = "nonce";
    inline constexpr Attr content_        = "content";
    inline constexpr Attr charset_        = "charset";
    inline constexpr Attr http_equiv_     = "http-equiv";
    inline constexpr Attr action_         = "action";
    inline constexpr Attr method_         = "method";
    inline constexpr Attr enctype_        = "enctype";
    inline constexpr Attr novalidate_     = "novalidate";
    inline constexpr Attr accept_charset_ = "accept-charset";
} // namespace mup::html

#endif
