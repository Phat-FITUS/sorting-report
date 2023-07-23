#ifndef MODE
#define MODE

#include "../Definitions/Datatype.cpp"
#include "../Definitions/GenerationType.cpp"
#include "../Definitions/SortAlgorithm.cpp"
#include "../Algorithms/Sort.h"
// #include "../Resources/DataGenerator.cpp"

class Mode {
private:
    
protected:
    ull run_time;
    ull number_comparison;
    Sort *sort;
    char *sortName;
    char* file_input;
    char* getSortName(char input[]) {
        char * sortName = new char[10];
        int i=0;
        while(input[i] != '-') {
            sortName[i] = input[i];
            i++;
        }
        sortName[i] = '\0';
        return sortName;
    };

    int getInputSize(char filename[]) {
        this->file_input = new char[100];
        strcpy(this->file_input, "Inputs/");
	    strcat(this->file_input, filename);
        FILE* file = fopen(this->file_input, "rt");
        int size;
        fscanf(file, "%d\n", &size);

        fclose(file);
        return size;
    }

    void createFileInput(int size, char dataOptions[]) {
        GenerationType option;
        if(strcmp(dataOptions, "rand") == 0) option = Random;
        else if(strcmp(dataOptions, "sorted") == 0) option = Sorted;
        else if(strcmp(dataOptions, "rev") == 0) option = Reverse;
        else if(strcmp(dataOptions, "nsorted") == 0) option = NearlySorted;
        GenerateData(size, (int)option, (char*)"input.txt");
    }

    void getSortAlgorithm(const char* fileinput=NULL) {
        if(strcmp(this->sortName, "selection")==0) sort = new SelectionSort(fileinput);
        
        else if(strcmp(this->sortName, "insertion")==0) sort = new InsertionSort(fileinput);
        
        else if(strcmp(this->sortName, "bubble")==0) sort = new BubbleSort(fileinput);
        
        
        else if(strcmp(this->sortName, "shaker")==0) sort = new ShakerSort(fileinput);
        
        
        else if(strcmp(this->sortName, "shell")==0) sort = new ShellSort(fileinput);
        
        
        else if(strcmp(this->sortName, "heap")==0) sort = new HeapSort(fileinput);
        
        
        else if(strcmp(this->sortName, "merge")==0) sort = new MergeSort(fileinput);
        
        
        else if(strcmp(this->sortName, "quick")==0) sort = new QuickSort(fileinput);
        
        
        else if(strcmp(this->sortName, "counting")==0) sort = new CountingSort(fileinput);
        
        else if(strcmp(this->sortName, "radix")==0) sort = new RadixSort(fileinput);
        
        else if(strcmp(this->sortName, "flash")==0) sort = new FlashSort(fileinput);
        
        else return;
    }
    
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
        delete sortName;
        delete file_input;
    }
};

#endif