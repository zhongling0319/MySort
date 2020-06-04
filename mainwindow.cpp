#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QTime>
#include <QString>
#include <algorithm>
#include <iostream>
#include "mergesort.h"
#include "quicksort.h"
#include "heapsort.h"
#include <QtCore/qmath.h>

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击开始进行
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        //获取数量
        int n = ui->lineEdit->text().toInt();
        //生成随机数组
        m_num.resize(n);
        qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
        for (int i = 0; i < n; i++) {
            m_num[i] = qrand()%1000;
        }
        //设置时钟
        QTime time;

        //选择排序
        time.start();
        selectionSort();
        ui->sort_1->setText(QString::number(time.elapsed()));
        random_shuffle(m_num.begin(), m_num.end());

//        for (int& num : m_num)   cout << num << " ";
//        cout << endl;

        //插入排序
        time.start();
        insertionSort();
        ui->sort_2->setText(QString::number(time.elapsed()));
        random_shuffle(m_num.begin(), m_num.end());

        //冒泡排序
        time.start();
        bubbleSort();
        ui->sort_3->setText(QString::number(time.elapsed()));
        random_shuffle(m_num.begin(), m_num.end());

        //希尔排序
        time.start();
        shellSort();
        ui->sort_4->setText(QString::number(time.elapsed()));
        random_shuffle(m_num.begin(), m_num.end());

        //归并排序
        time.start();
        mergeSort();
        ui->sort_5->setText(QString::number(time.elapsed()));
        random_shuffle(m_num.begin(), m_num.end());

        //快速排序
        time.start();
        quickSort();
        ui->sort_6->setText(QString::number(time.elapsed()));
        random_shuffle(m_num.begin(), m_num.end());

        //堆排序
        time.start();
        heapSort();
        ui->sort_7->setText(QString::number(time.elapsed()));
        random_shuffle(m_num.begin(), m_num.end());

        //桶排序
        time.start();
        bucketSort();
        ui->sort_8->setText(QString::number(time.elapsed()));
        random_shuffle(m_num.begin(), m_num.end());

        //计数排序
        time.start();
        countSort();
        ui->sort_9->setText(QString::number(time.elapsed()));
        random_shuffle(m_num.begin(), m_num.end());

        //基数排序
        time.start();
        radixSort();
        ui->sort_10->setText(QString::number(time.elapsed()));
//        random_shuffle(m_num.begin(), m_num.end());

    });
}

void MainWindow::quickSort()
{
    //选取一个基准数，依次从右往左、从左往右找，将小于基准数的填在左边，大于等于基准数的填在右边
    QuickSort qs;
    qs.quickSort(m_num, 0, m_num.size() - 1);
    cout << "quick sort:" << endl;
    for (int& num : m_num)   cout << num << " ";
    cout << endl;
}

void MainWindow::insertionSort()
{
    //将第i个数插入到前面排好的数中合适的位置，插入过程中，插入位置后面的数逐个后移
    int n = m_num.size();
    for (int i = 1; i < n; i++) {
        int k = i - 1;
        int temp = m_num[i];
        while (k >=0 && m_num[k] > temp) {
            k--;
        }
        k++;
        for (int j = i; j > k; j--) {
            m_num[j] = m_num[j - 1];
        }
        m_num[k] = temp;
    }
    cout << "insertion sort:" << endl;
    for (int& num : m_num)   cout << num << " ";
    cout << endl;
}

void MainWindow::bubbleSort()
{
    //通过两两比较，依次将最大的数移到最后
    int n = m_num.size();
    bool flag;
    for (int i = n - 1; i > 0; i--) {
        flag = true;    //对冒泡算法的优化，如果这一轮没有交换，说明已经排好序了
        for (int j = 0; j < i; j++) {
            if (m_num[j] > m_num[j + 1]) {
                flag = false;
                swap(m_num[j], m_num[j+1]);
            }
        }
        if (flag) break;
    }
    cout << "bubble sort:" << endl;
    for (int& num : m_num)   cout << num << " ";
    cout << endl;
}

void MainWindow::selectionSort()
{
    //从剩余数中选择最大值与最末数交换
    int n = m_num.size();
    for (int i = 0; i < n - 1; i++) {
        int iMin = i;
        for (int j = i + 1; j < n; j++) {
            if (m_num[j] < m_num[iMin]) {
                iMin = j;
            }
        }
        swap(m_num[i], m_num[iMin]);
    }
    cout << "selection sort:" << endl;
    for (int& num : m_num)   cout << num << " ";
    cout << endl;
}

void MainWindow::heapSort()
{
    //利用大根堆，不断将最大值交换到最末端
    HeapSort hs;
    hs.heapSort(m_num);
    cout << "heap sort:" << endl;
    for (int& num : m_num)   cout << num << " ";
    cout << endl;
}

void MainWindow::shellSort()
{
    //插入排序的改进，分组+插入排序，逐渐细化分组至1个组
    int n = m_num.size();
    for (int h = n/2; h > 0; h /= 2) {
        for (int i = h; i < n; i++) {
            int temp = m_num[i];
            int k;
            for (k = i - h; k >= 0 && m_num[k] > temp; k -= h) {
                m_num[k + h] = m_num[k];
            }
            m_num[k + h] = temp;
        }
    }
    cout << "shell sort:" << endl;
    for (int& num : m_num)   cout << num << " ";
    cout << endl;
}

void MainWindow::mergeSort()
{
    //两个有序合并
    MergeSort ms;
    ms.mergeSort(m_num, 0, m_num.size() - 1);
    cout << "merge sort:" << endl;
    for (int& num : m_num)   cout << num << " ";
    cout << endl;
}

void MainWindow::bucketSort()
{
    //计数排序改进版，获取最大最小值，按一定间隔划分桶，桶内排序
    int n = m_num.size();
    if (n > 0) {
        int min = m_num[0];
        int max = m_num[0];
        for (int i = 0; i < n; i++) {
            min = min <= m_num[i]? min: m_num[i];
            max = max >= m_num[i]? max: m_num[i];
        }
        int delta = 10;
        int bucketSize = (max - min)/delta + 1;
        vector<vector<int>> buckets(bucketSize, vector<int>(0));
        for (int i = 0; i < n; i++) {
            buckets[(m_num[i]-min)/delta].push_back(m_num[i]);
        }
        QuickSort qs;
        for (int i = 0; i < bucketSize; i++) {
            qs.quickSort(buckets[i], 0, buckets[i].size() - 1);
        }
        int index = 0;
        for (int i = 0; i < bucketSize; i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                m_num[index] = buckets[i][j];
                index++;
            }
        }
    }
    cout << "bucket sort:" << endl;
    for (int& num : m_num)   cout << num << " ";
    cout << endl;
}

void MainWindow::countSort()
{
    //计数排序，获取数列中最大最小值，开辟辅助数组，对每个值计数
    int n = m_num.size();
    if (n > 0) {
        int min = m_num[0];
        int max = m_num[0];
        for (int i = 0; i < n; i++) {
            min = min <= m_num[i]? min: m_num[i];
            max = max >= m_num[i]? max: m_num[i];
        }
        int size = max - min + 1;
        vector<int> countVec(size, 0);
        for (int i = 0; i < n; i++) {
            countVec[m_num[i] - min]++;
        }
        int index = 0;
        for (int i = 0; i < size; i++) {
            while (countVec[i] > 0) {
                m_num[index] = i + min;
                index++;
                countVec[i]--;
            }
        }
    }
    cout << "count sort:" << endl;
    for (int& num : m_num)   cout << num << " ";
    cout << endl;
}

void MainWindow::radixSort()
{
    //基数排序，确定最大数的位数，从低位开始，按位进行桶排序，直到最高位
    int n = m_num.size();
    if (n > 0) {
        int max = m_num[0];
        for (int i = 0; i < n; i++) {
            max = max >= m_num[i]? max : m_num[i];
        }
        int num = 0;
        while (max > 0) {
            max /= 10;
            num++;
        }
        vector<vector<int>> buckets(10, vector<int>(0));
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < n; j++) {
                buckets[m_num[j]/(static_cast<int>(qPow(10.0, i)))%10].push_back(m_num[j]);
            }
            int index = 0;
            for (int j = 0; j < buckets.size(); j++) {
                for (int k = 0; k < buckets[j].size(); k++) {
                    m_num[index++] = buckets[j][k];
                }
                buckets[j].clear();
            }
        }
    }
    cout << "radix sort:" << endl;
    for (int& num : m_num)   cout << num << " ";
    cout << endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}
