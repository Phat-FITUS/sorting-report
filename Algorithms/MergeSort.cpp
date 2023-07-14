#ifndef MERGESORT
#define MERGESORT

#include "Sort.cpp"

class MergeSort : public Sort {
    private:
        void Merge(int left, int mid, int right, int &countCompare) {
            int subLeftCount = mid - left+1;
            int subRightCount = right - mid;

            int * subLeft = new int[subLeftCount];
            int * subRight = new int[subRightCount];

            for(int i = 0; ++countCompare && i < subLeftCount; i++) subLeft[i] = array[left+i];
            for(int i = 0; ++countCompare && i < subRightCount; i++) subRight[i] = array[mid+1+i];

            int l=0, r=0,i=left;
            while(++countCompare && l < subLeftCount && ++countCompare && r < subRightCount) {
                if(subLeft[l] <= subRight[r]) {
                    array[i] = subLeft[l];
                    l++;
                } else {
                    array[i] = subRight[r];
                    r++;
                }
                countCompare++;
                i++;
            }
            while(++countCompare && l < subLeftCount) {
                array[i] = subLeft[l];
                l++;
                i++;
            } 
            while(++countCompare && r < subRightCount) {
                array[i] = subRight[r];
                r++;
                i++;
            }

            delete[] subLeft;
            delete[] subRight;
        }
        void m_sort(int left, int right, int &countCompare) {
            if(++countCompare && left >= right) return;

            int mid = (left + right)/2;
            m_sort(left, mid,countCompare);
            m_sort(mid+1, right,countCompare);
            Merge(left,mid,right,countCompare);
        }
    protected:
        void Handle(int &countCompare) {
            m_sort(0,size-1,countCompare);
        }
    public:
        using Sort::Sort;
};

#endif