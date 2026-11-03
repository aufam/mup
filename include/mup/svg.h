#ifndef MUP_SVG_H
#define MUP_SVG_H

#include <mup/mup.h>

namespace mup::svg {

    template <Attr... attr>
    using svg = Element<true, "svg", attr...>;

    template <Attr... attr>
    using a = Element<true, "a", attr...>;

    template <Attr... attr>
    using animate = Element<true, "animate", attr...>;

    template <Attr... attr>
    using animateMotion = Element<true, "animateMotion", attr...>;

    template <Attr... attr>
    using animateTransform = Element<true, "animateTransform", attr...>;

    template <Attr... attr>
    using circle = Element<true, "circle", attr...>;

    template <Attr... attr>
    using clipPath = Element<true, "clipPath", attr...>;

    template <Attr... attr>
    using defs = Element<true, "defs", attr...>;

    template <Attr... attr>
    using desc = Element<true, "desc", attr...>;

    template <Attr... attr>
    using ellipse = Element<true, "ellipse", attr...>;

    template <Attr... attr>
    using feBlend = Element<true, "feBlend", attr...>;

    template <Attr... attr>
    using feColorMatrix = Element<true, "feColorMatrix", attr...>;

    template <Attr... attr>
    using feComponentTransfer = Element<true, "feComponentTransfer", attr...>;

    template <Attr... attr>
    using feComposite = Element<true, "feComposite", attr...>;

    template <Attr... attr>
    using feConvolveMatrix = Element<true, "feConvolveMatrix", attr...>;

    template <Attr... attr>
    using feDiffuseLighting = Element<true, "feDiffuseLighting", attr...>;

    template <Attr... attr>
    using feDisplacementMap = Element<true, "feDisplacementMap", attr...>;

    template <Attr... attr>
    using feDistantLight = Element<true, "feDistantLight", attr...>;

    template <Attr... attr>
    using feDropShadow = Element<true, "feDropShadow", attr...>;

    template <Attr... attr>
    using feFlood = Element<true, "feFlood", attr...>;

    template <Attr... attr>
    using feFuncA = Element<true, "feFuncA", attr...>;

    template <Attr... attr>
    using feFuncB = Element<true, "feFuncB", attr...>;

    template <Attr... attr>
    using feFuncG = Element<true, "feFuncG", attr...>;

    template <Attr... attr>
    using feFuncR = Element<true, "feFuncR", attr...>;

    template <Attr... attr>
    using feGaussianBlur = Element<true, "feGaussianBlur", attr...>;

    template <Attr... attr>
    using feImage = Element<true, "feImage", attr...>;

    template <Attr... attr>
    using feMerge = Element<true, "feMerge", attr...>;

    template <Attr... attr>
    using feMergeNode = Element<true, "feMergeNode", attr...>;

    template <Attr... attr>
    using feMorphology = Element<true, "feMorphology", attr...>;

    template <Attr... attr>
    using feOffset = Element<true, "feOffset", attr...>;

    template <Attr... attr>
    using fePointLight = Element<true, "fePointLight", attr...>;

    template <Attr... attr>
    using feSpecularLighting = Element<true, "feSpecularLighting", attr...>;

    template <Attr... attr>
    using feSpotLight = Element<true, "feSpotLight", attr...>;

    template <Attr... attr>
    using feTile = Element<true, "feTile", attr...>;

    template <Attr... attr>
    using feTurbulence = Element<true, "feTurbulence", attr...>;

    template <Attr... attr>
    using filter = Element<true, "filter", attr...>;

    template <Attr... attr>
    using foreignObject = Element<true, "foreignObject", attr...>;

    template <Attr... attr>
    using g = Element<true, "g", attr...>;

    template <Attr... attr>
    using image = Element<true, "image", attr...>;

    template <Attr... attr>
    using line = Element<true, "line", attr...>;

    template <Attr... attr>
    using linearGradient = Element<true, "linearGradient", attr...>;

    template <Attr... attr>
    using marker = Element<true, "marker", attr...>;

    template <Attr... attr>
    using mask = Element<true, "mask", attr...>;

    template <Attr... attr>
    using metadata = Element<true, "metadata", attr...>;

    template <Attr... attr>
    using mpath = Element<true, "mpath", attr...>;

    template <Attr... attr>
    using path = Element<true, "path", attr...>;

    template <Attr... attr>
    using pattern = Element<true, "pattern", attr...>;

    template <Attr... attr>
    using polygon = Element<true, "polygon", attr...>;

    template <Attr... attr>
    using polyline = Element<true, "polyline", attr...>;

    template <Attr... attr>
    using radialGradient = Element<true, "radialGradient", attr...>;

    template <Attr... attr>
    using rect = Element<true, "rect", attr...>;

    template <Attr... attr>
    using set = Element<true, "set", attr...>;

    template <Attr... attr>
    using stop = Element<true, "stop", attr...>;

    template <Attr... attr>
    using switch_ = Element<true, "switch", attr...>;

    template <Attr... attr>
    using symbol = Element<true, "symbol", attr...>;

    template <Attr... attr>
    using text = Element<true, "text", attr...>;

    template <Attr... attr>
    using textPath = Element<true, "textPath", attr...>;

    template <Attr... attr>
    using tspan = Element<true, "tspan", attr...>;

    template <Attr... attr>
    using use = Element<true, "use", attr...>;


    // SVG core and geometry attributes

    inline constexpr Attr viewBox              = "viewBox";
    inline constexpr Attr viewBox_             = "viewBox";
    inline constexpr Attr preserveAspectRatio  = "preserveAspectRatio";
    inline constexpr Attr preserveAspectRatio_ = "preserveAspectRatio";
    inline constexpr Attr x                    = "x";
    inline constexpr Attr x_                   = "x";
    inline constexpr Attr y                    = "y";
    inline constexpr Attr y_                   = "y";
    inline constexpr Attr x1                   = "x1";
    inline constexpr Attr x1_                  = "x1";
    inline constexpr Attr y1                   = "y1";
    inline constexpr Attr y1_                  = "y1";
    inline constexpr Attr x2                   = "x2";
    inline constexpr Attr x2_                  = "x2";
    inline constexpr Attr y2                   = "y2";
    inline constexpr Attr y2_                  = "y2";
    inline constexpr Attr cx                   = "cx";
    inline constexpr Attr cx_                  = "cx";
    inline constexpr Attr cy                   = "cy";
    inline constexpr Attr cy_                  = "cy";
    inline constexpr Attr r                    = "r";
    inline constexpr Attr r_                   = "r";
    inline constexpr Attr rx                   = "rx";
    inline constexpr Attr rx_                  = "rx";
    inline constexpr Attr ry                   = "ry";
    inline constexpr Attr ry_                  = "ry";
    inline constexpr Attr width                = "width";
    inline constexpr Attr width_               = "width";
    inline constexpr Attr height               = "height";
    inline constexpr Attr height_              = "height";
    inline constexpr Attr d                    = "d";
    inline constexpr Attr d_                   = "d";
    inline constexpr Attr points               = "points";
    inline constexpr Attr points_              = "points";

    // Fill and stroke

    inline constexpr Attr fill               = "fill";
    inline constexpr Attr fill_              = "fill";
    inline constexpr Attr fill_opacity       = "fill-opacity";
    inline constexpr Attr fill_opacity_      = "fill-opacity";
    inline constexpr Attr fill_rule          = "fill-rule";
    inline constexpr Attr fill_rule_         = "fill-rule";
    inline constexpr Attr stroke             = "stroke";
    inline constexpr Attr stroke_            = "stroke";
    inline constexpr Attr stroke_width       = "stroke-width";
    inline constexpr Attr stroke_width_      = "stroke-width";
    inline constexpr Attr stroke_opacity     = "stroke-opacity";
    inline constexpr Attr stroke_opacity_    = "stroke-opacity";
    inline constexpr Attr stroke_linecap     = "stroke-linecap";
    inline constexpr Attr stroke_linecap_    = "stroke-linecap";
    inline constexpr Attr stroke_linejoin    = "stroke-linejoin";
    inline constexpr Attr stroke_linejoin_   = "stroke-linejoin";
    inline constexpr Attr stroke_miterlimit  = "stroke-miterlimit";
    inline constexpr Attr stroke_miterlimit_ = "stroke-miterlimit";
    inline constexpr Attr stroke_dasharray   = "stroke-dasharray";
    inline constexpr Attr stroke_dasharray_  = "stroke-dasharray";
    inline constexpr Attr stroke_dashoffset  = "stroke-dashoffset";
    inline constexpr Attr stroke_dashoffset_ = "stroke-dashoffset";

    // Transform

    inline constexpr Attr transform         = "transform";
    inline constexpr Attr transform_        = "transform";
    inline constexpr Attr transform_origin  = "transform-origin";
    inline constexpr Attr transform_origin_ = "transform-origin";
    inline constexpr Attr transform_box     = "transform-box";
    inline constexpr Attr transform_box_    = "transform-box";

    // Opacity and rendering

    inline constexpr Attr opacity          = "opacity";
    inline constexpr Attr opacity_         = "opacity";
    inline constexpr Attr display          = "display";
    inline constexpr Attr display_         = "display";
    inline constexpr Attr visibility       = "visibility";
    inline constexpr Attr visibility_      = "visibility";
    inline constexpr Attr vector_effect    = "vector-effect";
    inline constexpr Attr vector_effect_   = "vector-effect";
    inline constexpr Attr shape_rendering  = "shape-rendering";
    inline constexpr Attr shape_rendering_ = "shape-rendering";
    inline constexpr Attr image_rendering  = "image-rendering";
    inline constexpr Attr image_rendering_ = "image-rendering";
    inline constexpr Attr text_rendering   = "text-rendering";
    inline constexpr Attr text_rendering_  = "text-rendering";

    // Text

    inline constexpr Attr text_anchor         = "text-anchor";
    inline constexpr Attr text_anchor_        = "text-anchor";
    inline constexpr Attr dominant_baseline   = "dominant-baseline";
    inline constexpr Attr dominant_baseline_  = "dominant-baseline";
    inline constexpr Attr alignment_baseline  = "alignment-baseline";
    inline constexpr Attr alignment_baseline_ = "alignment-baseline";
    inline constexpr Attr font_family         = "font-family";
    inline constexpr Attr font_family_        = "font-family";
    inline constexpr Attr font_size           = "font-size";
    inline constexpr Attr font_size_          = "font-size";
    inline constexpr Attr font_weight         = "font-weight";
    inline constexpr Attr font_weight_        = "font-weight";
    inline constexpr Attr font_style          = "font-style";
    inline constexpr Attr font_style_         = "font-style";
    inline constexpr Attr letter_spacing      = "letter-spacing";
    inline constexpr Attr letter_spacing_     = "letter-spacing";
    inline constexpr Attr word_spacing        = "word-spacing";
    inline constexpr Attr word_spacing_       = "word-spacing";
    inline constexpr Attr text_decoration     = "text-decoration";
    inline constexpr Attr text_decoration_    = "text-decoration";

    // Gradients and patterns

    inline constexpr Attr gradient_units         = "gradientUnits";
    inline constexpr Attr gradient_units_        = "gradientUnits";
    inline constexpr Attr gradient_transform     = "gradientTransform";
    inline constexpr Attr gradient_transform_    = "gradientTransform";
    inline constexpr Attr spread_method          = "spreadMethod";
    inline constexpr Attr spread_method_         = "spreadMethod";
    inline constexpr Attr offset                 = "offset";
    inline constexpr Attr offset_                = "offset";
    inline constexpr Attr stop_color             = "stop-color";
    inline constexpr Attr stop_color_            = "stop-color";
    inline constexpr Attr stop_opacity           = "stop-opacity";
    inline constexpr Attr stop_opacity_          = "stop-opacity";
    inline constexpr Attr pattern_units          = "patternUnits";
    inline constexpr Attr pattern_units_         = "patternUnits";
    inline constexpr Attr pattern_content_units  = "patternContentUnits";
    inline constexpr Attr pattern_content_units_ = "patternContentUnits";
    inline constexpr Attr pattern_transform      = "patternTransform";
    inline constexpr Attr pattern_transform_     = "patternTransform";

    // Clipping and masking

    inline constexpr Attr clip_path           = "clip-path";
    inline constexpr Attr clip_path_          = "clip-path";
    inline constexpr Attr clip_rule           = "clip-rule";
    inline constexpr Attr clip_rule_          = "clip-rule";
    inline constexpr Attr clipPathUnits       = "clipPathUnits";
    inline constexpr Attr clipPathUnits_      = "clipPathUnits";
    inline constexpr Attr mask_               = "mask";
    inline constexpr Attr mask_units          = "maskUnits";
    inline constexpr Attr mask_units_         = "maskUnits";
    inline constexpr Attr mask_content_units  = "maskContentUnits";
    inline constexpr Attr mask_content_units_ = "maskContentUnits";

    // Markers

    inline constexpr Attr marker_start  = "marker-start";
    inline constexpr Attr marker_start_ = "marker-start";
    inline constexpr Attr marker_mid    = "marker-mid";
    inline constexpr Attr marker_mid_   = "marker-mid";
    inline constexpr Attr marker_end    = "marker-end";
    inline constexpr Attr marker_end_   = "marker-end";

    // External resources and linking

    inline constexpr Attr href         = "href";
    inline constexpr Attr href_        = "href";
    inline constexpr Attr xlink_href   = "xlink:href";
    inline constexpr Attr xlink_href_  = "xlink:href";
    inline constexpr Attr xmlns        = "xmlns";
    inline constexpr Attr xmlns_       = "xmlns";
    inline constexpr Attr xmlns_xlink  = "xmlns:xlink";
    inline constexpr Attr xmlns_xlink_ = "xmlns:xlink";
    inline constexpr Attr crossorigin  = "crossorigin";
    inline constexpr Attr crossorigin_ = "crossorigin";

    // Animation

    inline constexpr Attr begin           = "begin";
    inline constexpr Attr begin_          = "begin";
    inline constexpr Attr dur             = "dur";
    inline constexpr Attr dur_            = "dur";
    inline constexpr Attr end             = "end";
    inline constexpr Attr end_            = "end";
    inline constexpr Attr repeat_count    = "repeatCount";
    inline constexpr Attr repeat_count_   = "repeatCount";
    inline constexpr Attr repeat_dur      = "repeatDur";
    inline constexpr Attr repeat_dur_     = "repeatDur";
    inline constexpr Attr attribute_name  = "attributeName";
    inline constexpr Attr attribute_name_ = "attributeName";
    inline constexpr Attr calc_mode       = "calcMode";
    inline constexpr Attr calc_mode_      = "calcMode";
    inline constexpr Attr key_times       = "keyTimes";
    inline constexpr Attr key_times_      = "keyTimes";
    inline constexpr Attr values          = "values";
    inline constexpr Attr values_         = "values";
    inline constexpr Attr from            = "from";
    inline constexpr Attr from_           = "from";
    inline constexpr Attr to              = "to";
    inline constexpr Attr to_             = "to";
    inline constexpr Attr by              = "by";
    inline constexpr Attr by_             = "by";
} // namespace mup::svg

#endif
