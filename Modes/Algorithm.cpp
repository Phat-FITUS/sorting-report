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
            if(strcmp(order, "-rand") == 0) {
                return (char*)"Randomize";
            }
            else if(strcmp(order, "-nsorted") == 0){
                return (char*)"Nearly sorted";
            }
            else if(strcmp(order, "-sorted") == 0){
                return (char*)"Sorted";
            }
            else{
                return (char*)"Reversed";
            }
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
            cout << '\n';
        }

        char* inputfile(char* filename)
        {
            char* res = new char[12];
            if(strcmp(filename, "rand") == 0) {
                strcpy(res, "input_1.txt");
            }
            else if(strcmp(filename, "nsorted") == 0){
                strcpy(res, "input_2.txt");
            }
            else if(strcmp(filename, "sorted") == 0){
                strcpy(res, "input_3.txt");
            }
            else{
                strcpy(res, "input_4.txt");
            }
            return res;
        }

        void Mode3(char string[]){
            this->agrv[4] = string;
            this->createFileInput_algorithm(this->input_size,this->agrv[4]+1);
            this->input_file = inputfile(this->agrv[4]+1);
            this->input_order = ConvertOrder(this->agrv[4]);
            cout << endl;
            cout << "Input order: " << this->input_order << endl;
            cout << "----------------------------------------------------------------" << endl;
            this->RunSort(this->agrv[2]);
        }
  
        void createFileInput_algorithm(int size, char filename[]) {
            GenerationType option;
            char file[4][12] = {"input_1.txt", "input_2.txt", "input_3.txt", "input_4.txt"};
            int choose = -1;
            if(strcmp(filename, "rand") == 0) {
                option = Random;
                choose = 0;
            }
            else if(strcmp(filename, "sorted") == 0) {
                option = Sorted;
                choose = 1;
            }
            else if(strcmp(filename, "rev") == 0) {
                option = Reverse;
                choose = 2;
            }
            else if(strcmp(filename, "nsorted") == 0) {
                option = NearlySorted;
                choose = 3;
            }
            GenerateData(size, (int)option, file[choose]);
        }


    public:
        void Run(int argc, char* argv[]) {
            this->agrv = argv;
            cout << "ALGORITHM MODE" << endl;
            cout << "Algorithm: " << this->agrv[2] << endl;
            if ((int)agrv[3][0] >= (int)'0' && (int)agrv[3][0] <= (int)'9'){
                this->input_size = stoi(agrv[3]);
                cout << "Input size: " << this->input_size << endl;
                char* order = agrv[5];
                if(strcmp(this->agrv[4],"-rand") == 0 || strcmp(this->agrv[4],"-sorted") == 0 || strcmp(this->agrv[4],"-nsorted") == 0 || strcmp(this->agrv[4],"-rev") == 0){
                    this->createFileInput_algorithm(this->input_size,agrv[4]+1);
                    this->input_file = inputfile(this->agrv[4]+1);
                    this->input_order = ConvertOrder(this->agrv[4]);
                    cout << "Input order: " << this->input_order << endl;
                    cout << "----------------------------------------------------------------" << endl;
                    this->RunSort(agrv[2]);
                    ShowResult(agrv[5]);
                    delete sort;
                }
                else{
                    char* oput = NULL;
                    oput = this->agrv[4];
                    char string_1[] = "-rand";
                    Mode3(string_1);
                    ShowResult(oput);
                    delete sort;
                    char string_2[] = "-nsorted";
                    Mode3(string_2);
                    ShowResult(oput);
                    delete sort;
                    char string_3[] = "-sorted";
                    Mode3(string_3);
                    ShowResult(oput);
                    delete sort;
                    char string_4[] = "-rev";
                    Mode3(string_4);
                    ShowResult(oput);
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