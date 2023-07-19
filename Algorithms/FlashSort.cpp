#ifndef FLASHSORT
#define FLASHSORT

#include "Sort.cpp"

class FlashSort : public Sort {
    private:
        void InsertionSort(ull &countCompare) {
            for (int i = 1; ++countCompare && i < size; i++) {
                int k = i - 1;
                int key = array[i];

                while (++countCompare && array[k] > key && ++countCompare && k >= 0)
                {
                    array[k + 1] = array[k];
                    k--;
                }

                array[k + 1] = key;
            }
        }

    protected:
        void Handle(ull &countCompare) {
            int minVal = array[0];
            int max = 0;
            int m = int(0.45 * size);
            int* l = new int[m];

            for (int i = 0; ++countCompare && i < m; i++)
                l[i] = 0;

            for (int i = 1; ++countCompare && i < size; i++)
            {
                if (++countCompare && array[i] < minVal)
                    minVal = array[i];

                if (++countCompare && array[i] > array[max])
                    max = i;
            }

            if (++countCompare && array[max] == minVal)
                return;

            double c1 = (double)(m - 1) / (array[max] - minVal);

            for (int i = 0; ++countCompare && i < size; i++)
            {
                int k = int(c1 * (array[i] - minVal));
                ++l[k];
            }

            for (int i = 1; ++countCompare && i < m; i++)
                l[i] += l[i - 1];

            swap(array[max], array[0]);
            int nmove = 0;
            int j = 0;
            int k = m - 1;
            int flash;
            int count = 0;
            while (++countCompare && nmove < size - 1)
            {
                while (++countCompare && j > l[k] - 1)
                {
                    j++;
                    k = int(c1*(array[j] - minVal));
                }

                if (++countCompare && k < 0) break;
                flash = j;

                while (++countCompare && j != l[k])
                {
                    k = int(c1*(array[flash] - minVal));
                    swap(array[flash], array[--l[k]]);
                    ++nmove;
                }
            }

            delete[] l;
            InsertionSort(countCompare);
        }

    public:
        using Sort::Sort;
};

#endif