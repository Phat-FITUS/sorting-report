#ifndef QUICKSORT
#define QUICKSORT

#include "Sort.cpp"

class QuickSort : public Sort {
    private:
        int Partition(int left, int right, int &countCompare) {
            int l = left, r = right-1, pivot=right;

            while(++countCompare && l <= r) {
                while(++countCompare && array[l] < array[pivot] && l <= r) l++;
                while(++countCompare && array[r] > array[pivot] && l <=r) r--;
                if(l <= r) {
                    countCompare++;
                    swap(array[l], array[r]);
                    l++;
                    r--;
                }
            }

            swap(array[l], array[pivot]);

            return l;
        }

        void q_sort(int left, int right, int &countCompare) {
            if(++countCompare && left >= right) return;
            int pivot = Partition(left, right,countCompare);
            q_sort(left,pivot-1,countCompare);
            q_sort(pivot+1,right, countCompare);
        }

    protected:
        void Handle(int &countCompare) {
            q_sort(0,size-1,countCompare);
        }
        
    public:
        using Sort::Sort;
};

#endif