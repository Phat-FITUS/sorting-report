#ifndef RADIXSORT
#define RADIXSORT

#include "Sort.cpp"

class RadixSort : public Sort {
private:
    void countingSort(int exp) {
        int *output = new int[size];
        int count[10] = {0}; //There are only digits from 0-9 in each units

        for (int i = 0; i < size; i++)
            count[(array[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = size - 1; i >= 0; i--) {
            output[count[(array[i] / exp) % 10] - 1] = array[i];
            count[(array[i] / exp) % 10]--;
        }

        for (int i = 0; i < size; i++)
            array[i] = output[i];

        delete[] output;
        output = NULL;
    }

    int FindMax(int* start, int* end) {
        int max_element = *start;

        for (int* p = start + 1; p != end; p++) {
            if (max_element < *p) {
                max_element = *p;
            }
        }

        return max_element;
    }

protected:
    void Handle(int &count_compare) {
        int maxVal = FindMax(array, array + size);

        for (int exp = 1; maxVal / exp > 0; exp *= 10)
            countingSort(exp);
    }

public:
    using Sort::Sort;
};

#endif