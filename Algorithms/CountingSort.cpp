#ifndef COUNTINGSORT
#define COUNTINGSORT

#include "Sort.cpp"

class CountingSort : public Sort {
private:
    int FindMax(int* start, int* end) {
        int max_element = *start;

        for (int* p = start + 1; p != end; p++) {
            if (max_element < *p) {
                max_element = *p;
            }
        }

        return max_element;
    }

    int FindMin(int* start, int* end) {
        int min_element = *start;

        for (int* p = start + 1; p != end; p++) {
            if (min_element > *p) {
                min_element = *p;
            }
        }

        return min_element;
    }

protected:
    void Handle(int &count_compare) {
        int max_value = this->FindMax(array, array + size); count_compare += 2 * size;
        int min_value = this->FindMin(array, array + size); count_compare += 2 * size;
        int range = max_value - min_value + 1;

        int* count = new int[range]();
        int* output = new int[size];

        for (int i = 0; ++count_compare && i < size; i++) {
            count[array[i] - min_value]++;
        }

        for (int i = 1; ++count_compare && i < range; i++) {
            count[i] += count[i - 1];
        }

        for (int i = size - 1; ++count_compare && i >= 0; i--) {
            output[count[array[i] - min_value] - 1] = array[i];
            count[array[i] - min_value]--;
        }

        for (int i = 0; ++count_compare && i < size; i++) {
            array[i] = output[i];
        }

        delete[] count;
        delete[] output;
    }
public:
    using Sort::Sort;
};

#endif