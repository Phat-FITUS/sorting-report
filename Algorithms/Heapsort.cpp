#ifndef HEAPSORT
#define HEAPSORT

#include "Sort.cpp"

class HeapSort : public Sort {
private:
    
void MaxHeapify(int*& array, int size, int i, int& count_compare)
{
	int left = 2*i + 1;
	int right = 2*i + 2;
	int largest;
	if (left < size && array[left] > array[i])
	{
		count_compare = count_compare + 2;
		largest = left;
	}
	else largest = i;
	if (right < size && array[right] > array[largest])
	{
		count_compare = count_compare + 2;
		largest = right;	
	}
	if (largest != i)
	{
		++count_compare;
		swap(array[i], array[largest]);
		MaxHeapify(array, size, largest, count_compare);
	}
}

void Heapsort(int*& array, int size, int& count_compare)
{
	for (int i = size/2; ++count_compare && i >= 0; i--)
	{
		MaxHeapify(array, size, i, count_compare);	
	}		
	for (int i = size - 1; ++count_compare && i > 0; i--)
	{
		swap(array[0], array[i]);
		MaxHeapify(array, i, 0, count_compare);
	}
}

protected:
    void Handle(int &count_compare) {
       Heapsort(array, size, count_compare);
    }
public:
    using Sort::Sort;
};

#endif
