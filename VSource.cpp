#include <iostream>
#include <iomanip>

#include "VSource.h"

const std::string VSource::SOURCETYPE = "Voltage Source";

// ---------------------------------
// ---------- Constructor ----------
// ---------------------------------
VSource::VSource(Node n1, Node n2, std::complex<double> V)
    : forcedVoltage(V), Source(SOURCETYPE, n1, n2, V, 0)
{ }

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
    std::cout << std::string(barNum, '-') << std::endl;
    std::cout << this->elementName << std::endl;
    std::cout << "  Magnitude -- " << std::abs(this->forcedVoltage) << " V" << std::endl;
    std::cout << "  Angle ------ " <<  std::arg(this->forcedVoltage) << " rad" << std::endl;
    std::cout << std::string(barNum, '-') << std::endl;
    std::cout << std::fixed << std::setprecision(3);
    std::cout.unsetf(std::ios_base::floatfield);
}

