#ifndef ISOURCE_H
#define ISOURCE_H

#include <string>
#include <complex>

#include "Source.h"

class ISource : public Source
{
public:
    // Operator Overloading
    const ISource& operator=(const ISource& B);

    // Copy Constructor
    ISource(const ISource& B);

    // Constructor
    ISource(Node n1, Node n2, std::complex<double> I);

    // Getter
    std::complex<double> getForcedValue();

    // Setter
    void setCurrent(std::complex<double> newI);

    // Print
    void print();


private:
    std::complex<double> forcedCurrent;

    static const std::string SOURCETYPE;


};

#endif
