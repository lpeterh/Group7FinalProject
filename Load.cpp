#include "Load.h"
#include "Node.h"
#include <iostream>
#include <iomanip>


// Operator Overloading
const Load& Load::operator=(const Load& B)
{
    this->impedance = B.impedance;
    this->elementName = B.elementName;
    this->voltageAcross = B.voltageAcross;
    this->currentThrough = B.currentThrough;

    this->node1 = B.node1;
    this->node2 = B.node2;

    return *this;
}

// Copy Constructor
Load::Load(const Load& B)
    :  Element(B.elementName, B.node1, B.node2, B.voltageAcross, B.currentThrough)
{
    this->impedance = B.impedance;
}

Load operator+(const Load& A, const Load& B)
{
    std::complex<double> ZResult;
    ZResult = A.impedance + B.impedance;
    Load result("SeriesLoad", Node("1"), Node("2"), 0, 0, ZResult);

    return result;

}

Load operator||(const Load& A, const Load& B)
{
    std::complex<double> ZResult;
    ZResult = (1.00/(((1.00)/(A.impedance)) + ((1.00)/(B.impedance))));
    Load result("SeriesLoad", Node("1"), Node("2"), 0, 0, ZResult);

    return result;

}




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