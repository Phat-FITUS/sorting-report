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

        char* ConvertOrder(char order[]) {
           /*if(order == "rand"){
                return order;
            }
            else if(order == "nsorted"){
                return order;
            }
            else if(order == "sorted"){
                return dd"Sorted";
            }
            else{
                return "reversed";
            }*/
            return 0;
        }

        void ShowResult(char output[]) {
            if (strcmp(output, "-time") == 0 ){
                cout << "Running time: " << this->run_time << endl;
            }

            else if (strcmp(output, "-comp") == 0 ){
                cout << "Comparisions: " << this->number_comparison << endl;
            }

            else{
                cout << "Running time: " << this->run_time<<endl;
                cout << "Number of comparisons: " << this->number_comparison<<endl;
            }
        }

        void Mode3(char string[]){
            char* oput = NULL;
            oput = this->agrv[4];
            this->agrv[4] = string;
            this->createFileInput(this->input_size,this->agrv[4]+1);
            this->input_file = this->agrv[4]+1;
            this->input_order = this->agrv[4]+1;
            cout << "Input order: " << this->input_order << endl;
            cout << "----------------------------------------------------------------" << endl;
            this->RunSort(this->agrv[2]);
            ShowResult(oput);
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
                char* order = agrv[5];
                //cout << "Order: " << order << endl;
                if(strcmp(this->agrv[4],"-rand") == 0 || strcmp(this->agrv[4],"-sorted") == 0 || strcmp(this->agrv[4],"-nsorted") == 0 || strcmp(this->agrv[4],"-reverse") == 0){
                    this->createFileInput(this->input_size,agrv[4]+1);
                    this->input_file = agrv[4]+1;
                    this->input_order = agrv[4]+1;
                    cout << "Input order: " << this->input_order << endl;
                    cout << "----------------------------------------------------------------" << endl;
                    this->RunSort(agrv[2]);
                    ShowResult(agrv[5]);
                    delete sort;
                }
                else{
                    char string[] = "-rand";
                    Mode3(string);
                    char string_2[] = "-nsorted";
                    Mode3(string_2);
                    char string_3[] = "-sorted";
                    Mode3(string_3);
                    char string_4[] = "-reverse";
                    Mode3(string_4);
                }
            }
            else{
                this->input_file = agrv[3];
                this->input_size = this->getInputSize(this->input_file);
                RunSort(agrv[2]);
                cout << "Input size: " << this->input_size << endl;
                cout << "----------------------------------------------------------------" << endl;
                ShowResult(this->agrv[4]);
                delete sort;
            }
        }

        using Mode::Mode;
};

#endif