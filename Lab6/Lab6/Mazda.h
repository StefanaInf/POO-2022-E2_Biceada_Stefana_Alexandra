#pragma once
#include "Car.h"
class Mazda : public Car
{
public:
	Mazda(); //constructor
	float CarRace(bool& y, int, int) override;
	char* GetName() override;
};

