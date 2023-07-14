#ifndef SHELLSORT
#define SHELLSORT

#include "Sort.cpp"

class ShellSort : public Sort {
private:
    

protected:
    void Handle(int &count_compare) {
        for (int gap = size/2; ++count_compare && gap > 0; gap = gap/2)
        {
            for (int i = gap; ++count_compare && i < size; i++)
            {
                int temp = array[i];
                int j;
                for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
                {
                    array[j] = array[j - gap];
                    count_compare += 2;
                }
                array[j] = temp;
            }
            
        }
        
    }
public:
    using Sort::Sort;
};

#endif