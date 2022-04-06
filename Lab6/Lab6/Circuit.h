#pragma once
#include "Car.h"

class Circuit
{
private:
	Car* vector[10]; //vector of class
	int NrCars;

	int CarFinish[10]; //the vector that will store what cars have finished the race
	float TimeCar[10]; //the vector will store the time needed for a car to finish the race

	int lenght;
	int weather;
public:
	Circuit(); //constructor

	void SetLenght(int len);
	void SetWeather(int w);
	void AddCar(Car* c); //adds car

	void Race(); //the method we use to get the info about the cars
	void Sort();
};

