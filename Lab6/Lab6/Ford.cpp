#include "Ford.h"
#include "Weather.h"

Ford::Ford() {
	fuelCapacity = 100;
	fuelConsumtion = 25;
	averageSpeed[Rain] = 100;
	averageSpeed[Sunny] = 150;
	averageSpeed[Snow] = 100;
	name = (char*)"Mazda";
};

float Ford::CarRace(bool& k, int w, int lenghtRace) {
	int speed = averageSpeed[w]; //viteza in functie de vreme

	int time = fuelCapacity / fuelConsumtion; //the time that the car can be driven for
	int distance = speed * time; //the distance that the car can be drive for

	if (distance < lenghtRace) w = 0; //the car cannot finish the race
	else w = 1; //the car can finish the race

	//we want to return the amount of time that each car needs for it to finish the race
	int timeNeeded = (time * lenghtRace) / distance;
	return timeNeeded;
}

char* Ford::GetName() {
	return name;
}