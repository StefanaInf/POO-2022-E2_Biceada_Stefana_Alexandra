#pragma once
#include "Car.h"
class Toyota : public Car
{
public:
	Toyota(); //constructor
	float CarRace(bool& y, int, int) override;
	char* GetName() override;
};

