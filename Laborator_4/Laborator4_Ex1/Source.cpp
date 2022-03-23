#include <iostream>
#include "Sort.h"

using namespace std;

int main() 
{
	Sort c1(10, 10, 100);
	int v[5] = { 1,2,8,4,5 };
	Sort c2(v, 5);
	Sort c3(6, 1, 2, 3, 4, 5, 6);
	char c[] = "12,19,25,15";
	Sort c4(c);
	Sort c5();
	//c2.InsertSort();
	//c2.QuickSort(false, 1, 5);
	c2.BubbleSort();
	c2.Print();
	return 0;
}