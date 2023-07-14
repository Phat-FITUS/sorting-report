#ifndef SHAKERSORT
#define SHAKERSORT

#include "Sort.cpp"

class ShakerSort : public Sort {
private:
    //Other required function here

protected:
    void Handle(int &count_compare) {
    	int left  = 0;
		int right = size - 1;
		int flag = 0;
        while (++count_compare && left < right)
	{
		for (int i = left; ++count_compare && i < right; i++)
		{
			if (array[i + 1] < array[i])
			{
				++count_compare;
				swap(array[i+1], array[i]);
				flag = i;
			}
		}
		right = flag;
		for (int i = right; ++count_compare && i > left; i--)
		{
			if (array[i] < array[i - 1])
			{
				++count_compare;
				swap(array[i], array[i - 1]);
				flag = i;
			}
		}
		left = flag;
	}
    }
public:
    using Sort::Sort;
};

#endif
