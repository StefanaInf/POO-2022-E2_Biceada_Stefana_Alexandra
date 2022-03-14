#include <iostream>
#include "Math.h"

using namespace std;

int main()
{
	Math m;
	int a1 = 4;
	int b1 = 5;
	int c1 = 6;
	printf("Sum of 2 int numbers: %d\n", m.Add(a1, b1));
	printf("Sum of 3 int numbers: %d\n", m.Add(a1, b1, c1));
	double a2 = 1.9;
	double b2 = 1.9;
	double c2 = 9.4;
	printf("Sum of 2 double numbers: %d\n", m.Add(a2, b2));
	printf("Sum of 3 double numbers: %d\n", m.Add(a2, b2, c2));

	printf("Mul of 2 int numbers: %d\n", m.Mul(a1, b1));
	printf("Mul of 3 int numbers: %d\n", m.Mul(a1, b1, c1));
	printf("Mul of 2 double numbers: %d\n", m.Mul(a2, b2));
	printf("Mul of 3 double numbers: %d\n", m.Mul(a2, b2, c2));

	int n = 6;
	printf("Sum of %d numbers: %d\n", n, m.Add(n,1,2,3,4,5,6));
	printf("word: %s", m.Add("ABC", "DEFG"));
	return 0;
}