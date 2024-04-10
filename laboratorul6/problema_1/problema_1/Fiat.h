#pragma once
#include "Car.h"
class Fiat :public Car
{
public:
	Fiat();
	void CalculateTime(int,int)override;
	bool GetFinished()override;
	int GetSpeed(int w)override;
	float GetTime()override;
	char* GetName()override;
};

