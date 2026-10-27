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

} // namespace mup::svg

#endif
