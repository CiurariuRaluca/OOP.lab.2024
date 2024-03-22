#pragma once
#include "Sort.h"
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>

class Sort
{
    int* v;
    int count;
public:
    Sort(int NumarElemente, int ElementMaxim, int ElementMinim);
    Sort(int* vector, int NumarElemente);
    Sort(int count, ...);
    Sort( const char*);
    Sort();
    void InsertSort(bool ascendent = false);
    void QuickSort();
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
 
};
void SortareQuick(int* v, int st, int dr, bool ascendent);
