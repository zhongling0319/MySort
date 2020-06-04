#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void quickSort();
    void insertionSort();
    void bubbleSort();
    void selectionSort();
    void heapSort();
    void shellSort();
    void mergeSort();
    void bucketSort();
    void countSort();
    void radixSort();

    
private:
    Ui::MainWindow *ui;
    vector<int> m_num;
};

#endif // MAINWINDOW_H
