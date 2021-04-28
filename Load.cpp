#include "Load.h"

#include <iostream>
#include <iomanip>

// Constructor
Load::Load(std::string name, Node n1, Node n2, std::complex<double> v, std::complex<double> i, std::complex<double> z)
    : impedance(z), Element(name, n1, n2, v, i)
{ }

// Getter
std::complex<double> Load::getImpedance()
{
    return impedance;
}

// Setter
void Load::setImpedance(std::complex<double> newZ)
{
    this->impedance = newZ;
}

void Load::print()
{
    int barNum = 25;
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::string(barNum, '-') << std::endl;
    std::cout << this->elementName << std::endl;
    std::cout << "  Real Part -- " << std::real(this->impedance) << std::endl;
    std::cout << "  Imag Part -- " <<  std::imag(this->impedance) << std::endl;
    std::cout << std::string(barNum, '-') << std::endl;
    std::cout.unsetf(std::ios_base::floatfield);
}

Load::~Load()
{ }