#include "helperFunctions.h"

void printLoadMap(multimap< string*, Load > loadMap)
{
    for (auto loadItr = loadMap.begin(); loadItr != loadMap.end(); loadItr++ )
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
}