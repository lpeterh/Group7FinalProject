#include "Analysis.h"


bool analyzeCircuit(multimap< string*, Load >& loadMap, Source* source)
{
    // Test for thevenin / norton
    if( loadMap.size() == 1)
    {
        auto loadMapItr1 = loadMap.begin();
        if (source->getElementName() == "Voltage Source" )
        {
            // therefore we know the voltage across,
            (loadMapItr1->second).setVoltageAcross(source->getVoltageAcross());
            (loadMapItr1->second).setVGood(true);

            // And can find the current using ohms law
            (loadMapItr1->second).setCurrentThrough( ohmC( (loadMapItr1->second).getImpedance(), (loadMapItr1->second).getVoltageAcross() ) );
            (loadMapItr1->second).setIGood(true);
        }
        else if (source->getElementName() == "Current Source" )
        {
            // therefore we know the current across, and can find the voltage using ohms law
            (loadMapItr1->second).setCurrentThrough(source->getCurrentThrough());
            (loadMapItr1->second).setIGood(true);

            // And can find the voltage using ohms law
            (loadMapItr1->second).setVoltageAcross( ohmV( (loadMapItr1->second).getImpedance(), (loadMapItr1->second).getCurrentThrough() ) );
            (loadMapItr1->second).setVGood(true);
        }
        else
        {
            std::cout << "Bad source" << std::endl;
        }
        return true;
    }
    else
    {
        // find series / parallel

        multimap< string*, Load > loadMap2;
        loadMap2 = loadMap;

        string load1Node1;
        string load1Node2;
        string load2Node1;
        string load2Node2;
        string nodePair[2];

        int found = 0;

        auto OGMapItr1 = loadMap.begin();
        auto OGMapItr2 = loadMap.begin();
        auto loadItr1 = loadMap2.begin();
        auto loadItr2 = loadMap2.begin();

        auto addedLoadItr = loadMap2.begin();

        int loadCases; // 0 = series, 1 = parallel, -1 = neither

        while (loadItr1 != loadMap2.end() && found != 1)
        {
            load1Node1 = (loadItr1->first)[0];
            load1Node2 = (loadItr1->first)[1];
            //cout << load1Node1 << " -> " << load1Node2 << endl;

            loadCases = 0;

            loadItr2 = loadMap2.begin();
            while(loadItr2 != loadMap2.end() && found != 1)
            {
                load2Node1 = (loadItr2->first)[0];
                load2Node2 = (loadItr2->first)[1];

                if(loadItr2 == loadItr1)
                {
                    //same element
                    loadCases = 1;
                    loadItr2++;
                    OGMapItr2++;
                    continue;
                }
                else if( load1Node1 == load2Node1 || load1Node2 == load2Node1 )
                {
                    loadCases = 2;
                    //cout << (loadItr1->second).getElementName() << " " <<(loadItr1->second).getImpedance();
                    //cout << " matches with ";
                    //cout << (loadItr2->second).getElementName()<< " " << (loadItr2->second).getImpedance();
                    //cout << " at Node " <<  load2Node1 << endl;
                    loadCases = testRelation(loadMap2, load2Node1, loadItr1, loadItr2, source);
                }
                else if( load1Node1 == load2Node2 || load1Node2 == load2Node2 )
                {
                    loadCases = 3;
                    //cout << (loadItr1->second).getElementName() << " " <<(loadItr1->second).getImpedance();
                    //cout << " matches with ";
                    //cout << (loadItr2->second).getElementName()<< " " << (loadItr2->second).getImpedance();
                    //cout << " at Node " <<  load2Node2 << endl;
                    loadCases = testRelation(loadMap2, load2Node2, loadItr1, loadItr2, source);
                }
                else
                {
                    loadCases = 4;
                    //cout << (loadItr1->second).getElementName() << " " <<(loadItr1->second).getImpedance();
                    //cout << " does not match with ";
                    //cout << (loadItr2->second).getElementName()<< " " << (loadItr2->second).getImpedance() << endl;
                    loadCases = 3;
                }

                switch (loadCases) // 0 = series, 1 = parallel, -1 = neither
                {
                    case 0:
                        //cout << "Looks like series" << endl;
                        if ((loadItr1->first)[0] == (loadItr2->first)[0] )
                        {
                            nodePair[0] = (loadItr1->first)[1];
                            nodePair[1] = (loadItr2->first)[1];
                        }
                        else if ((loadItr1->first)[1] == (loadItr2->first)[1] )
                        {
                            nodePair[0] = (loadItr1->first)[0];
                            nodePair[1] = (loadItr2->first)[0];
                        }
                        else if ((loadItr1->first)[0] == (loadItr2->first)[1] )
                        {
                            nodePair[0] = (loadItr1->first)[1];
                            nodePair[1] = (loadItr2->first)[0];
                        }
                        else if ((loadItr1->first)[1] == (loadItr2->first)[0] )
                        {
                            nodePair[0] = (loadItr1->first)[0];
                            nodePair[1] = (loadItr2->first)[1];
                        }

                        addedLoadItr = loadMap2.insert( pair(nodePair, Load( "Z", Node(nodePair[0]), Node(nodePair[1]), 0, 0, (loadItr1->second).getImpedance() + (loadItr2->second).getImpedance() ) ) );

                        loadMap2.erase( loadItr1 );
                        loadMap2.erase( loadItr2 );

                        found = 1;

                        analyzeCircuit(loadMap2, source); // recursion

                        break;
                    case 1:
                        //cout << "Looks like parallel" << endl;
                        nodePair[0] = (loadItr1->first)[0];
                        nodePair[1] = (loadItr1->first)[1];

                        addedLoadItr = loadMap2.insert( pair(nodePair, Load( "Z", Node(nodePair[0]), Node(nodePair[1]), 0, 0,
                                                              1.0 / ( (1.0/(loadItr1->second).getImpedance()) + (1.0/(loadItr2->second).getImpedance()) ) ) ) );
                        loadMap2.erase(loadItr1);
                        loadMap2.erase(loadItr2);

                        found = 1;

                        analyzeCircuit(loadMap2, source); // recursion

                        break;
                    case -1:
                        //cout << "Looks like nothing :(" << endl;

                    case 3:
                        break;

                    default:
                        //cout <<"bad Case" << endl;
                        return -6;

                }
                if (found != 1)
                {
                    loadItr2++;
                    OGMapItr2++;
                }
            }

            if (found != 1)
            {
                OGMapItr1++;
                loadItr1++;
            }

        }

        // based on series or parallel, give current / voltage, find other with ohms
        std::cout << (addedLoadItr->second).getImpedance() << " : " << (addedLoadItr->second).getVoltageAcross() << " V ---- " << (addedLoadItr->second).getCurrentThrough() << " A" << std::endl;

        auto j = loadMap.begin();
        for(auto i = loadMap2.begin(); i != loadMap2.end(); i++)
        {
            if(i != addedLoadItr)
            {
                (j->second).setVoltageAcross((i->second).getVoltageAcross());
                (j->second).setCurrentThrough((i->second).getCurrentThrough());
            }
            j++;

        }

        // loadCases, 0 = series, 1 = parallel, -1 = neither
        if (loadCases == 0) // series therefore current is the same, use current to find voltage
        {
            (OGMapItr1->second).setCurrentThrough( (addedLoadItr->second).getCurrentThrough() );
            (OGMapItr1->second).setIGood(true);
            (OGMapItr2->second).setCurrentThrough( (addedLoadItr->second).getCurrentThrough() );
            (OGMapItr2->second).setIGood(true);

            (OGMapItr1->second).setVoltageAcross( ohmV( (OGMapItr1->second).getImpedance(), (OGMapItr1->second).getCurrentThrough() ) );
            (OGMapItr1->second).setVGood(true);
            (OGMapItr2->second).setVoltageAcross( ohmV( (OGMapItr2->second).getImpedance(), (OGMapItr2->second).getCurrentThrough() ) );
            (OGMapItr2->second).setVGood(true);
        }
        else if (loadCases == 1) // parallel therefore voltage is the same, use voltage to find current
        {
            (OGMapItr1->second).setVoltageAcross( (addedLoadItr->second).getVoltageAcross() );
            (OGMapItr1->second).setVGood(true);
            (OGMapItr2->second).setVoltageAcross( (addedLoadItr->second).getVoltageAcross() );
            (OGMapItr2->second).setVGood(true);

            (OGMapItr1->second).setCurrentThrough( ohmC( (OGMapItr1->second).getImpedance(), (OGMapItr1->second).getVoltageAcross() ) );
            (OGMapItr1->second).setIGood(true);
            (OGMapItr2->second).setCurrentThrough( ohmC( (OGMapItr2->second).getImpedance(), (OGMapItr2->second).getVoltageAcross() ) );
            (OGMapItr2->second).setIGood(true);
        }
        else
        {
            std::cout << "Error, loadcases is not what it should ba at bottom of analyze" << std::endl;
        }

        return true;
    }
    return false;
}



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
        if (  (loadItr1->first)[0] == (loadItr2->first)[0] && (loadItr1->first)[1] == (loadItr2->first)[1]  )
        {
            return false;
        }
        else if (  (loadItr1->first)[0] == (loadItr2->first)[1] && (loadItr1->first)[1] == (loadItr2->first)[0]  )
        {
            return false;
        }
        else if (loadItr3 == loadItr1 || loadItr3 == loadItr2)
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

// Ohms law used to find voltage given current and impedance. V = I*Z;
complex<double> ohmV(complex<double> impedance, complex<double> current)
{
    complex<double> OhmV;
    OhmV = impedance * current;
    //std::cout << OhmV << std::endl;
    return OhmV;
};
// Ohms law used to find current given voltage and impedance. I = V/Z;
complex<double> ohmC(complex<double> impedance, complex<double> voltage)
{
    complex<double> OhmC;
    OhmC = voltage / impedance;
    //std::cout << OhmC << std::endl;
    return OhmC;
};

//this uses voltage division, so basically voltage through element = voltage*(elementImpedance/ totalImpedance);
complex<double> voltageDivision(complex<double> voltage, complex<double> partialImpedance, complex<double> totalImpedance)
{
    complex<double> specificVoltage;
    specificVoltage = voltage * (partialImpedance/totalImpedance);
    //std::cout << specificVoltage << std::endl;
    return specificVoltage;
};



