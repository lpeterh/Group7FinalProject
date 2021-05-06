#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <iostream>
#include <map>
#include <list>
#include <memory>
#include "Element.h"
#include "Load.h"

using namespace std;


void printLoadMap(multimap< string*, Load > loadMap);

void printLoadMapVals(multimap< string*, Load >& loadMap);



// This needs to be defined in the header as well
template<typename T>
void getLoad(unsigned loadNum, list<unique_ptr<Node>>& nodeList, list<unique_ptr<T>>& loadList, string units)
{
    unsigned num_copy = 0;

    Node node1(" ");
    Node node2(" ");

    string node1Name;
    string node2Name;

    double loadVal;

    auto nodeListItr = nodeList.begin();

    while (num_copy < loadNum)
    {
        node1.setName(" "); // Reset the names to ensure they aren't carried over
        node2.setName(" ");

        cout << "Enter " + units + ":";
        cin >> loadVal;

        cout << "Enter First Nodes Name:";
        cin >> node1Name;

        cout << "Enter Second Nodes Name:";
        cin >> node2Name;

        for (nodeListItr = nodeList.begin(); nodeListItr != nodeList.end(); nodeListItr++) // get the node for node 1 repeat for node 2
        {
            if (node1Name == (*nodeListItr)->getName()) {
                node1.setName(node1Name);
            }
            if (node2Name == (*nodeListItr)->getName()) {
                node2.setName(node2Name);
            }
        }
        if ((node1.getName() == " ") || (node2.getName() == " ")) // TODO: separate to say what node name failed
        {
            cout << "Node name not recognized";
            return;
        }

        loadList.push_back(make_unique<T>(node1, node2, loadVal)); // Resistor res = Resistor(N1,N2,R);
        num_copy++;
    }
}
/* ORIGINAL: DO NOT REMOVE
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

#endif

