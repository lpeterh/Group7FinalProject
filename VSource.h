#ifndef VSOURCE_H
#define VSOURCE_H

#include <string>
#include <complex>

#include "Source.h"

class VSource : public Source
{
public:
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
