#pragma once
#include "Car.h"

class BMW :public Car
{
public:
	BMW ();
	void CalculateTime(int,int)override;
	bool GetFinished()override;
	int GetSpeed(int w)override;
	float GetTime()override;
	char*GetName()override;
};

