#ifndef SHELLSORT
#define SHELLSORT

#include "Sort.cpp"

class ShellSort : public Sort
{
protected:
    void Handle(int &count_compare)
    {
        for (int gap = size / 2; ++count_compare && gap > 0; gap = gap / 2)
        {
            for (int i = gap; ++count_compare && i < size; i++)
            {
                int temp = array[i];
                int j;

                for (j = i; ++count_compare && j >= gap && ++count_compare && array[j - gap] > temp; j -= gap)
                {
                    array[j] = array[j - gap];
                }

                array[j] = temp;
            }
        }
    }

public:
    using Sort::Sort;
};

#endif