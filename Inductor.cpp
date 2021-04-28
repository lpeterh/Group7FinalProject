#include "Inductor.h"

#include <iostream>
#include <iomanip>
#include <complex>

Inductor::Inductor(Node n1, Node n2, double l)
        : inductance(l), Load("Inductor", n1,n2, 0, 0)
{
    std::complex<double> ZR (0, (l * OMEGA));

    this->setImpedance(ZR);
}

// Getter
double Inductor::getInductance() {
    return inductance;
}

// Setter
void Inductor::setInductance(double newL)
{
    (this->inductance) = newL;
}

// Print
void Inductor::print()
{
    int barNum = 25;
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::string(barNum, '-') << std::endl;
    std::cout << this->elementName << std::endl;
    std::cout << "  Inductance -- " << std::real(this->inductance) << " HENRYS" << std::endl;
    std::cout << std::string(barNum, '-') << std::endl;
    std::cout.unsetf(std::ios_base::floatfield);
}