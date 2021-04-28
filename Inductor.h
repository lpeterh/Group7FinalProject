#ifndef INDUCTOR_H
#define INDUCTOR_H

#include "Load.h"

class Inductor : public Load
{
public:
    // Constructor
    Inductor(Node n1, Node n2, double l);

    // Getter
    double getInductance();

    // Setter
    void setInductance(double newL);

    // Print
    void print();


private:
    double inductance;

};

#endif
