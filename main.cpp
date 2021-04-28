#include <iostream>
#include <string>
#include <complex>

#include "Node.h"
#include "Element.h"
#include "Source.h"
#include "VSource.h"
#include "ISource.h"
#include "Load.h"
#include "Resistor.h"
#include "Capacitor.h"
#include "Inductor.h"

using namespace std;

double OMEGA; // will give access global access for elements when calculating impedance


int main() {
    cout << "Omega = ";
    cin >> OMEGA;

    complex<double> complexV (10.0,2.0);
    complex<double> complexI (5.0,1.0); // see if can input mag and angle, sqrt(x^2 +y^2) arctan(y/x)???
    complex<double> complexZ (100.0,-8.0);

    Node A("A");
    Node B("B");


    Load Z = Load("Generic Load", A, B, complexV, complexI, complexZ);

    Z.print();

    Resistor R = Resistor(A,B,20);
    R.print();
    cout << R.getImpedance() << endl; // Better formatting

    Capacitor C = Capacitor(A,B,4);
    C.print();
    cout << C.getImpedance() << endl;

    Inductor L = Inductor(A,B,9);
    L.print();
    cout << L.getImpedance() << endl;

    Source* source;
    //auto dwnCstSource;
    int voltage;
    cin >> voltage;

    if (voltage == 1)
    {
        source = new VSource(A, B, complexV);


    }
    else if (voltage == 0)
    {
        source = new ISource(A, B, complexI);
    }



    source->print();


    //source = new VSource(A, B, complexV);
    auto dwnCstSource = dynamic_cast<VSource*>(source);
    dwnCstSource->setVoltage(5);

    //i.print();

    //cout << i.getNode1Name() << " -> " << i.getNode2Name() << endl; // new function? printNodeConnections()

    delete source;

    return 0;
}

