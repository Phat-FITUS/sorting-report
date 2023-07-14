#ifndef BUBBLESORT
#define BUBBLESORT

#include "Sort.cpp"

class BubbleSort : public Sort {
private:
    //Other required function here

protected:
    void Handle(int &count_compare) {
        for (int  i = 0; ++count_compare && i < size - 1; i++)
       {
       		for (int j = 0; ++count_compare && j < size - 1 - i; j++)
       		{
       			if (array[j + 1]  < array[j])
       			{
       				++count_compare;
       				swap(array[j+1], array[j]);
				}
			}
	   }
    }
public:
    using Sort::Sort;
};

#endif
