#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include <cstring>

void student::setMate(float a)
{
	this->mate = a;
}
float student::getMate()
{
	return this->mate;
}
void student::setEngleza(float b)
{
	this->engleza = b;
}
float student::getEngleza()
{
	return this->engleza;
}
void student::setIstorie(float c)
{
	this->istorie = c;
}
float student::getIstorie()
{
	return this->istorie;
}
void student::setName(char a[20])
{
	strcpy(this->nume, a);
}
void student::getName(char a[20])
{
	strcpy(a, this->nume);

}
float student::medie()
{
	return (this->mate + this->engleza + this->istorie) / 3;
}