#ifndef FLASHSORT
#define FLASHSORT

#include "Sort.cpp"

class FlashSort : public Sort {
    private:
        void InsertionSort(int &countCompare) {
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
        void Handle(int &countCompare) {
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
            int t = 0;
            int flash;

            while (++countCompare && nmove < size - 1)
            {
                while (++countCompare && j > l[k] - 1)
                {
                    j++;
                    k = int(c1*(array[j] - minVal));
                }
                flash = array[j];

                if (++countCompare && k < 0) break;

                while (++countCompare && j != l[k])
                {
                    k = int(c1*(flash - minVal));
                    int hold = array[t = --l[k]];
                    array[t] = flash;
                    flash = hold;
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