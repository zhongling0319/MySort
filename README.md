# MySort
本程序实现了十大排序算法速度比较，采用QT制作简单的界面，输入要排序的数量，计算各排序算法所用时间。

![MySort界面截图](https://image-1301378304.cos.ap-nanjing.myqcloud.com/MySort%E7%95%8C%E9%9D%A2%E6%88%AA%E5%9B%BE.png)

### 十大排序算法思想简述

- **插入排序**：从第二个元素开始，向前插入到有序数组中，插入的过程是依次与前面的数比较，若小于则该数后移，直到插入到合适位置
- **希尔排序**：插入排序的改进，按照一定间隔将数组分为若干子序列，分别进行插入排序，得到部分有序的数组，然后缩短间隔，继续插入排序，直到间隔为1。间隔序列可以为k=n/2; k>0; k/=2，进行插入排序时轮流对各子序列插入，而不是排完一个序列再排下一个
- **归并排序**：分治法，将数组拆成两个子序列，分别归并排序后将两者合并，递归。
- **冒泡排序**：两两比较，将较大的数交换到最后。以此循环，不断将大数交换到最后
- **快速排序**：取某个数为基准数（一般取第一个数，如果取其他位的数，要交换到第一个位置），用双指针分别从后往前，从前往后，将小于等于基准数的交换到前面，大于基准数的交换到后面，最后把基准数放在指针重合的位置，则基准数前都小于等于，基准数后都大于基准数。递归的对基准数前和后的数组进行排序。由于不会出现重复的比较，因此快排的效率比较好。
- **选择排序**：每次循环，从剩余数组中找出最小的数与剩余数组的首位交换
- **堆排序**：将数组构建成堆，每次循环，利用大根堆的性质，取堆顶元素与最后一个元素交换，剩余数组再进行堆调整。（建立堆的时间复杂度是n，调整与排序的时间复杂度是nlogn）
- **计数排序**：获得最大值和最小值，开辟辅助数组size=max-min+1，遍历数列将元素放入数组对应位置，遍历数组即可完成排序
- **桶排序**：计数排序的改进，获得最大最小值，已某个间隔将其分为若干个桶，开辟辅助数组size=(max-min)/delta+1，遍历数列将元素放入对应的桶中，桶内排序（用其他排序方法），遍历数组取出排序后的元素
- **基数排序**：获取最大值，计算最大值的位数，依次从数的低位到高位，进行计数排序。

### 排序算法性能对比

![排序算法比较](https://image-1301378304.cos.ap-nanjing.myqcloud.com/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95%E6%AF%94%E8%BE%83.jpg)