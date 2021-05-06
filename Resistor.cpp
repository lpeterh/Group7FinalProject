#include "Resistor.h"

#include <iostream>
#include <iomanip>
#include <complex>

// Operator Overloading
const Resistor& Resistor::operator=(const Resistor& B)
{
    this->resistance = B.resistance;
    this->elementName = B.elementName;
    this->voltageAcross = B.voltageAcross;
    this->currentThrough = B.currentThrough;

    this->node1 = B.node1;
    this->node2 = B.node2;

    std::complex<double> ZR ((this->resistance),0);
    this->setImpedance(ZR);

    return *this;
}

// Copy Constructor
Resistor::Resistor(const Resistor& B)
        :  Load(B.elementName, B.node1, B.node2, B.voltageAcross, B.currentThrough)
{
    this->resistance = B.resistance;

    std::complex<double> ZR ((this->resistance),0);

    this->setImpedance(ZR);
}


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