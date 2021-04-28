#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "Load.h"

class Capacitor : public Load
{
public:
    // Constructor
    Capacitor(Node n1, Node n2, double c);

    // Getter
    double getCapacitance();

    // Setter
    void setCapacitance(double newC);

    // Print
    void print();


private:
    double capacitance;

};

#endif
