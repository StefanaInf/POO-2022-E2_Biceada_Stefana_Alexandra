#include <iostream>
#include "Canvas.h"

using namespace std;

int main()
{
	Canvas* c1 = new Canvas(25,25);
	c1->Clear();
	//c1->DrawCircle(5, 5, 4, '*');
	//c1->FillCircle(5, 5, 4, '*');
	//c1->DrawRect(2, 2, 10, 15, '*');
	c1->FillRect(2, 2, 10, 15, '*');
	//c1->SetPoint(5, 5, '&');
	//c1->DrawLine(1, 2, 15, 15, '*');
	
	c1->Print();
	return 0;
}