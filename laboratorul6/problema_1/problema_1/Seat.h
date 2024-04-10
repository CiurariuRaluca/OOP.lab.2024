#pragma once
#include "Car.h"
class Seat:public Car
{
public:
	Seat();
	void CalculateTime(int,int)override;
	bool GetFinished() override;
	int GetSpeed(int w)override;
	float GetTime()override;
	char* GetName()override;
};

