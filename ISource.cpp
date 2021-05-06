#include <iostream>
#include <iomanip>

#include "ISource.h"

const std::string ISource::SOURCETYPE = "Current Source";

// Operator Overloading
const ISource& ISource::operator=(const ISource& B)
{
    this->elementName = B.elementName;
    this->voltageAcross = B.voltageAcross;
    this->currentThrough = B.currentThrough;
    this->forcedCurrent = B.forcedCurrent;

    this->node1 = B.node1;
    this->node2 = B.node2;

    return *this;
}

// Copy Constructor
ISource::ISource(const ISource& B)
        :  Source(B.elementName, B.node1, B.node2, B.voltageAcross, B.currentThrough)
{
    this->forcedCurrent = B.forcedCurrent;

}

// ---------------------------------
// ---------- Constructor ----------
// ---------------------------------
ISource::ISource(Node n1, Node n2, std::complex<double> I)
        : forcedCurrent(I), Source(SOURCETYPE, n1, n2, 0, I)
{
    goodI = true;
}

// ----------------------------
// ---------- Getter ----------
// ----------------------------
std::complex<double> ISource::getForcedValue()
{
    return forcedCurrent;
}

// ----------------------------
// ---------- Setter ----------
// ----------------------------
void ISource::setCurrent(std::complex<double> newI)
{
    this->forcedCurrent = newI;
}

// ---------------------------
// ---------- Print ----------
// ---------------------------
void ISource::print()
{
    int barNum = 25;
    std::cout << std::fixed << std::setprecision(3);
    //std::cout << std::string(barNum, '-') << std::endl;
    std::cout << this->elementName << std::endl;
    std::cout << "  Magnitude -- " << std::abs(this->forcedCurrent) << " A" << std::endl;
    std::cout << "  Angle ------ " <<  std::arg(this->forcedCurrent) << " rad" << std::endl;
    std::cout << std::string(barNum, '-') << std::endl;
    std::cout.unsetf(std::ios_base::floatfield);
}