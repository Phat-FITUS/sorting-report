#ifndef SORT
#define SORT

#include "../Resources/external_lib.h"
#include "../Definitions/Datatype.cpp"
#include "../Resources/DataGenerator.cpp"

class Sort {
private:
    char* file_input;

    void LoadData() {
        FILE* file = fopen(file_input, "rt");

        fscanf(file, "%d\n", &this->size);

        this->array = new int[this->size];
        for (int i = 0; i < this->size; i++) {
            fscanf(file, "%d ", &this->array[i]);
        }

        fclose(file);
    }

    void SaveData() {
        FILE* file = fopen("output.txt", "wt");

        fprintf(file, "%d\n", this->size);

        for (int i = 0; i < this->size; i++) {
            fprintf(file, "%d ", this->array[i]);
        }

        fclose(file);
    }

protected:
    int* array;
    int size;

    virtual void Handle(int &count_compare) = 0;

public:
    Sort() {
        this->array = 0;
        this->size = 0;

        file_input = new char[20];
        strcpy(file_input, "Inputs/input.txt");
        file_input[19] = '\0';

        this->LoadData();
    }

    Sort(const char filename[]) {
        this->array = 0;
        this->size = 0;

        this->file_input = new char[100];
        strcpy(this->file_input, "Inputs/");
	    strcat(this->file_input, filename);

        this->LoadData();
    }

    void Run(int &running_time, int &count_compare) {
        count_compare = 0;

        auto start = std::chrono::high_resolution_clock::now();

        Handle(count_compare);

        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<miliseconds>(stop - start);

        running_time = duration.count();

        this->SaveData();
    }

    ~Sort() {
        delete[] this->array;
        delete[] this->file_input;
    }
};

#endif