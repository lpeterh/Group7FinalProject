#include "Analysis.h"

int testRelation(multimap<std::string*, Load>& loadMap, std::string sharedNode, std::multimap<std::string*, Load>::iterator loadItr1, std::multimap<std::string*, Load>::iterator loadItr2, Source* source)
{
    if( testSeries(loadMap, sharedNode, loadItr1,loadItr2, source) )
    {
        return 0; // series
    }
    else if( testParallel(loadItr1, loadItr2) )
    {
        return 1; // parallel
    }
    else
    {
        return -1;
        // not either
    }

}


bool testSeries(multimap<std::string*, Load>& loadMap, std::string sharedNode, std::multimap<std::string*, Load>::iterator loadItr1, std::multimap<std::string*, Load>::iterator loadItr2, Source* source)
{
    std::string load3Node1;
    std::string load3Node2;
    for (auto loadItr3 = loadMap.begin(); loadItr3 != loadMap.end(); loadItr3++ )
    {
        load3Node1 = (loadItr3->first)[0];
        load3Node2 = (loadItr3->first)[1];
        if (loadItr3 == loadItr1 || loadItr3 == loadItr2)
        {
            continue;
        }
        else if( load3Node1 == sharedNode || load3Node2 == sharedNode )
        {
            return false;
        }
        else if( source->getNode1Name() == sharedNode || source->getNode2Name() == sharedNode )
        {
            return false;
        }

    }
    return true;
}


bool testParallel(std::multimap<std::string*, Load>::iterator loadItr1, std::multimap<std::string*, Load>::iterator loadItr2)
{
    std::string L1N1 = (loadItr1->first)[0];
    std::string L1N2 = (loadItr1->first)[1];
    std::string L2N1 = (loadItr2->first)[0];
    std::string L2N2 = (loadItr2->first)[1];

    if ( L1N1 == L2N1 && L1N2 == L2N2 )
    {
        return true;
    }
    else if ( L1N1 == L2N2 && L1N2 == L2N1 )
    {
        return true;
    }
    else
    {
        return false;
    }

}
