#include "helperFunctions.h"
#include <string>
#include <iomanip>

void printLoadMap(multimap< string*, Load > loadMap)
{
    int barNum = 37;
    int nodeWidth = [loadMap](int max = 0)mutable{
        for(auto loadItr = loadMap.begin(); loadItr != loadMap.end(); loadItr++ ){
            if(((loadItr->second).getNode1Name()).size() > max) {max = ((loadItr->second).getNode1Name()).size();}
            if(((loadItr->second).getNode2Name()).size() > max) {max = ((loadItr->second).getNode2Name()).size();}
        }return max; }();
    int nameWidth = [loadMap](int max = 0)mutable{
        for(auto loadItr = loadMap.begin(); loadItr != loadMap.end(); loadItr++ ){
            if(((loadItr->second).getElementName()).size() > max) {max = ((loadItr->second).getElementName()).size();}
        }return max; }();



    for (auto loadItr = loadMap.begin(); loadItr != loadMap.end(); loadItr++ )
    {
        cout << std::setprecision(3);
        cout << setw(nodeWidth) << (loadItr->second).getNode1Name(); // either way works
        cout << " -> ";
        cout << left;
        cout << setw(nodeWidth) << (loadItr->second).getNode2Name(); // either way works
        cout << " : ";
        cout << setw(nameWidth) << (loadItr->second).getElementName();
        cout << " : ";
        cout << setw(16) << (loadItr->second).getImpedance();
        cout << endl;
        cout << std::string(barNum, '-') <<endl;
        cout << right;
        cout.unsetf(std::ios_base::floatfield);
    }
}


void printLoadMapVals(multimap< string*, Load > &loadMap)
{
    int barNum = 75;
    int nodeWidth = [loadMap](int max = 0)mutable{
        for(auto loadItr = loadMap.begin(); loadItr != loadMap.end(); loadItr++ ){
            if(((loadItr->second).getNode1Name()).size() > max) {max = ((loadItr->second).getNode1Name()).size();}
            if(((loadItr->second).getNode2Name()).size() > max) {max = ((loadItr->second).getNode2Name()).size();}
        }return max; }();
    int nameWidth = [loadMap](int max = 0)mutable{
        for(auto loadItr = loadMap.begin(); loadItr != loadMap.end(); loadItr++ ){
            if(((loadItr->second).getElementName()).size() > max) {max = ((loadItr->second).getElementName()).size();}
        }return max; }();

    for (auto loadItr = loadMap.begin(); loadItr != loadMap.end(); loadItr++ )
    {
        cout << std::setprecision(3);
        cout << setw(nodeWidth) << (loadItr->second).getNode1Name(); // either way works
        cout << " -> ";
        cout << left;
        cout << setw(nodeWidth) << (loadItr->second).getNode2Name(); // either way works
        cout << " : ";
        cout << setw(nameWidth) << (loadItr->second).getElementName();
        cout << " : ";

        cout << right;
        cout << setw(3) << real( (loadItr->second).getImpedance() );
        cout << left;
        cout << [loadItr](){if(imag((loadItr->second).getImpedance() ) >= 0)return"+j";return"-j";}();
        cout << setw(3) << abs( imag( (loadItr->second).getImpedance()));

        cout << " : (";
        cout << abs( (loadItr->second).getVoltageAcross() ) << ", " << ((arg( (loadItr->second).getVoltageAcross() ))*180)/M_PI << "\370";
        cout << ") V : (";
        cout << abs( (loadItr->second).getCurrentThrough() ) << ", " << ((arg( (loadItr->second).getCurrentThrough() ))*180)/M_PI << "\370";
        cout << ") A" << endl;
        cout << std::string(barNum, '-') <<endl;

        cout << right;
        cout.unsetf(std::ios_base::floatfield);

    }
}