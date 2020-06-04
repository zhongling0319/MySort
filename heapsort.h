#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>
using namespace std;

class HeapSort
{
public:
    HeapSort();
    void heapSort(vector<int>& nums);
    void heapAdjust(vector<int>& nums, int i, int n);
};

#endif // HEAPSORT_H
