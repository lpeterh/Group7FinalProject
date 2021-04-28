#ifndef LOAD_H
#define LOAD_H

#include <string>
#include <complex>

#include "Element.h"

class Load : public Element
{
public:
    // Constructor, note the z=0 will default it to 0 if z is not provided
    Load(std::string name, Node n1, Node n2, std::complex<double> v, std::complex<double> i, std::complex<double> z = 0);

    // Getter
    virtual std::complex<double> getImpedance();

    // Setter
    void setImpedance(std::complex<double> newZ);

    virtual void print();

    //
    ~Load(); // Apparently needed else "undefined reference to 'vtable Load" // https://stackoverflow.com/questions/3065154/undefined-reference-to-vtable


private:
    std::complex<double> impedance;

};

#endif
