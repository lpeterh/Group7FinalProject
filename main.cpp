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
    complex<double> complexI (5.0,1.0);

    Node A = Node("A");
    Node B = Node("B");

    VSource v = VSource(A, B, complexV);

    ISource i = ISource(A, B, complexI);

    v.print();

    i.print();

    cout << i.getNode1Name() << " -> " << i.getNode2Name() << endl; // new function? printNodeConnections()

    return 0;
}
