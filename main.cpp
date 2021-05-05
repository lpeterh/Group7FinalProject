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
    */

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
    string quickNodesC1[2] = {"B", "GND"};
    string quickNodesL1[2] = {"B", "GND"};
    string quickNodesS1[2] = {"A", "GND"};

    Source* source;

    complex<double> sourceValue;
    sourceValue = polar(50,0);
    source = new ISource(N_A, GND, sourceValue);


    multimap< string*, Load > loadMap;
    loadMap.insert( pair(quickNodesR1, Resistor( N_A, N_B, 10)));
    loadMap.insert( pair(quickNodesR2, Resistor(N_B, GND, 20)));
    loadMap.insert( pair(quickNodesC1, Capacitor(N_B, GND, 0.025)));
    loadMap.insert( pair(quickNodesL1, Inductor(N_B, GND, 30)));

    printLoadMap(loadMap);


/*
    // Find parallel and series
    string load1Node1;
    string load1Node2;
    string load2Node1;
    string load2Node2;
    string nodePair[2];
    auto matchNode = loadMap.begin();
    for (auto loadItr1 = loadMap.begin(); loadItr1 != loadMap.end(); loadItr1++ )
    {
        load1Node1 = (loadItr1->first)[0];
        load1Node2 = (loadItr1->first)[1];
        //cout << load1Node1 << " -> " << load1Node2 << endl;

        nodePair[0] = load1Node1;
        nodePair[1] = load1Node2;

        int loadCases; // 0 = series, 1 = parallel, -1 = neither

        loadCases = 0;


        for (auto loadItr2 = loadMap.begin(); loadItr2 != loadMap.end(); loadItr2++ )
        {
            load2Node1 = (loadItr2->first)[0];
            load2Node2 = (loadItr2->first)[1];

            if(loadItr2 == loadItr1)
            {
                //same element
                loadCases = 1;
                continue;
            }
            else if( load1Node1 == load2Node1 || load1Node2 == load2Node1 )
            {
                loadCases = 2;

                cout << (loadItr1->second).getElementName() << " " <<(loadItr1->second).getImpedance();
                cout << " matches with ";
                cout << (loadItr2->second).getElementName()<< " " << (loadItr2->second).getImpedance();
                cout << " at Node " <<  load2Node1 << endl;

                loadCases = testRelation(loadMap, load2Node1, loadItr1, loadItr2, source);

            }
            else if( load1Node1 == load2Node2 || load1Node2 == load2Node2 )
            {
                loadCases = 3;
                cout << (loadItr1->second).getElementName() << " " <<(loadItr1->second).getImpedance();
                cout << " matches with ";
                cout << (loadItr2->second).getElementName()<< " " << (loadItr2->second).getImpedance();
                cout << " at Node " <<  load2Node2 << endl;
                loadCases = testRelation(loadMap, load2Node2, loadItr1, loadItr2, source);
            }
            else
            {
                loadCases = 4;
                cout << (loadItr1->second).getElementName() << " " <<(loadItr1->second).getImpedance();
                cout << " does not match with ";
                cout << (loadItr2->second).getElementName()<< " " << (loadItr2->second).getImpedance() << endl;
                loadCases = 3;
            }

            switch (loadCases) // 0 = series, 1 = parallel, -1 = neither
            {

                case 0:
                    cout << "Looks like series" << endl;
                    break;
                case 1:
                    cout << "Looks like parallel" << endl;
                    break;
                case -1:
                    cout << "Looks like nothing :(" << endl;
                    break;
                case 3:
                    break;

                default:
                    cout <<"bad Case" << endl;
                    return -6;

            }



        }
        cout << "-----------------------------------------------------------" << endl;

    }
    */

    source->print();

    //cout << analyzeCircuit(loadMap, source) << endl;
    auto it = loadMap.begin();
    analyzeCircuit(loadMap, source, it );
    printLoadMapVals(loadMap);



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



