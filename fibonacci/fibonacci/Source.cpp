#include <iostream>

using namespace std;

int main()
{
	int s = 2;
	int a = 1;
	int b = 2;
	int c;
	//cout << a << " " << b << " ";
	while (b < 4000000)
	{
		c = a + b;
		a = b;
		b = c;
		if (b % 2 == 0)
			s += b;
	}
	if (b % 2 == 0)
		s -= b;
	cout << s;
	return 0;
}