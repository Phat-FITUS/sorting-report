#ifndef COMPARISON_MODE
#define COMPARISON_MODE

#include "Mode.cpp"

class Comparison : public Mode{
    protected:

        void ShowResult(char output[]) {

        }

    public:
        void Run(int argc, char* argv[]) {

        }

        using Mode::Mode;
};

#endif