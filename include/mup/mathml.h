#ifndef MUP_MATHML_H
#define MUP_MATHML_H

#include <mup/mup.h>

namespace mup::mathml {

    // Presentation MathML elements
    template <Attr... attr>
    using math = Element<true, "math", attr...>;

    template <Attr... attr>
    using maction = Element<true, "maction", attr...>;

    template <Attr... attr>
    using menclose = Element<true, "menclose", attr...>;

    template <Attr... attr>
    using merror = Element<true, "merror", attr...>;

    template <Attr... attr>
    using mfenced = Element<true, "mfenced", attr...>;

    template <Attr... attr>
    using mfrac = Element<true, "mfrac", attr...>;

    template <Attr... attr>
    using mi = Element<true, "mi", attr...>;

    template <Attr... attr>
    using mmultiscripts = Element<true, "mmultiscripts", attr...>;

    template <Attr... attr>
    using mn = Element<true, "mn", attr...>;

    template <Attr... attr>
    using mo = Element<true, "mo", attr...>;

    template <Attr... attr>
    using mover = Element<true, "mover", attr...>;

    template <Attr... attr>
    using mpadded = Element<true, "mpadded", attr...>;

    template <Attr... attr>
    using mphantom = Element<true, "mphantom", attr...>;

    template <Attr... attr>
    using mprescripts = Element<true, "mprescripts", attr...>;

    template <Attr... attr>
    using mroot = Element<true, "mroot", attr...>;

    template <Attr... attr>
    using mrow = Element<true, "mrow", attr...>;

    template <Attr... attr>
    using ms = Element<true, "ms", attr...>;

    template <Attr... attr>
    using mspace = Element<true, "mspace", attr...>;

    template <Attr... attr>
    using msqrt = Element<true, "msqrt", attr...>;

    template <Attr... attr>
    using mstyle = Element<true, "mstyle", attr...>;

    template <Attr... attr>
    using msub = Element<true, "msub", attr...>;

    template <Attr... attr>
    using msubsup = Element<true, "msubsup", attr...>;

    template <Attr... attr>
    using msup = Element<true, "msup", attr...>;

    template <Attr... attr>
    using mtable = Element<true, "mtable", attr...>;

    template <Attr... attr>
    using mtd = Element<true, "mtd", attr...>;

    template <Attr... attr>
    using mtext = Element<true, "mtext", attr...>;

    template <Attr... attr>
    using mtr = Element<true, "mtr", attr...>;

    template <Attr... attr>
    using munder = Element<true, "munder", attr...>;

    template <Attr... attr>
    using munderover = Element<true, "munderover", attr...>;

    template <Attr... attr>
    using semantics = Element<true, "semantics", attr...>;

    // Content MathML elements
    template <Attr... attr>
    using annotation = Element<true, "annotation", attr...>;

    template <Attr... attr>
    using annotation_xml = Element<true, "annotation-xml", attr...>;

    template <Attr... attr>
    using apply = Element<true, "apply", attr...>;

    template <Attr... attr>
    using bind = Element<true, "bind", attr...>;

    template <Attr... attr>
    using bvar = Element<true, "bvar", attr...>;

    template <Attr... attr>
    using ci = Element<true, "ci", attr...>;

    template <Attr... attr>
    using cn = Element<true, "cn", attr...>;

    template <Attr... attr>
    using cs = Element<true, "cs", attr...>;

    template <Attr... attr>
    using csymbol = Element<true, "csymbol", attr...>;

    template <Attr... attr>
    using cerror = Element<true, "cerror", attr...>;

    template <Attr... attr>
    using cbytes = Element<true, "cbytes", attr...>;

    template <Attr... attr>
    using cdbase = Element<true, "cdbase", attr...>;

    template <Attr... attr>
    using cinterval = Element<true, "interval", attr...>;

    template <Attr... attr>
    using condition = Element<true, "condition", attr...>;

    template <Attr... attr>
    using declare = Element<true, "declare", attr...>;

    template <Attr... attr>
    using degree = Element<true, "degree", attr...>;

    template <Attr... attr>
    using domainofapplication = Element<true, "domainofapplication", attr...>;

    template <Attr... attr>
    using interval = Element<true, "interval", attr...>;

    template <Attr... attr>
    using lambda = Element<true, "lambda", attr...>;

    template <Attr... attr>
    using logbase = Element<true, "logbase", attr...>;

    template <Attr... attr>
    using momentabout = Element<true, "momentabout", attr...>;

    template <Attr... attr>
    using lowlimit = Element<true, "lowlimit", attr...>;

    template <Attr... attr>
    using uplimit = Element<true, "uplimit", attr...>;

    template <Attr... attr>
    using piece = Element<true, "piece", attr...>;

    template <Attr... attr>
    using piecewise = Element<true, "piecewise", attr...>;

    template <Attr... attr>
    using otherwise = Element<true, "otherwise", attr...>;

    template <Attr... attr>
    using quotient = Element<true, "quotient", attr...>;

    template <Attr... attr>
    using remainder = Element<true, "rem", attr...>;

    template <Attr... attr>
    using set = Element<true, "set", attr...>;

    template <Attr... attr>
    using list = Element<true, "list", attr...>;

    template <Attr... attr>
    using matrix = Element<true, "matrix", attr...>;

    template <Attr... attr>
    using matrixrow = Element<true, "matrixrow", attr...>;

    template <Attr... attr>
    using vector = Element<true, "vector", attr...>;

    template <Attr... attr>
    using scalar = Element<true, "scalar", attr...>;

    template <Attr... attr>
    using interval_ = Element<true, "interval", attr...>;

    template <Attr... attr>
    using sep = Element<true, "sep", attr...>;

    template <Attr... attr>
    using fn = Element<true, "fn", attr...>;

    template <Attr... attr>
    using ident = Element<true, "ident", attr...>;

    template <Attr... attr>
    using domain = Element<true, "domain", attr...>;

    template <Attr... attr>
    using codomain = Element<true, "codomain", attr...>;

    template <Attr... attr>
    using image = Element<true, "image", attr...>;

    template <Attr... attr>
    using inverse = Element<true, "inverse", attr...>;

    template <Attr... attr>
    using compose = Element<true, "compose", attr...>;

    template <Attr... attr>
    using tendsto = Element<true, "tendsto", attr...>;

    template <Attr... attr>
    using diff = Element<true, "diff", attr...>;

    template <Attr... attr>
    using partialdiff = Element<true, "partialdiff", attr...>;

    template <Attr... attr>
    using int_ = Element<true, "int", attr...>;

    template <Attr... attr>
    using sum = Element<true, "sum", attr...>;

    template <Attr... attr>
    using product = Element<true, "product", attr...>;

    template <Attr... attr>
    using limit = Element<true, "limit", attr...>;

    template <Attr... attr>
    using forall = Element<true, "forall", attr...>;

    template <Attr... attr>
    using exists = Element<true, "exists", attr...>;

    template <Attr... attr>
    using notexists = Element<true, "notexists", attr...>;

    template <Attr... attr>
    using and_ = Element<true, "and", attr...>;

    template <Attr... attr>
    using or_ = Element<true, "or", attr...>;

    template <Attr... attr>
    using xor_ = Element<true, "xor", attr...>;

    template <Attr... attr>
    using not_ = Element<true, "not", attr...>;

    template <Attr... attr>
    using implies = Element<true, "implies", attr...>;

    template <Attr... attr>
    using equivalent = Element<true, "equivalent", attr...>;

    template <Attr... attr>
    using approx = Element<true, "approx", attr...>;

    template <Attr... attr>
    using eq = Element<true, "eq", attr...>;

    template <Attr... attr>
    using neq = Element<true, "neq", attr...>;

    template <Attr... attr>
    using gt = Element<true, "gt", attr...>;

    template <Attr... attr>
    using lt = Element<true, "lt", attr...>;

    template <Attr... attr>
    using geq = Element<true, "geq", attr...>;

    template <Attr... attr>
    using leq = Element<true, "leq", attr...>;

    template <Attr... attr>
    using plus = Element<true, "plus", attr...>;

    template <Attr... attr>
    using minus = Element<true, "minus", attr...>;

    template <Attr... attr>
    using times = Element<true, "times", attr...>;

    template <Attr... attr>
    using divide = Element<true, "divide", attr...>;

    template <Attr... attr>
    using power = Element<true, "power", attr...>;

    template <Attr... attr>
    using root = Element<true, "root", attr...>;

    template <Attr... attr>
    using abs = Element<true, "abs", attr...>;

    template <Attr... attr>
    using floor = Element<true, "floor", attr...>;

    template <Attr... attr>
    using ceiling = Element<true, "ceiling", attr...>;

    template <Attr... attr>
    using factorial = Element<true, "factorial", attr...>;

    template <Attr... attr>
    using min = Element<true, "min", attr...>;

    template <Attr... attr>
    using max = Element<true, "max", attr...>;

    template <Attr... attr>
    using real = Element<true, "real", attr...>;

    template <Attr... attr>
    using imaginary = Element<true, "imaginary", attr...>;

    template <Attr... attr>
    using conjugate = Element<true, "conjugate", attr...>;

    template <Attr... attr>
    using arg = Element<true, "arg", attr...>;

    template <Attr... attr>
    using sin = Element<true, "sin", attr...>;

    template <Attr... attr>
    using cos = Element<true, "cos", attr...>;

    template <Attr... attr>
    using tan = Element<true, "tan", attr...>;

    template <Attr... attr>
    using sinh = Element<true, "sinh", attr...>;

    template <Attr... attr>
    using cosh = Element<true, "cosh", attr...>;

    template <Attr... attr>
    using tanh = Element<true, "tanh", attr...>;

    template <Attr... attr>
    using arcsin = Element<true, "arcsin", attr...>;

    template <Attr... attr>
    using arccos = Element<true, "arccos", attr...>;

    template <Attr... attr>
    using arctan = Element<true, "arctan", attr...>;

    template <Attr... attr>
    using exp = Element<true, "exp", attr...>;

    template <Attr... attr>
    using ln = Element<true, "ln", attr...>;

    template <Attr... attr>
    using log = Element<true, "log", attr...>;

    template <Attr... attr>
    using gcd = Element<true, "gcd", attr...>;

    template <Attr... attr>
    using lcm = Element<true, "lcm", attr...>;

    template <Attr... attr>
    using mean = Element<true, "mean", attr...>;

    template <Attr... attr>
    using median = Element<true, "median", attr...>;

    template <Attr... attr>
    using mode = Element<true, "mode", attr...>;

    template <Attr... attr>
    using variance = Element<true, "variance", attr...>;

    template <Attr... attr>
    using sdev = Element<true, "sdev", attr...>;

} // namespace mup::mathml

#endif
