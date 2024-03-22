#include "Sort.h"
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>

Sort::Sort(int NumarElemente, int ElementMaxim, int ElementMinim)
{
	this->count = NumarElemente;
	v = new int[this->count + 1];
	time_t a;
	srand((unsigned)(time(&a)));

	for (int i = 0; i < NumarElemente; i++)
	  v[i]= ElementMinim + rand() % (ElementMaxim - ElementMinim + 1);
}
Sort::Sort(int* vec, int NumarElemente)
{
	this->count = NumarElemente;
	v = new int[this->count + 1];
	for (int i = 0; i < this->count; i++)
		v[i] = vec[i];

}

Sort::Sort(int count, ...)
{
	this->count = count;

	va_list vl;

	va_start(vl, count);

	v = new int[this->count + 1];

	for (int i = 0; i < this->count; i++)
	{
		v[i] = va_arg(vl, int);
	}
	va_end(vl);
}

Sort::Sort( const char* s)
{
	int rez = 0,nr=1,k=0;

	for (int i = 0; s[i] != '\0'; i++)
	{ 
		if (s[i] == ',')
			nr++;
	}

	this -> count = nr;
	v = new int[this->count+ 1];

	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != ',')
		{
			rez = rez*10 + ( s[i ] - '0' );
		}
		if (s[i] == ',')
		{
			v[k++] = rez;
			rez = 0;
		}
	}
	v[k++] = rez;
}

Sort::Sort() : v(new int[6] {1, 2, 3, 4, 5, 6})
{
	this->count = 6;

}

void Sort::InsertSort(bool  ascendent)
{
	int p;
	for (int i = 1; i < this->count; i++)
	{
		p = i;
		while ( p>0 && this->v[p] > this->v[p - 1] && !ascendent ||
			           this->v[p] < this->v[p - 1] && ascendent )
		{
			int aux = this->v[p];
			this->v[p] = this->v[p -1];
			this->v[p - 1] = aux;
			p--;
		}
	}
}
void Sort::BubbleSort(bool ascendent)
{
	bool ok = true;
	while (ok)
	{
		ok = false;
		for (int i = 0; i < this->count-1; i++)
		{  
			if ( ascendent && this->v[i] > this->v[i + 1] ||
				!ascendent && this->v[i] < this->v[i+1])
			{
				int aux = this->v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				ok = true;
			}
		}
	}
}
void SortareQuick(int *vec, int st, int dr,bool ascendent)
{
	if (st < dr)
	{
		int mij = (st + dr) / 2;
		int aux = vec[st];
		vec[st] = vec[mij];
		vec[mij] = aux;

		int i = st, j = dr, d = 0;
		while (i < j)
		{
			if (vec[i] > vec[j] && ascendent || vec[i] < vec[j] && !ascendent)
			{
				int a = vec[i];
				vec[i] = vec[j];
				vec[j] = a;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}

		SortareQuick(vec, st, i - 1,ascendent);
		SortareQuick(vec, i + 1, dr ,ascendent);
	}

}
void Sort::QuickSort()
{

	int st = 0;
	int dr = this->count-1;
	bool ascendent = false;
	SortareQuick(this->v, st, dr, ascendent);
}

int Sort::GetElementFromIndex(int index)
{
	return this->v[index];
}

int Sort::GetElementsCount()
{
	return this->count;
}
void Sort::Print()
{
	for (int i = 0; i < this->count; i++)
		printf("%d ", v[i]);
	printf("\n");
}