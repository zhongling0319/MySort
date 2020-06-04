#ifndef MERGESORT_H
#define MERGESORT_H
#include <vector>
using namespace std;

class MergeSort
{
public:
    MergeSort();
    void mergeSort(vector<int>& nums, int left, int right);
    void merge(vector<int>& nums, int left, int mid, int right);
};

#endif // MERGESORT_H
