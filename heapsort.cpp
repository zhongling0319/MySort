#include "heapsort.h"


HeapSort::HeapSort()
{
}

void HeapSort::heapSort(vector<int>& nums)
{
    int n = nums.size();
    //构建堆：从最后一个非叶子节点开始，逐个调整
    for (int i = (n - 1)/2; i >= 0; i--) {
        heapAdjust(nums, i, n);
    }
    //每次从堆顶取最大值放在最末
    for (int j = n - 1; j > 0; j--) {
        swap(nums[0], nums[j]);
        heapAdjust(nums, 0, j);
    }
}

void HeapSort::heapAdjust(vector<int>& nums, int i, int n)
{
    if (2*i + 1 > n - 1) {
        return;
    }//没有子节点，不用调整
    int leftChild = 2*i + 1;
    int rightChile = 2*i + 2;
    int max = i;
    if (leftChild < n && nums[leftChild] > nums[max]) {
        max = leftChild;
    }
    if (rightChile < n && nums[rightChile] > nums[max]) {
        max = rightChile;
    }
    if (max != i) {
        swap(nums[i], nums[max]);
        heapAdjust(nums, max, n);
    }
}
