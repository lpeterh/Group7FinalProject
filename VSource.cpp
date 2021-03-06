#include <iostream>
#include <iomanip>

#include "VSource.h"

const std::string VSource::SOURCETYPE = "Voltage Source";

// Operator Overloading
const VSource& VSource::operator=(const VSource& B)
{
    this->elementName = B.elementName;
    this->voltageAcross = B.voltageAcross;
    this->currentThrough = B.currentThrough;
    this->forcedVoltage = B.forcedVoltage;

    this->node1 = B.node1;
    this->node2 = B.node2;

    return *this;
}

// Copy Constructor
VSource::VSource(const VSource& B)
        :  Source(B.elementName, B.node1, B.node2, B.voltageAcross, B.currentThrough)
{
    this->forcedVoltage = B.forcedVoltage;

}


// ---------------------------------
// ---------- Constructor ----------
// ---------------------------------
VSource::VSource(Node n1, Node n2, std::complex<double> V)
    : forcedVoltage(V), Source(SOURCETYPE, n1, n2, V, 0)
{
    goodV = true;
}

// ----------------------------
// ---------- Getter ----------
// ----------------------------
std::complex<double> VSource::getForcedValue()
{
    return forcedVoltage;
}

// ----------------------------
// ---------- Setter ----------
// ----------------------------
void VSource::setVoltage(std::complex<double> newV)
{
    this->forcedVoltage = newV;
}

// ---------------------------
// ---------- Print ----------
// ---------------------------
void VSource::print()
{
    int barNum = 25;
    std::cout << std::fixed << std::setprecision(3);
    //std::cout << std::string(barNum, '-') << std::endl;
    std::cout << this->elementName << std::endl;
    std::cout << "  Magnitude -- " << std::abs(this->forcedVoltage) << " V" << std::endl;
    std::cout << "  Angle ------ " <<  std::arg(this->forcedVoltage) << " rad" << std::endl;
    std::cout << std::string(barNum, '-') << std::endl;
    std::cout.unsetf(std::ios_base::floatfield);
}

