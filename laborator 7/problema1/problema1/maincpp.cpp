#include <stdio.h>
#include <iostream>

using namespace std;

int operator""_Fahrenheit(unsigned long long int a)
{
	int rez;
	rez= (a * 2)+ 32;
	return rez;
}
int operator""_Kelvin(unsigned long long a)
{
	int rez;
	rez = a + 274;
	return rez;
}
int main()
{
	float b = 120_Fahrenheit;
	float a = 300_Kelvin;
	cout << b << " " << a;

	return 0;
}