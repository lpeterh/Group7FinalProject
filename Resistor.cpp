#include "Resistor.h"

#include <iostream>
#include <iomanip>
#include <complex>

// Constructor
Resistor::Resistor(Node n1, Node n2, double r)
    : resistance(r), Load("Resistor", n1,n2, 0, 0)
{
    std::complex<double> ZR (r,0);

    this->setImpedance(ZR);
}

// Getter
double Resistor::getResistance()
{
    return resistance;
}

// Setter
void Resistor::setResistance(double newR)
{
    (this->resistance) = newR;
}

// Print
void Resistor::print()
{
    int barNum = 25;
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::string(barNum, '-') << std::endl;
    std::cout << this->elementName << std::endl;
    std::cout << "  Resistance -- " << std::real(this->resistance) << " OHMS" << std::endl;
    std::cout << std::string(barNum, '-') << std::endl;
    std::cout.unsetf(std::ios_base::floatfield);
}