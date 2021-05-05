#include "helperFunctions.h"

void printLoadMap(multimap< string*, Load > loadMap)
{
    for (auto loadItr = loadMap.begin(); loadItr != loadMap.end(); loadItr++ )
    {
        cout << (loadItr->second).getNode1Name(); // either way works
        cout << " -> ";
        cout << (loadItr->second).getNode2Name(); // either way works
        cout << " : ";
        cout << (loadItr->second).getElementName();
        cout << " : ";
        cout << (loadItr->second).getImpedance();
        cout << endl;
        cout << "-----------------------"<< endl;
    }
}


void printLoadMapVals(multimap< string*, Load > &loadMap)
{
    for (auto loadItr = loadMap.begin(); loadItr != loadMap.end(); loadItr++ )
    {
        cout << (*(loadItr->first))[0]; // either way works
        cout << " -> ";
        cout << *(loadItr->first + 1); // either way works
        cout << " : ";
        cout << (loadItr->second).getElementName();
        cout << " : ";
        cout << (loadItr->second).getImpedance();
        cout << " : ";
        cout << (loadItr->second).getVoltageAcross();
        cout << " V : ";
        cout << (loadItr->second).getCurrentThrough();
        cout << " A" << endl;
        cout << "-----------------------"<< endl;
    }
}