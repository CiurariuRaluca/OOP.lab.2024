#define _CRT_SECURE_NO_WARNINGS
#include "Circuit.h"
#include <stdio.h>

Circuit::Circuit()
{
	this->count = 0;
}

void Circuit::SetLength(int a)
{
	this->length = a;
}
void Circuit::SetWeather(int b)
{
	this->weather = b;
}
void Circuit::AddCar(Car* a)
{ 
	this->cars[this->count] = a;
	this-> count++;
}
void BubbleSort(Car*cars[10], int n)
{
	bool ok = true;
	
	while (ok)
	{
		ok = false;
		for (int i = 0; i < n - 1; i++)
		{
			if (cars[i]->GetTime() > cars[i + 1]->GetTime())
			{
				Car* aux;
				aux = cars[i];
				cars[i] = cars[i + 1];
				cars[i + 1] = aux;
				ok = true;
			}
		}
	}
}
void Circuit::Race()
{
	for (int i = 0; i < this->count; i++)
	{	 
		this->cars[i]->CalculateTime(this->length, this->weather);
	}
	BubbleSort(this->cars, this->count);
}
void Circuit::ShowFinalRanks()
{
	for (int i = 0; i < this->count; i++)
		if (this->cars[i]->GetFinished())
	{
		printf("%s ",cars[i]->GetName());
	}
	printf("\n");
}
void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0; i < this->count; i++)
	{
		if (!this->cars[i]->GetFinished())
			printf("%s ", this->cars[i]->GetName());
	}
}