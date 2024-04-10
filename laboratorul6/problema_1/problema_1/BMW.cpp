#include "BMW.h"

BMW::BMW( )
{   
	this->name = new char[10];
	strcpy(this->name, "BMW");
	this->fuel_consumption = 10;
	this->fuel_capacity = 60;
	speed[0] = 210;
	speed[1] = 190;
	speed[2] = 160;
	
}

void BMW::CalculateTime(int leng,int w)
{
	this->finish = Final(leng,this->speed[w],this->fuel_consumption,this->fuel_capacity);
	if (this->finish)
		this->time = (1.0) * leng / this->speed[w];

}
bool BMW::GetFinished()
{
	return this->finish;
}
int BMW::GetSpeed(int w)
{
	return this->speed[w];
}
float BMW::GetTime()
{
	return this->time;
}
char* BMW::GetName()
{
	return this->name;
}
