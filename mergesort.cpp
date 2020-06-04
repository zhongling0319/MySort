#include "mergesort.h"


MergeSort::MergeSort()
{
}

void MergeSort::mergeSort(vector<int>& nums, int left, int right)
{
    if (left >= right) return;
    int mid = (left + right)/2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

void MergeSort::merge(vector<int>& nums, int left, int mid, int right)
{
    vector<int> temp;
    temp.clear();
    int i = left;
    int j = mid + 1;
    for (; i <= mid && j <= right; ) {
        if (nums[i] < nums[j]) {
            temp.push_back(nums[i]);
            i++;
        }
        else {
            temp.push_back(nums[j]);
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(nums[i++]);
    }
    while (j <= right) {
        temp.push_back(nums[j++]);
    }
    for (int num : temp) {
        nums[left] = num;
        left++;
    }
}
