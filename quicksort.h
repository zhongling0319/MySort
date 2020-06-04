#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
using namespace std;

class QuickSort
{
public:
    QuickSort();
    void quickSort(vector<int>& nums, int lo, int hi);
};

#endif // QUICKSORT_H
