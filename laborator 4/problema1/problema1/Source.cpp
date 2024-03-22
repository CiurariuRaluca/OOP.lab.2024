#include "Sort.h"
#include <stdio.h> 
#include <stdlib.h>

int main()
{
	int m[] = { 2,3,4,5 };
	Sort a(10, 77, 34);
	Sort b(m, 4);
	Sort c(4, 3, 4, 5, 6);
	Sort d("23,4,5,5,6");
	Sort e;
	a.Print();
	b.Print();
	c.Print();
	d.Print();
	e.Print();
	printf("%d\n", a.GetElementsCount());
	printf("%d\n", a.GetElementFromIndex(4));
	d.BubbleSort(true);
	d.Print();
	d.InsertSort(false);
	d.Print();
	d.QuickSort();
	d.Print();
}