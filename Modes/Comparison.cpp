#ifndef COMPARISON_MODE
#define COMPARISON_MODE

#include "Mode.cpp"

class Comparison : public Mode{
    private:
        ull run_time_0;
        ull number_comparison_0;
        char** argv = NULL;
        char* input_file = NULL;
        int input_size = -1;
        int input_order = -1;
    protected:

        void ShowResult(char output[] = NULL) {
            cout << "COMPARISON MODE: " << endl;
            cout << "Algorithm: " << this->argv[2] << " | " << this->argv[3]<< endl;
            if(this->input_file) cout << "Input file: " << this->input_file << endl;
            cout << "Input size: " << this->input_size << endl;
            if(this->input_order != -1) cout << "Input order: " << this->input_order << endl;
            cout << "-----------------------" << endl;
            cout << "Running time: " << this->run_time_0 << " | " << this->run_time << endl;
            cout << "Comparison: " << this->number_comparison_0 << " | " << this->number_comparison << endl;
        }

    public:
        void Run(int argc, char* argv[]) {
            this->argv = argv;
            if(argv[4][0] >= '0' and argv[4][0] <= '9') {
                cout << "Waiting for phat..." << endl;
                return;
            }
            this->input_file=argv[4];
            this->sortName = this->getSortName(argv[2]);
            this->getSortAlgorithm(this->input_file);
            sort->Run(this->run_time, this->number_comparison);
            this->run_time_0 = this->run_time;
            this->number_comparison_0 = this->number_comparison;
            delete this->sort;
            this->sortName = this->getSortName(argv[3]);
            this->getSortAlgorithm(this->input_file);
            sort->Run(this->run_time, this->number_comparison);
            ShowResult();
        }

        using Mode::Mode;
};

#endif