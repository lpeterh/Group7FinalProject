#ifndef SOURCE_H
#define SOURCE_H

#include <string>
#include <complex>

#include "Element.h"

class Source : public Element
{
public:
    // Constructor
    Source(std::string name, Node n1, Node n2, std::complex<double> V, std::complex<double> I);

    // Purely virtual functions to be defined later
    virtual std::complex<double> getForcedValue() = 0;

    virtual void print() = 0;

};


#endif
