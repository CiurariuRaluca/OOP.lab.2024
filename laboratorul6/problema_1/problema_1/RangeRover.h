#pragma once
#include "Car.h"
class RangeRover :public Car
{
public:
	RangeRover( );
	void CalculateTime(int,int)override;
	bool GetFinished()override;
	int GetSpeed(int w)override;
	float GetTime()override;
	char* GetName()override;
}; 

