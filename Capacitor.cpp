#include "Capacitor.h"

#include <iostream>
#include <iomanip>
#include <complex>

// Operator Overloading
const Capacitor& Capacitor::operator=(const Capacitor& B)
{
    this->capacitance = B.capacitance;
    this->elementName = B.elementName;
    this->voltageAcross = B.voltageAcross;
    this->currentThrough = B.currentThrough;

    this->node1 = B.node1;
    this->node2 = B.node2;

    std::complex<double> ZR (0,-(1/ (this->capacitance * OMEGA)));
    this->setImpedance(ZR);

    return *this;
}

// Copy Constructor
Capacitor::Capacitor(const Capacitor& B)
        :  Load(B.elementName, B.node1, B.node2, B.voltageAcross, B.currentThrough)
{
    this->capacitance = B.capacitance;

    std::complex<double> ZR (0,-(1/ (this->capacitance * OMEGA)));

    this->setImpedance(ZR);
}

Capacitor::Capacitor(Node n1, Node n2, double c)
        : capacitance(c), Load("Capacitor", n1,n2, 0, 0)
{
    std::complex<double> ZR (0,-(1/ (c * OMEGA)));

    this->setImpedance(ZR);
}

// Getter
double Capacitor::getCapacitance()
{
    return capacitance;
}

// Setter
void Capacitor::setCapacitance(double newC)
{
    (this->capacitance) = newC;
}

// Print
void Capacitor::print()
{
    int barNum = 25;
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::string(barNum, '-') << std::endl;
    std::cout << this->elementName << std::endl;
    std::cout << "  Capacitance -- " << std::real(this->capacitance) << " FARADS" << std::endl;
    std::cout << std::string(barNum, '-') << std::endl;
    std::cout.unsetf(std::ios_base::floatfield);
}