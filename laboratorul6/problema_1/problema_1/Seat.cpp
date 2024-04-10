#include "Seat.h"

Seat::Seat()
{   
	this->name = new char[10];
	strcpy(this->name, "Seat");
	this->fuel_consumption = 33;
	this->fuel_capacity = 12;
	speed[0] = 190;
	speed[1] = 160;
	speed[2] = 130;
}

void Seat::CalculateTime(int leng, int w)
{
	this->finish = Final(leng,this->speed[w], this->fuel_consumption, this->fuel_capacity);
	if (this->finish)
		this->time = (1.0)*leng / this->speed[w];
}
bool Seat::GetFinished()
{
	return this->finish;
}
int Seat::GetSpeed(int w)
{
	return this->speed[w];
}
float Seat::GetTime()
{
	return this->time;
}
char* Seat::GetName()
{
	return this->name;
}