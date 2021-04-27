#include "Load.h"

// Constructor
Load::Load(std::string name, Node n1, Node n2, std::complex<double> V, std::complex<double> I, std::complex<double> z)
: impedance(z), Element(name, n1, n2, V, I)
{ }

// Setter
void Load::setImpedance(std::complex<double> newZ)
{
    this->impedance = newZ;
}
