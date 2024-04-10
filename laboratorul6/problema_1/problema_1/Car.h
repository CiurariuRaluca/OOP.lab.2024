#pragma once
#include "GlobalFunctions.h"

class Car
{
protected:
	char* name;
	int fuel_consumption;
	int fuel_capacity;
	int speed[3];
	float time;
	bool finish;

public:
	virtual void CalculateTime(int,int) = 0;
	virtual bool GetFinished() = 0;
	virtual int GetSpeed(int w) = 0;
	virtual float GetTime() = 0;
	virtual char* GetName() = 0;


};
