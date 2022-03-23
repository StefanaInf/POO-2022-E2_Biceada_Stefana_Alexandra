#pragma once
class Sort
{
    int number;
    int* vector;
public:
    Sort(int number_elements, int min_element, int max_element);
    Sort(int* elemente, int number_elements);
    Sort(int count, ...);
    Sort(char* s);
    Sort();
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent, int low, int high);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};