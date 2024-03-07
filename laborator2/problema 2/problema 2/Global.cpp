#include "Global.h"
#include<cstring>

int comparareNume(student* s1, student* s2)
{
	char a[20], b[20];

	s1->getName(a);
	s2->getName(b);
   
	return strcmp(a, b);

}
int comparareMate(student* s1, student* s2)
{
	float a,b;

	a=s1->getMate();
	b=s2->getMate();

	if (a == b) return 0;
	else if (a > b)return 1;
	else return -1;

}
int comparareEngleza(student* s1, student* s2)
{
	float a, b;

	a = s1->getEngleza();
	b = s2->getEngleza();

	if (a == b) return 0;
	else if (a > b) return 1;
	else return -1;
}

int comparareIstorie(student* s1, student* s2)
{
	float a, b;

	a = s1->getIstorie();
	b = s2->getIstorie();

	if (a == b) return 0;
	else if (a > b) return 1;
	else return -1;
}
int comparareMedie(student* s1, student* s2)
{
	float a, b;

	a = s1->medie();
	b = s2->medie();

	if (a == b) return 0;
	else if (a > b) return 1;
	else return -1;

}