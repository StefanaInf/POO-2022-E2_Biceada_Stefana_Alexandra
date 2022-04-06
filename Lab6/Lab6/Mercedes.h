#pragma once
#include "Car.h"
class Mercedes : public Car
{
public:
	Mercedes(); //constructor
	float CarRace(bool& y, int, int) override;
	char* GetName() override;
};

