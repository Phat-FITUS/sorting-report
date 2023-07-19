#ifndef HEAPSORT
#define HEAPSORT

#include "Sort.cpp"

class HeapSort : public Sort {
private:
	void MaxHeapify(int i, ull& count_compare)
	{
		int left = 2*i + 1;
		int right = 2*i + 2;
		int largest;

		if (++count_compare && left < size && ++count_compare && array[left] > array[i])
		{
			largest = left;
		}
		else largest = i;

		if (++count_compare && right < size && ++count_compare && array[right] > array[largest])
		{
			largest = right;
		}

		if (++count_compare && largest != i)
		{
			swap(array[i], array[largest]);
			MaxHeapify(largest, count_compare);
		}
	}

protected:
    void Handle(ull &count_compare) {
       for (int i = size/2; ++count_compare && i >= 0; i--)
		{
			MaxHeapify(i, count_compare);
		}

		for (int i = size - 1; ++count_compare && i > 0; i--)
		{
			swap(array[0], array[i]);
			MaxHeapify(0, count_compare);
		}
    }

public:
    using Sort::Sort;
};

#endif
