#pragma once
#include "Weather.h"
#include "Volvo.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "BMW.h"
#include "Seat.h"

class Circuit
{
	int length;
	int weather;
	int count;
	Car* cars[10];
public:
	 Circuit();
	 void SetLength(int);
	 void SetWeather(int);
	 void AddCar(Car*);
	 void Race();
	 void ShowFinalRanks();
	 void ShowWhoDidNotFinish();

};

