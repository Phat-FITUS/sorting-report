#ifndef RADIXSORT
#define RADIXSORT

#include "Sort.cpp"

class RadixSort : public Sort {
private:
    void countingSort(int exp, ull &count_compare) {
        int *output = new int[size];
        int count[10] = {0}; //There are only digits from 0-9 in each units

        for (int i = 0; ++count_compare && i < size; i++)
            count[(array[i] / exp) % 10]++;

        for (int i = 1; ++count_compare && i < 10; i++)
            count[i] += count[i - 1];

        for (int i = size - 1; ++count_compare && i >= 0; i--) {
            output[count[(array[i] / exp) % 10] - 1] = array[i];
            count[(array[i] / exp) % 10]--;
        }

        for (int i = 0; ++count_compare && i < size; i++)
            array[i] = output[i];

        delete[] output;
        output = NULL;
    }

    int FindMax(int* start, int* end, ull &count_compare) {
        int max_element = *start;

        for (int* p = start + 1; ++count_compare && p != end; p++) {
            if (max_element < *p) {
                max_element = *p;
            }
        }

        return max_element;
    }

protected:
    void Handle(ull &count_compare) {
        int maxVal = FindMax(array, array + size, count_compare);

        for (int exp = 1; ++count_compare && maxVal / exp > 0; exp *= 10)
            countingSort(exp, count_compare);
    }

public:
    using Sort::Sort;
};

#endif