#include <iostream>
#include <memory>
#include <string>
#include <complex>
#include <Map>
#include <List>
#include <Memory>

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

double OMEGA = 1; // will give access global access for elements when calculating impedance


int main() {

    complex<double> complexV (10.0,2.0);
    complex<double> complexI (5.0,1.0); // see if can input mag and angle, sqrt(x^2 +y^2) arctan(y/x)???
    complex<double> complexZ (100.0,-8.0);

    //Node A("A");
    //Node B("B");
    //Node C("C");
    //Node GND("GND");

    //Load* Z = new Load("Generic Load", A, B, complexV, complexI, complexZ);
    //Z.print();

    //Resistor res = Resistor(B,GND,20);
    //R.print();
    //cout << R.getImpedance() << endl; // Better formatting

    //Capacitor cap = Capacitor(C,GND,4);
    //C.print();
    //cout << C.getImpedance() << endl;

    //Inductor ind = Inductor(B,C,9);
    //L.print();
    //cout << L.getImpedance() << endl;

    //Source* source;
    //source = new VSource(A, GND, complexV);
    //source->print();
    //auto dwnCstSource = dynamic_cast<VSource*>(source);
    //dwnCstSource->setVoltage(5);

    unsigned nodeNum = 0;
    unsigned resNum = 0;
    unsigned capNum = 0;
    unsigned indNum = 0;

    cout << "Enter Number of Nodes:";
    cin >> nodeNum;
    cout << "Enter Number of Resistors:";
    cin >> resNum;
    cout << "Enter Number of Capacitors:";
    cin >> capNum;
    cout << "Enter Number of Inductors:";
    cin >> indNum;

    // Used for deletion
    unsigned nodeNum_copy = 0;
    unsigned resNum_copy =  0;
    unsigned capNum_copy =  0;
    unsigned indNum_copy =  0;

    list<unique_ptr<Node>> nodeList;
    list<unique_ptr<Resistor>> resList;
    list<unique_ptr<Capacitor>> capList;
    list<unique_ptr<Inductor>> indList;

    string nodeName;
    while( nodeNum_copy < nodeNum)
    {
        cout << "Enter Node name:";
        cin >> nodeName;
        //nodeList.push_back(new Node(nodeName));
        nodeList.push_back( make_unique<Node>(nodeName) );
        nodeNum_copy++;
    }

    auto nodeListItr = nodeList.begin();

    double resistance = 0;
    double capacitance = 0;
    double inductance = 0;

    string node1Name;
    string node2Name;

    Node node1(" ");
    Node node2(" ");


    while(resNum_copy < resNum)
    {
        node1.setName(" "); // Reset the names to ensure they aren't carried over
        node2.setName(" ");

        cout << "Enter Resistance:";
        cin >> resistance;

        cout << "Enter First Nodes Name:";
        cin >> node1Name;

        cout << "Enter Second Nodes Name:";
        cin >> node2Name;

        for( nodeListItr = nodeList.begin() ;nodeListItr != nodeList.end(); nodeListItr++) // get the node for node 1 repeat for node 2
        {
            if (node1Name == (*nodeListItr)->getName() )
            {
                node1.setName(node1Name);
            }
            if (node2Name == (*nodeListItr)->getName() )
            {
                node2.setName(node2Name);
            }
        }
        if ( (node1.getName() == " ") || (node2.getName() == " ") ) // separate to say what node name failed
        {
            cout << "Node name not recognized";
            return -5;
        }

        resList.push_back( make_unique<Resistor>(node1, node2, resistance)); // Resistor res = Resistor(N1,N2,R);
        resNum_copy++;
    }



    while(capNum_copy < capNum)
    {
        node1.setName(" "); // Reset the names to ensure they aren't carried over
        node2.setName(" ");

        cout << "Enter Capacitance:";
        cin >> capacitance;

        cout << "Enter First Nodes Name:";
        cin >> node1Name;

        cout << "Enter Second Nodes Name:";
        cin >> node2Name;

        for( nodeListItr = nodeList.begin() ; nodeListItr != nodeList.end(); nodeListItr++) // get the node for node 1 and node 2
        {
            if (node1Name == (*nodeListItr)->getName() )
            {
                node1.setName(node1Name);
            }
            if (node2Name == (*nodeListItr)->getName() )
            {
                node2.setName(node2Name);
            }
        }
        if ( (node1.getName() == " ") || (node2.getName() == " ") ) // separate to say what node name failed
        {
            cout << "Node name not recognized";
            return -5;
        }

        capList.push_back(make_unique<Capacitor>(node1, node2, capacitance)); // Capacitor c = Capacitor( n1, n2, c)
        capNum_copy++;
    }



    while( indNum_copy < indNum)
    {
        node1.setName(" "); // Reset the names to ensure they aren't carried over
        node2.setName(" ");

        cout << "Enter Inductance:";
        cin >> inductance;

        cout << "Enter First Nodes Name:";
        cin >> node1Name;
        node1.setName(node1Name);

        cout << "Enter Second Nodes Name:";
        cin >> node2Name;
        node2.setName(node2Name);

        for( nodeListItr = nodeList.begin(); nodeListItr != nodeList.end(); nodeListItr++) // get the node for node 1 repeat for node 2
        {
            if (node1Name == (*nodeListItr)->getName() )
            {
                node1.setName(node1Name);
            }
            if (node2Name == (*nodeListItr)->getName() )
            {
                node2.setName(node2Name);
            }
        }
        if ( (node1.getName() == " ") || (node2.getName() == " ") ) // separate to say what node name failed
        {
            cout << "Node name not recognized";
            return -5;
        }

        indList.push_back( make_unique<Inductor>(node1, node2, inductance)); // Resistor res = Resistor(N1,N2,R);
        indNum_copy++;
    }


    multimap< string*, Load > loadMap;

    auto resListItr = resList.begin();
    auto capListItr = capList.begin();
    auto indListItr = indList.begin();

    for (resListItr = resList.begin(); resListItr != resList.end(); resListItr++)
    {
        loadMap.insert( pair( (*resListItr)->getNodes(), *(*resListItr)  ) );

        //loadMap.insert(pair((*resListItr)->getNodes(), *resListItr));
    }

    for( capListItr = capList.begin(); capListItr != capList.end() ; capListItr++)
    {
        loadMap.insert(pair( (*capListItr)->getNodes() , *(*capListItr)) );
    }

    for( indListItr = indList.begin(); indListItr != indList.end() ; indListItr++)
    {
        loadMap.insert(pair( (*indListItr)->getNodes() , *(*indListItr)));
    }

    for (auto loadItr = loadMap.begin(); loadItr != loadMap.end(); loadItr++ )
    {
        cout << (*(loadItr->first))[0];
        cout << " : ";
        cout << *(loadItr->first + 1);
        cout << " : ";
        cout << (loadItr->second).getElementName();
        cout << " : ";
        cout << (loadItr->second).getImpedance();
        cout << endl;
        cout << "-----------------------"<< endl;
    }

    resListItr = resList.begin();
    auto loadItr = loadMap.begin();

    loadItr = loadMap.find( (*resListItr)->getNodes() );

    Load* rPtr = &(loadItr->second);

    auto dwnCast = dynamic_cast<Resistor*>(rPtr);
    dwnCast->getResistance();

    /*
    cout << "Omega =  ";
    cin >> OMEGA;

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

    //source = new VSource(A, B, complexV);
    //i.print();

    //cout << i.getNode1Name() << " -> " << i.getNode2Name() << endl; // new function? printNodeConnections()


    */
    //delete Z;
    //delete source;


    return 0;
}

