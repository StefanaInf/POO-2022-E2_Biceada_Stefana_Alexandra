
#define _CRT_SECURE_NO_WARNINGS

#include "Sort.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

//1.
Sort::Sort(int number_elements, int min_element, int max_element) {
	vector = (int*)(malloc(number_elements * sizeof(int)));

	this->number = number_elements;

	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i < number_elements; i++) {
		vector[i] = min_element + rand() % (min_element - max_element + 1);
	}
}

Sort::Sort() : vector(new int[6]{ 1, 2, 3, 4, 5, 6 }) {
	this->number = 6;
}

//3.
Sort::Sort(int* elemente, int number_elements) {
	vector = (int*)(malloc(number_elements * sizeof(int)));

	for (int i = 0; i < number_elements; i++) {
		vector[i] = elemente[i];
	}
	this->number = number_elements;
}

//4.
Sort::Sort(int count, ...) {
	vector = (int*)(malloc(count * sizeof(int)));

	va_list vl;
	va_start(vl, count);
	for (int i = 0; i < count; i++) {
		vector[i] = va_arg(vl, int);
	}
	va_end(vl);

	this->number = count;
}

//5.
Sort::Sort(char* s) {
	int nr = 1;
	for (int i = 0; s[i]; i++) {
		if (s[i] == ',')
			nr++;
	}
	
	vector = (int*)(malloc(nr * sizeof(int)));
	int i = 0;

	char* p;
	p = strtok(s, ",");
	while (p != NULL) {
		int number = 0;
		for (int i = 0; p[i]; i++) {
			number = number * 10 + (p[i] - '0');
		}
		//std::cout << number << " ";
		vector[i++] = number;
		p = strtok(NULL, ",");
	}

	this->number = nr;
}

void Sort::Print() {
	for (int i = 0; i < this->number; i++) {
		std::cout << this->vector[i] << " ";
	}
}

void Sort::InsertSort(bool ascendent)
{
	if (ascendent == true) {
		int i, key, j;
		for (i = 1; i < this->number; i++)
		{
			key = this->vector[i];
			j = i - 1;

			while (j >= 0 && this->vector[j] > key)
			{
				this->vector[j + 1] = this->vector[j];
				j = j - 1;
			}
			this->vector[j + 1] = key;
		}
	}
	else {
		int i, key, j;
		for (i = 1; i < this->number; i++)
		{
			key = this->vector[i];
			j = i - 1;

			while (j >= 0 && this->vector[j] < key)
			{
				this->vector[j + 1] = this->vector[j];
				j = j - 1;
			}
			this->vector[j + 1] = key;
		}
	}
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition_true(int arr[], int low, int high)
{
	int pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int partition_false(int arr[], int low, int high)
{
	int pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void Sort::QuickSort(bool ascendent, int low, int high)
{
	if (ascendent == true) {
		if (low < high)
		{
			int pi = partition_true(vector, low, high);

			QuickSort(vector, low, pi - 1);
			QuickSort(vector, pi + 1, high);
		}
	}
	else {
		if (low < high)
		{
			int pi = partition_false(vector, low, high);

			QuickSort(vector, low, pi - 1);
			QuickSort(vector, pi + 1, high);
		}
	}
}

void Sort::BubbleSort(bool ascendent) {
	bool sortat;
	int m = this->number;
	if (ascendent == true) {
		do
		{
			sortat = true;
			int p = m;
			for (int i = 0; i < p - 1; i++)
				if (this->vector[i] > this->vector[i + 1])
				{
					int aux = this->vector[i];
					this->vector[i] = this->vector[i + 1];
					this->vector[i + 1] = aux;
					sortat = false;
					m = i + 1;
				}
		} while (!sortat);
	}
	else {
		do
		{
			sortat = true;
			int p = m;
			for (int i = 0; i < p - 1; i++)
				if (this->vector[i] < this->vector[i + 1])
				{
					int aux = this->vector[i];
					this->vector[i] = this->vector[i + 1];
					this->vector[i + 1] = aux;
					sortat = false;
					m = i + 1;
				}
		} while (!sortat);
	}
}

int  Sort::GetElementsCount() {
	return this->number;
}

int  Sort::GetElementFromIndex(int index) {
	return this->vector[index];
}