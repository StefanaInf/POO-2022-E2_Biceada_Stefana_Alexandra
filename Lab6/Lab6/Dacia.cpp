#include "Dacia.h"
#include "Weather.h"

Dacia::Dacia() {
	fuelCapacity = 75;
	fuelConsumtion = 50;
	averageSpeed[Rain] = 30;
	averageSpeed[Sunny] = 70;
	averageSpeed[Snow] = 30;
	name = (char*)"Dacia";
};

float Dacia::CarRace(bool &k, int w, int lenghtRace) {
	int speed = averageSpeed[w]; //viteza in functie de vreme

	int time = fuelCapacity / fuelConsumtion; //the time that the car can be driven for
	int distance = speed * time; //the distance that the car can be drive for

	if (distance < lenghtRace) w = 0; //the car cannot finish the race
	else w = 1; //the car can finish the race

	//we want to return the amount of time that each car needs for it to finish the race
	int timeNeeded = (time * lenghtRace) / distance;
	return timeNeeded;
}

char* Dacia::GetName() {
	return name;
}