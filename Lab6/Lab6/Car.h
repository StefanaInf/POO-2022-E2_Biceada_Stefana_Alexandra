#pragma once
class Car
{
protected:
	int fuelCapacity;
	int fuelConsumtion;
	int averageSpeed[3];
	char* name; //numele masinii
public:
	virtual char* GetName() = 0;
	//CarRace: bool-can the car complete the race, int-weather, int-circuitLength
	virtual float CarRace(bool& y, int, int) = 0;
};

