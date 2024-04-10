#include "Fiat.h"


Fiat::Fiat()
{   
	this->name = new char[10];
	strcpy(this->name, "Fiat");
	this->fuel_consumption = 17;
	this->fuel_capacity = 11;
	speed[0] = 120;
	speed[1] = 110;
	speed[2] = 90;
}

void Fiat::CalculateTime(int leng, int w)
{
	this->finish = Final(leng,this->speed[w], this->fuel_consumption, this->fuel_capacity);
	if (this->finish)
		this->time = (1.0)*leng / this->speed[w];
}
bool Fiat::GetFinished()
{
	return this->finish;
}
int Fiat:: GetSpeed(int w)
{
	return this->speed[w];
}

float Fiat::GetTime()
{
	return this->time;
}
char* Fiat::GetName()
{
	return this->name;
}