#include "Math.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <iostream>


int Math::Add(int number1,int number2) {
	return number1 + number2;
}

int Math::Add(int number1,int number2, int number3) {
	return number1 + number2 + number3;
}

int Math::Add(double number1,double number2) {
	return number1 + number2;
}

int Math::Add(double number1, double number2, double number3) {
	return number1 + number2 + number3;
}
//Mul 
int Math::Mul(int number1, int number2) {
	return number1 * number2;
}

int Math::Mul(int number1, int number2, int number3) {
	return number1 * number2 * number3;
}

int  Math::Mul(double number1, double number2) {
	return number1 * number2;
}

int Math::Mul(double number1, double number2, double number3) {
	return number1 * number2 * number3;
}

int Math::Add(int count, ...) {
	int sum = 0;
	int val;

	va_list v1;
	va_start(v1, count);
	for (int i = 0; i < count; i++) {
		val = va_arg(v1, int);
		sum += val;
	}
	va_end(v1);

	return sum;
}

char* Math::Add(const char* sir1, const char* sir2) {
	char* word = nullptr;
	int s = 0;
	s = strlen(sir1) + strlen(sir2) + 1;
	word = (char*) malloc(s * sizeof(char));
	memcpy(word, sir1, strlen(sir1));
	memcpy(word + strlen(sir1), sir2, strlen(sir2));
	memcpy(word + strlen(sir1) + strlen(sir2), "\0", 1);
	return word;
}
