#include "Volvo.h"

Volvo::Volvo()
{   
	this->name = new char[10];
    strcpy(this->name, "Volvo");
	this->fuel_consumption = 44;
	this->fuel_capacity = 23;
	speed[0] = 200;
	speed[1] = 180;
	speed[2] = 140;

}

void Volvo::CalculateTime(int leng, int w)
{
	this->finish = Final(leng,this->speed[w], this->fuel_consumption, this->fuel_capacity);
	if (this->finish)
		this->time = (1.0)*leng / this->speed[w];

}
bool Volvo::GetFinished()
{
	return this->finish;
}
int Volvo::GetSpeed(int w)
{
	return this->speed[w];
}
float Volvo::GetTime()
{
	return this->time;
}
char* Volvo::GetName()
{
	return this->name;
}
