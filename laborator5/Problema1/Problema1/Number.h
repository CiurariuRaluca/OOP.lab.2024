#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>


class Number
{
	char* valoare;
	int baza;
	int lungime;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int x);
	~Number();

	// add operators and copy/move constructor
	Number(Number& d);//copy const
	Number(Number&& e);//move constu
	Number friend operator +(Number a,Number b);
	Number friend operator-(Number c, Number d);
	int operator>(Number);
	int operator<(Number);
	int operator<=(Number);
	int operator>=(Number);
	int operator==(Number);
	int operator!=(Number);
	char operator[](int m);
	Number& operator= (Number);
	Number& operator=(const char*);
	Number& operator=(int);
	Number& operator+=(Number);
	Number& operator--();//pre
	Number& operator--(int x);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
	

};
