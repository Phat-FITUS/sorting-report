#ifndef ALGORITHM_MODE
#define ALGORITHM_MODE

#include "Mode.cpp"

class Algorithm : public Mode{
    protected:

        void ShowResult(char output[]) {

        }

    public:
        void Run(int argc, char* argv[]) {

        }

        using Mode::Mode;
};

#endif