#include "student.h"
#include "Global.h"
#include<stdio.h>

using namespace std;

int main()
{
	student a,b;
	char s[20]="ana";
	char sh[20];

	a.setMate(7.0f);
	a.setEngleza(8.0f);
	a.setIstorie(5.0f);
	a.setName(s);
	a.getName(sh);

	char s2[20]="maria";
	char sh2[20];

	b.setMate(6.0f);
	b.setEngleza(8.0f);
	b.setIstorie(5.0f);
	b.setName(s2);
	b.getName(sh2);
	
	printf("%d ",comparareMate(&a, &b));
	printf("%d ", comparareEngleza(&a, &b));
	printf("%d ", comparareIstorie(&a, &b));
	printf("%d ", comparareMedie(&a, &b));
	printf("%d ", comparareNume(&a, &b));

	return 0;
}
