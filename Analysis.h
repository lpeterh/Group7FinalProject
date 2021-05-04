#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "Circuit.h"

int testRelation(multimap<std::string*, Load>& loadMap, std::string sharedNode, std::multimap<std::string*, Load>::iterator loadItr1, std::multimap<std::string*, Load>::iterator loadItr2, Source* source);

bool testSeries(multimap<std::string*, Load>& loadMap, std::string sharedNode, std::multimap<std::string*, Load>::iterator loadItr1, std::multimap<std::string*, Load>::iterator loadItr2, Source* source);
bool testParallel(std::multimap<std::string*, Load>::iterator loadItr1, std::multimap<std::string*, Load>::iterator loadItr2);

bool analyzeCircuit(multimap< string*, Load > &loadMap, Source* source);


complex<double> ohmV(complex<double> impedance, complex<double> current);
complex<double> ohmC(complex<double> impedance, complex<double> voltage);

complex<double> voltageDivision(complex<double> voltage, complex<double> partialImpedance, complex<double> totalImpedance);

#endif