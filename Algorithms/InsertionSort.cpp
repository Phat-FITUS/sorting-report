#ifndef INSERTIONSORT
#define INSERTIONSORT

#include "Sort.cpp"

class InsertionSort : public Sort {
private:
    //Other required function here

protected:
    void Handle(int &count_compare) {
        for (int i = 0;++count_compare && i < size; i++)
        {
            int key = array[i];
            int j = i - 1;
            while (++count_compare >= 0 && array[j] > key && j >= 0)
            {
                array[j+1] = array[j];
                j = j - 1;
            }
            array[j+1] = key;
        }
    }
public:
    using Sort::Sort;
};

#endif