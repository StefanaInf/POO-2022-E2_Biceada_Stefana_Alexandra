#include "Circuit.h"
#include "Car.h"

Circuit::Circuit() {
	this->NrCars = 0;
}

void Circuit::SetLenght(int len) {
	this->lenght = len;
}

void Circuit::SetWeather(int w) {
	this->weather - w;
}

//adds one car to the vector of classes
void Circuit::AddCar(Car* c) {
	vector[NrCars++] = c;
}

void Circuit::Race() {
	for (int i = 0; i < NrCars; i++)
	{
		bool completeRace = false;
		TimeCar[i] = vector[i]->CarRace(completeRace, this->weather, this->lenght);
		CarFinish[i] = completeRace;
	}
}

bool operator<(Car const& a, Car const& b)
{
	return a.value < b.value;
}

