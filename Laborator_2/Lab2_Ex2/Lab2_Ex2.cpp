// Lab2_Ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string.h>
#include "Class.h"
#include "GlobalFunctions.h"

using namespace std;

int main()
{
	Class c1, c2;

	Class* c3 = new Class(10);

	c1.setName((char*)"Popeye the Sailor");
	c1.setMathGrade(5.54);
	c1.setEnglGrade(10);
	c1.setHistGrade(2.5);
	printf("Notele studentului %s sunt la matematica: %f, la engleza: %f, la istorie: %f\n", c1.getName(), c1.getMathGrade(),c1.getEnglGrade(), c1.getHistGrade());
	printf("Media studentului este: %f\n", c1.getAvgGrade());

	c2.setName((char*)"Olive");
	c2.setMathGrade(9);
	c2.setEnglGrade(7.5);
	c2.setHistGrade(3.14);
	printf("Notele studentului %s sunt la matematica: %f, la engleza: %f, la istorie: %f\n", c2.getName(), c2.getMathGrade(), c2.getEnglGrade(), c2.getHistGrade());
	printf("Media studentului este: %f\n", c2.getAvgGrade());
	
	printf("Compararea numelui: %d\n", CompareName(c1,c2));
	printf("Compararea notei la matematica: %d\n", CompareGradeMath(c1,c2));
	printf("Compararea notei la engleza: %d\n", CompareGradeEngl(c1, c2));
	printf("Compararea notei la istorie: %d\n", CompareGradeHist(c1, c2));
	printf("Compararea mediei: %d\n", CompareGradeAvg(c1, c2));

	return 0;
}

