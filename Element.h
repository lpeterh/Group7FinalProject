#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include <complex>

#include "Node.h"

class Element
{
public:
    // Constructor
    Element(std::string EName, Node n1, Node n2, std::complex<double> V, std::complex<double> I);

    // Getters
    std::string getElementName();

    std::string getNode1Name();
    std::string getNode2Name();

    std::complex<double> getVoltageAcross();
    std::complex<double> getCurrentThrough();


    // Setters
    void setElementName(std::string newElementName);

    void setNode1Name(std::string newNode1Name);
    void setNode2Name(std::string newNode2Name);

    void setVoltageAcross(std::complex<double> newV);
    void setCurrentThrough(std::complex<double> newI);

    // Purely virtual print function to be defined later
    virtual void print() = 0;

protected:
    std::string elementName;

    Node node1;
    Node node2;

    std::complex<double> voltageAcross;
    std::complex<double> currentThrough;

};


#endif
