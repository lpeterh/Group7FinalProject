#ifndef RESISTOR_H
#define RESISTOR_H

#include "Load.h"

class Resistor : public Load
{
public:
    // Operator Overloading
    const Resistor& operator=(const Resistor& B);

    // Copy Constructor
    Resistor(const Resistor& B);

    // Constructor
    Resistor(Node n1, Node n2, double r);

    // Getter
    double getResistance();

    // Setter
    void setResistance(double newR);

    // Print
    void print();


private:
    double resistance;


};




#endif
