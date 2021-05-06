#ifndef VSOURCE_H
#define VSOURCE_H

#include <string>
#include <complex>

#include "Source.h"

class VSource : public Source
{
public:
    // Operator Overloading
    const VSource& operator=(const VSource& B);

    // Copy Constructor
    VSource(const VSource& B);

    // Constructor
    VSource(Node n1, Node n2, std::complex<double> V);

    // Getter
    std::complex<double> getForcedValue();

    // Setter
    void setVoltage(std::complex<double> newV);

    // Print
    void print();


private:
    static const std::string SOURCETYPE;

    std::complex<double> forcedVoltage;



};


#endif
