#ifndef SELECTIONSORT
#define SELECTIONSORT

#include "Sort.cpp"

class SelectionSort : public Sort
{
protected:
    void Handle(int &count_compare)
    {
        for (size_t i = 0; ++count_compare && i < size - 1; i++)
        {
            int min = i;

            for (int j = i + 1; ++count_compare && j < size; j++)
            {
                if (++count_compare && array[j] < array[min])
                {
                    min = j;
                }
            }

            int temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }

public:
    using Sort::Sort;
};

#endif