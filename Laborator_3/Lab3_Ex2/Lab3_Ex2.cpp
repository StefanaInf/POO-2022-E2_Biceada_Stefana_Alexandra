#include <iostream>
#include "Canvas.h"

using namespace std;

int main()
{
	Canvas* c1 = new Canvas(25,25);
	c1->DrawCircle(5, 5, 4, '*');
	c1->Print();
	return 0;
}