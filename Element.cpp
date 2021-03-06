#include "Element.h"

// ---------------------------------
// ---------- Constructor ----------
// ---------------------------------
Element::Element(std::string EName, Node n1, Node n2, std::complex<double> V, std::complex<double> I)
    : elementName(EName), node1(n1), node2(n2), voltageAcross(V), currentThrough(I)
{
    nodes[0] = this->getNode1Name();
    nodes[1] = this->getNode2Name();
}

// -----------------------------
// ---------- Getters ----------
// -----------------------------
std::string Element::getElementName()
{
    return elementName;
}

std::string Element::getNode1Name()
{
    return (node1.getName());
}
std::string Element::getNode2Name()
{
    return (node2.getName());
}

std::string* Element::getNodes()
{
    return nodes;
}

std::complex<double> Element::getVoltageAcross()
{
    return voltageAcross;
}

std::complex<double> Element::getCurrentThrough()
{
    return currentThrough;
}

bool Element::isVGood()
{
    return goodV;
}
bool Element::isIGood()
{
    return goodI;
}

// -----------------------------
// ---------- Setters ----------
// -----------------------------
void Element::setElementName(std::string newElementName)
{
    (this->elementName) = newElementName;
}

void Element::setNode1Name(std::string newNode1Name)
{
    (this->node1).setName(newNode1Name);
}

void Element::setNode2Name(std::string newNode2Name)
{
    (this->node2).setName(newNode2Name);
}

void Element::setVoltageAcross(std::complex<double> newV)
{
    (this->voltageAcross) = newV;
}

void Element::setCurrentThrough(std::complex<double> newI)
{
    (this->currentThrough) = newI;
}

void Element::setVGood(bool check)
{
    (this->goodV) = check;
}
void Element::setIGood(bool check)
{
    (this->goodI) = check;
}