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

        void RunSort(char *sort) {
            this->sortName = this->getSortName(sort);
            this->getSortAlgorithm(this->input_file);
            this->sort->Run(this->run_time, this->number_comparison);
        }
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
            if((int)argv[4][0] >= (int)'0' and (int)argv[4][0] <= (int)'9') {
                this->input_size = stoi(argv[4]);
                this->createFileInput(this->input_size, argv[5]+1);
                this->input_file = argv[5]+1;
            } else {
                this->input_file=argv[4];
                this->input_size = this->getInputSize(this->input_file);
                cout << "Input size: " << this->input_size << endl;
            }
            this->RunSort(argv[2]);
            this->run_time_0 = this->run_time;
            this->number_comparison_0 = this->number_comparison;
            delete this->sort;
            this->RunSort(argv[3]);
            ShowResult();
        }

        using Mode::Mode;
};

#endif