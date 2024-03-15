#include "Math.h"
#include<cstring>


int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

double Math::Add(double a, double b)
{
	return a + b;
}
double Math::Add(double a, double b, double c)
{
	return a + b + c;
}
int Math::Mul(int a, int b)
{
	return a * b;
}
int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}
double Math::Mul(double a, double b)
{
	return a * b;
}
double Math::Mul(double a, double b, double c)
{
	return a * b * c;
}
int Math::Add(int count, ...)
{
	int suma=0;
	va_list vl;
	va_start(vl, count);

	for (int i = 0; i < count; i++)
		suma += va_arg(vl, int);
	va_end(vl);
	return suma;
}

char* Math::Add(const char* sir1, const char* sir2)
{
	if (sir1 == nullptr || sir2 == nullptr)
			return nullptr;
	
	int maxim = strlen(sir1);
	int lung = strlen(sir2);

	if (lung > maxim)
		maxim = lung;

	char* rez = new char[maxim+1];
	rez[maxim+1] = '\0';
	
	for(int j=0;j<=maxim;j++)
		rez[j]='a';


	int lung2 = strlen(sir2) - 1;
	int lung1 = strlen(sir1) - 1;

	int carry = 0, suma = 0;

	while (lung1 >= 0 && lung2 >= 0)
	{
		suma = sir1[lung1] - '0' + sir2[lung2] - '0' + carry;

		carry = suma / 10;
		suma = suma % 10;

		rez[maxim--] = suma + '0';

		lung1--; lung2--;
	}

	while (lung1 >= 0)
	{
		suma = sir1[lung1] - '0' + carry;

		carry = suma / 10;
		suma = suma % 10;

		rez[maxim--] = suma + '0';

		lung1--;

	}
	while (lung2 >= 0)
	{

		suma = sir2[lung2] - '0' + carry;

		carry = suma / 10;
		suma = suma % 10;

		rez[maxim--] = suma + '0';

		lung2--;
	}
	rez[0]=carry+'0';

	if(rez[0]=='a')
		strcpy(rez,rez+1);
	return rez;
}
