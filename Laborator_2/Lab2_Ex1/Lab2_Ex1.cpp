// Lab2_Ex1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "NumberList.h"

int main()
{
	NumberList n(5);
	//n.Init();
	n.Add(7);
	n.Add(18);
	n.Add(10);
	n.Add(12);
	n.Add(2);
	n.Sort();
	n.Print();

	/*
	NumberList* m = new NumberList;
	//m->Init();
	m->Add(22);
	m->Print();
	*/

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
