#ifndef MODE
#define MODE

#include "../Definitions/Datatype.cpp"

class Mode {
private:
    uint run_time;
    uint number_comparison;

public:
    Mode() {
        this->run_time = 0;
        this->number_comparison = 0;
    }
};

#endif