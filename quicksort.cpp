#include "quicksort.h"

QuickSort::QuickSort()
{
}

void QuickSort::quickSort(vector<int>& nums, int lo, int hi)
{
    if (lo >= hi) return;
    int temp = nums[lo];
    int i = lo;
    int j = hi;
    while (i < j) {
        //从右往左找小于等于temp的
        while (i < j && nums[j] > temp) j--;
        if (i < j) {
            nums[i] = nums[j];
            i++;
        }
        //从左往右找大于temp的
        while (i < j && nums[i] <= temp) i++;
        if (i < j) {
            nums[j] = nums[i];
            j--;
        }
    }
    nums[i] = temp;
    quickSort(nums, lo, i - 1);
    quickSort(nums, i + 1, hi);
}
