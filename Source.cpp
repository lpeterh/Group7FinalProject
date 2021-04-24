#include "Source.h"


// ---------------------------------
// ---------- Constructor ----------
// ---------------------------------
Source::Source(std::string name, Node n1, Node n2, std::complex<double> v, std::complex<double> i)
    : Element(name, n1, n2, v, i)
{ }