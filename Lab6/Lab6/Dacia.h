#pragma once
#include "Car.h"
class Dacia : public Car
{
public:
	Dacia(); //constructor
	float CarRace(bool& y, int, int) override;
	char* GetName() override;
};

