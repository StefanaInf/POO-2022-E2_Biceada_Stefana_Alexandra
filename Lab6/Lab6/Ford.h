#pragma once
#include "Car.h"
class Ford : public Car
{
public:
	Ford(); //constructor
	float CarRace(bool& y, int, int) override;
	char* GetName() override;
};

