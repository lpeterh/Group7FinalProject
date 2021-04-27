#include <iostream>
#include <string>
#include <complex>

#include "Node.h"
#include "Element.h"
#include "Source.h"
#include "VSource.h"
#include "ISource.h"

using namespace std;

int main() {

    complex<double> complexV (10.0,2.0);
    complex<double> complexI (5.0,1.0); // see if can input mag and angle

    Node A = Node("A");
    Node B = Node("B");

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
