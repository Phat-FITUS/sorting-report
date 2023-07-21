#ifndef ALGORITHM_MODE
#define ALGORITHM_MODE

#include "Mode.cpp"

class Algorithm : public Mode{
    protected:
        char* input_file = NULL;
        char** agrv;
        int mode;
        int input_size = -1;
        int input_order = -1;
        void RunSort(char *sort) {
            this->sortName = this->getSortName(sort);
            this->getSortAlgorithm(this->input_file);
            this->sort->Run(this->run_time, this->number_comparison);
        }

        void ShowResult(char output[]) {
            cout << "ALGORITHM MODE" << endl;
            cout << "algorithm: " << this->agrv[2] << endl;

            cout << "Input size: " << this->input_size << endl;
            cout << "Input order: " << this->input_order << endl;
            cout << "----------------------------------------------------------------" << endl;
            if (output == "-time"){
                cout << "Running time: " << this->run_time;
            }
            else if (output == "-comp"){
                cout << "Comparisions: " << this->number_comparison;
            }
            else{
                cout << "Running time: " << this->run_time<<endl;
                cout << "Number of comparisons: " << this->number_comparison<<endl;
            }
        }

    public:
        void Run(int argc, char* argv[]) {

        }

        using Mode::Mode;
};

#endif