#include "NumberList.h"
#include <iostream>

using namespace std;

NumberList::NumberList()
{
	cout << "Apel constructor implicit" << endl;

	count = 0;
}

NumberList::NumberList(int y)
{
	cout << "Apel constructor implicit: " << 5 << endl;

	count = 0;
}

void NumberList::Init()
{
	this -> count = 0;
	//count = 0;
}

bool NumberList::Add(int x)
{
	numbers[count] = x;
	count++;

	if (count >= 10)
		return false;
	return true; 
}

void NumberList::Sort()
{
	bool sortat;
	do {
		sortat = true;
		for(int i = 0; i < count - 1; i++)
			if (numbers[i] > numbers[i + 1])
			{
				swap(numbers[i], numbers[i + 1]);
				sortat = false;
			}
	}while(!sortat);
}

void NumberList::Print()
{
	cout << "Nr elemente: " << count << endl;

	for (int i = 0; i < count; i++)
		cout << numbers[i] << " ";
	cout << endl;
}