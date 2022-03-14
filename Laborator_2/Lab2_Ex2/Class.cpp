#include "Class.h"
#include <iostream>

Class::Class()
{
	printf("Am apelat constructorul implicit\n");

	MathGrade = 0;
	EnglGrade = 0;
	HistGrade = 0;
	AvgGrade  = 0;
}

Class::Class(int MathGrade)
{
	//printf("Am apelat constructorul implicit\n");

	MathGrade = 0;
	this->MathGrade = MathGrade;
	EnglGrade = 0;
	HistGrade = 0;
	AvgGrade = 0;
}

void Class::setName(char* name)
{
	strcpy_s(this->name, 20, name);
}

char* Class::getName()
{
	return this->name;
}

void Class::setMathGrade(float input)
{
	if(input >= 0 && input <= 10)
		this->MathGrade = input;
}

float Class::getMathGrade()
{
	return this->MathGrade;
}

void Class::setHistGrade(float input)
{
	if (input >= 0 && input <= 10)
		this->HistGrade = input;
}

float Class::getHistGrade()
{
	return this->HistGrade;
}

void Class::setEnglGrade(float input)
{
	if (input >= 0 && input <= 10)
		this->EnglGrade = input;
}

float Class::getEnglGrade()
{
	return this->EnglGrade;
}

float Class::getAvgGrade()
{
	float avg = 0;
	avg = this->HistGrade + this->EnglGrade + this->MathGrade;
	return avg / 3;
}
