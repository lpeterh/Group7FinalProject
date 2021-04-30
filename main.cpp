#include <iostream>
#include <memory>
#include <string>
#include <complex>
#include <map>
#include <list>
#include <memory>

#include "Node.h"
#include "Element.h"
#include "Source.h"
#include "VSource.h"
#include "ISource.h"
#include "Load.h"
#include "Resistor.h"
#include "Capacitor.h"
#include "Inductor.h"

#include "helperFunctions.h"


using namespace std;

double OMEGA = 1; // will give access global access for elements when calculating impedance


int main()
{
    unsigned nodeNum = 0;
    unsigned resNum = 0;
    unsigned capNum = 0;
    unsigned indNum = 0;

    cout << "Enter a value for Omega: ";
    cin >> OMEGA;

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

    string node1Name;
    string node2Name;

    Node node1(" ");
    Node node2(" ");

    // Source
    node1.setName(" "); // Reset the names to ensure they aren't carried over
    node2.setName(" ");

    string sourceType;
    double sourceMag = 0;
    double sourcePhase = 0;

    cout << "What type of source" << endl;
    cout << "Enter V for Voltage and I for Current:";
    cin >> sourceType;

    cout << "Enter Magnitude:";
    cin >> sourceMag;

    cout << "Enter Phase (in rad):";
    cin >> sourcePhase;

    cout << "Enter positive/forward current Nodes Name:";
    cin >> node1Name;

    cout << "Enter negative/reverse current Nodes Name:";
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

    Source* source;

    complex<double> sourceValue;
    sourceValue = polar(sourceMag,sourcePhase);

    if (sourceType == "V")
    {
        source = new VSource(node1, node2, sourceValue);
    }
    else if (sourceType == "I")
    {
        source = new ISource(node1, node2, sourceValue);
    }
    else
    {
        cout << "Bad source type";
        return -4;
    }


    getLoad<Resistor>(resNum, nodeList, resList, "Resistance");

    getLoad<Capacitor>(capNum, nodeList, capList, "Capacitance");

    getLoad<Inductor>(indNum, nodeList, indList, "Inductance");


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

    for (auto loadItr = loadMap.begin(); loadItr != loadMap.end(); loadItr++ ) // TODO: this may be nice to have as a helper function
    {
        cout << (*(loadItr->first))[0]; // either way works
        cout << " : ";
        cout << *(loadItr->first + 1); // either way works
        cout << " : ";
        cout << (loadItr->second).getElementName();
        cout << " : ";
        cout << (loadItr->second).getImpedance();
        cout << endl;
        cout << "-----------------------"<< endl;
    }
    source->print();

    //auto loadItr = loadMap.begin();

    //auto dwnCstSource = dynamic_cast<VSource*>(source);
    //dwnCstSource->setVoltage(5);

    //loadItr = loadMap.find( (*resListItr)->getNodes() );

    //Load* rPtr = &(loadItr->second);

    //auto dwnCast = dynamic_cast<Resistor*>(rPtr);
    //dwnCast->getResistance();




    return 0;
}

//complex<double> complexI (5.0,1.0);
//complex<double> complexZ (100.0,-8.0);

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

//cout << i.getNode1Name() << " -> " << i.getNode2Name() << endl; // TODO: new function? printNodeConnections()



/* ORIGINAL
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
*/