#include <iostream>
#include <memory>
#include <string>
#include <complex>
#include <map>
#include <list>
#include <vector>
#include <memory>

#include "Circuit.h"

using namespace std;

double OMEGA = 1; // will give access global access for elements when calculating impedance


int main()
{
/*
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

    // Used for keeping track of how many times to create nodes
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
*/
     //printLoadMap(loadMap);


    // FOR TESTING
    Node N_A("A");
    Node N_B("B");
    Node N_C("C");
    Node GND("GND");

    list<unique_ptr<Node>> nodeList;
    nodeList.push_back( make_unique<Node>("A") );
    nodeList.push_back( make_unique<Node>("B") );
    nodeList.push_back( make_unique<Node>("C") );
    nodeList.push_back( make_unique<Node>("GND") );

    nodeList.sort();
    auto n = nodeList.begin();

    string quickNodesR1[2] = {"A", "B"};
    string quickNodesR2[2] = {"B", "GND"};
    string quickNodesC1[2] = {"C", "GND"};
    string quickNodesL1[2] = {"B", "C"};
    string quickNodesS1[2] = {"A", "GND"};

    Source* source;

    complex<double> sourceValue;
    sourceValue = polar(50,0);
    source = new VSource(N_A, GND, sourceValue);
    string sourceType = "V";


    multimap< string*, Load > loadMap;
    loadMap.insert( pair(quickNodesR1, Resistor( N_A, N_B, 10)));
    loadMap.insert( pair(quickNodesR2, Resistor(N_B, GND, 20)));
    loadMap.insert( pair(quickNodesC1, Capacitor(N_C, GND, 0.025)));
    loadMap.insert( pair(quickNodesL1, Inductor(N_B, N_C, 30)));

    cout << "User Inputted: " << endl;
    printLoadMap(loadMap);

    // This is stupid, print would do that anyway as it is a virtual
    // but downcasting the loads in the map doesn't work for some reason?
    // and source is the only element that is not in the map
    // so to fulfill the requirement of downcasting, here  are...
    // (please have mercy)
    //source->print();
    if(sourceType == "V")
    {
        (dynamic_cast<VSource*>(source))->print();
    }
    else if(sourceType == "I")
    {
        (dynamic_cast<ISource*>(source))->print();
    }

    cout << endl << endl;
    cout << "Values Found: " << endl;
    auto it = loadMap.begin();
    //cout << analyzeCircuit(loadMap, source, it) << endl;
    analyzeCircuit(loadMap, source, it );


    printLoadMapVals(loadMap);

    return 0;
}
