//
// Created by lphan on 4/29/2021.
//

friend Load operator+(const Load& A, const Load& B);

friend Load operator||(const Load& A, const Load& B);

Load operator+(const Load& A, const Load& B)
{
    std::complex <double> ZResult;
    ZResult = A.impedance + B.impedance;
    Load result("SeriesLoad", Node n1("1"), Node n2("2"), 0, 0, Zresult);

    return result;

}

Load operator||(const Load& A, const Load& B)
{
    std::complex <double> ZResult;
    ZResult = (1.00/(((1.00)/(A.impedance)) + ((1.00)/(B.impedance))));
    Load result("SeriesLoad", Node n1("1"), Node n2("2"), 0, 0, Zresult);

    return result;

}
