#ifndef MODE
#define MODE

#include "../Definitions/Datatype.cpp"
#include "../Definitions/SortAlgorithm.cpp"
#include "../Algorithms/Sort.h"

class Mode {
private:
    
protected:
    ull run_time;
    ull number_comparison;
    Sort *sort;
    char *sortName;
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

    void getSortAlgorithm(const char* fileinput) {
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
        delete[] sortName;
    }
};

#endif