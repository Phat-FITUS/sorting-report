#ifndef MODE
#define MODE

#include "../Definitions/Datatype.cpp"
#include "../Algorithms/Sort.h"

class Mode {
private:
    ull run_time;
    ull number_comparison;
    Sort *sort;

protected:
    virtual void ShowResult(char output[]) = 0;

public:
    Mode() {
        this->run_time = 0;
        this->number_comparison = 0;
        sort = NULL;
    }

    virtual void Run(int argc, char* argv[]) = 0;

    ~Mode() {
        delete sort;
    }
};

#endif