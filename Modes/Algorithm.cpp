#ifndef ALGORITHM_MODE
#define ALGORITHM_MODE

#include "Mode.cpp"

class Algorithm : public Mode{
    protected:
        char* input_file = NULL;
        char** agrv;
        int mode;
        int input_size = -1;
        char* input_order;

        void RunSort(char *sort) {
            this->sortName = this->getSortName(sort);
            this->getSortAlgorithm(this->input_file);
            this->sort->Run(this->run_time, this->number_comparison);
        }

        char* ConvertOrder(char* order) {
            if(order == "rand"){
                return (char*)"Randomize";
            }
            else if(order == "nsorted"){
                return (char*)"Nearly Sorted";
            }
            else if(order == "sorted"){
                return (char*)"Sorted";
            }
            else{
                return (char*)"Reversed";
            }
        }

        void ShowResult(char output[]) {
            if (output == "-time"){
                cout << "Running time: " << this->run_time << endl;
            }

            else if (output == "-comp"){
                cout << "Comparisions: " << this->number_comparison << endl;
            }

            else{
                cout << "Running time: " << this->run_time<<endl;
                cout << "Number of comparisons: " << this->number_comparison<<endl;
            }
        }

        void Mode3(char* options){
            this->createFileInput(this->input_size,options);
            this->input_file = options;
            this->input_order = ConvertOrder(options);
            this->RunSort(agrv[2]);
            cout << "Input order: " << this->input_order << endl;
            cout << "----------------------------------------------------------------" << endl;
            ShowResult(agrv[4]);
            delete sort;
        }

    public:
        void Run(int argc, char* argv[]) {
            this->agrv = argv;
            cout << "ALGORITHM MODE" << endl;
            cout << "algorithm: " << this->agrv[2] << endl;
            if ((int)agrv[3][0] >= (int)'0' && (int)agrv[3][0] <= (int)'9'){
                this->input_size = stoi(agrv[3]);
                cout << "Input size: " << this->input_size << endl;
                if(agrv[4] == "-rand" || agrv[4] == "-sorted" || agrv[4] == "-nsorted" || agrv[4] == "-reverse"){
                    this->createFileInput(this->input_size,agrv[4]+1);
                    this->input_file = agrv[4]+1;
                    this->input_order = ConvertOrder(agrv[4]+1);
                    cout << "Input order: " << this->input_order << endl;
                    cout << "----------------------------------------------------------------" << endl;
                    this->RunSort(agrv[2]);
                    ShowResult(agrv[5]);
                    delete sort;
                }
                else{
                    //random input
                    Mode3((char*)"rand");
                    //sorted input
                    Mode3((char*)"sorted");
                    //nearly sorted input
                    Mode3((char*)"nsorted");
                    //reverse input
                    Mode3((char*)"reverse");
                }
            }
            else{
                this->input_file = agrv[3];
                this->input_size = this->getInputSize(this->input_file);
                RunSort(agrv[2]);
                cout << "Input size: " << this->input_size << endl;
                cout << "----------------------------------------------------------------" << endl;
                ShowResult(agrv[4]);
                delete sort;
            }
        }

        using Mode::Mode;
};

#endif