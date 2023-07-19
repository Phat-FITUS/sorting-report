#ifndef BUBBLESORT
#define BUBBLESORT

#include "Sort.cpp"

class BubbleSort : public Sort {
protected:
    void Handle(ull &count_compare) {
        for (int  i = 0; ++count_compare && i < size - 1; i++)
        {
       		for (int j = 0; ++count_compare && j < size - 1 - i; j++)
       		{
       			if (++count_compare && array[j + 1]  < array[j])
       			{
       				swap(array[j+1], array[j]);
				}
			}
	    }
    }
public:
    using Sort::Sort;
};

#endif
