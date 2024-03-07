#include<stdio.h>
#include<iostream>
#include "NumberList.h"

using namespace std;

int main()
{
	NumberList m;
	m.Init();
	m.Add(3);
	m.Add(4);
	m.Add(0);
	m.Sort();
	m.Print();


	return 0;

}