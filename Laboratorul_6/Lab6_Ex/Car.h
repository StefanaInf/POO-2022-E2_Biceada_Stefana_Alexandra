#pragma once

class Car
{
protected:
	int fuelCapacity;
	int fuelConsumption;
	int averageSpeed[3];
	char* name;
private:
	virtual char* GetName() = 0;
	
};

