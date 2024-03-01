#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int atoi(char* s) {

	int rez = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		rez = rez * 10 + s[i] - '0';
	}
	return rez;
}

int main()
{
	FILE* fp;
	int rezultat = 0;
	
	if (fopen_s(&fp, "in.txt", "r") != 0)
	{
		printf("eroare.nu am putut deschide fisierul\n");
	}
	else
	{
		printf("am deschis fisierul cu succes\n");

		char sir[201];

		while (fgets(sir, 200, fp))
		{
			rezultat += atoi(sir);
		}
	}
	printf("suma este:%d \n", rezultat);

	
	return 0;
}