#include "RangeRover.h"

RangeRover::RangeRover()
{	
	this->name = new char[12];
	strcpy(this->name, "RangeRover");
	this->fuel_consumption = 50;
	this->fuel_capacity = 22;
	speed[0] = 170;
	speed[1] = 145;
	speed[2] = 120;


}

void RangeRover::CalculateTime( int leng, int w)
{
	this->finish = Final(leng,this->speed[w], this->fuel_consumption, this->fuel_capacity);
	if (this->finish)
		this->time =(1.0)*leng / this->speed[w];
}
bool RangeRover::GetFinished()
{
	return this->finish;
}
int RangeRover::GetSpeed(int w)
{
	return this->speed[w];
}
float RangeRover::GetTime()
{
	return this->time;
}
char* RangeRover::GetName()
{
	return this->name;
}