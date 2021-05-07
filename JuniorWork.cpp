/*
#include <iostream>
#include <complex>

using namespace std;
// Ohms law used to find voltage given current and impedance. V = I*Z;
complex<double> ohmV(complex<double> impedance, complex<double> current)
{
    complex<double> OhmV;
    OhmV = impedance * current;
    cout << OhmV << endl;
    return OhmV;
};
// Ohms law used to find current given voltage and impedance. I = V/Z;
complex<double> ohmC(complex<double> impedance, complex<double> voltage)
{
    complex<double> OhmC;
    OhmC = voltage / impedance;
    cout << OhmC << endl;
    return OhmC;
};

//this uses voltage division, so basically voltage through element = voltage*(elementImpedance/ totalImpedance);
complex<double> voltageDivision(complex<double> voltage, complex<double> partialImpedance, complex<double> totalImpedance)
{
    complex<double> specificVoltage;
    specificVoltage = voltage * (partialImpedance/totalImpedance);
    cout << specificVoltage << endl;
    return specificVoltage;
};
 */