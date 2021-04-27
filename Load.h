#ifndef LOAD_H
#define LOAD_H

#include "Element.h"

class Load : public Element
{
public:
    // Constructor
    Load(std::string name, Node n1, Node n2, std::complex<double> V, std::complex<double> I, std::complex<double> z);

    // Getter
    virtual std::complex<double> getImpedance();

    // Setter
    void setImpedance(std::complex<double> newZ);

    virtual void print();


private:
    std::complex<double> impedance;

};

#endif
