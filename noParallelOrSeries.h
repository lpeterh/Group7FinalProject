#ifndef NOPARALLELORSERIES_H
#define NOPARALLELORSERIES_H

#include <stdexcept>
using namespace std;

class noParallelOrSeries : public runtime_error
{
public:
    noParallelOrSeries() : runtime_error("Circuit could not be simplified") {};
};


#endif
