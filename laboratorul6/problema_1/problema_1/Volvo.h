#pragma once
#include "Car.h"

class Volvo: public Car
{
public:
	Volvo();
	void CalculateTime(int,int)override;
	bool GetFinished()override;
	int GetSpeed(int w)override;
	float GetTime()override;
	char* GetName()override;
};

