#include <iostream>
#include <string>

template<class T>
void Sort(T v[], std::size_t n) {
	bool sorted;
	do
	{
		sorted = true;
		for (int i = 1; i <= n - 3; i+=2)
			if (v[i] < v[i + 1])
			{
				T aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				sorted = false;
			}
	} while (!sorted);
}

template<class T>
void Print(T v[], std::size_t n) {
	for (int i = 0; i < n; i++) {
		std::cout << v[i] << " ";
	}
	std::cout << "\n\n";
}

int main()
{
	int int_array[10] = { 10,5,4,3,7,8,1,2,9,6 };
	Sort(int_array, 10);
	std::cout << "Int array sortat:" << "\n";
	Print(int_array, 10);

	double double_array[10] = { 4.5,1.2,7.12,9,5,6.7,12,34,5.6,1.3 };
	Sort(double_array, 10);
	std::cout << "Double array sortat:" << "\n";
	Print(double_array, 10);
	
	char char_array[10] = { 'a','v','b','n','t','p','k','d','o','q' };
	Sort(char_array, 10);
	std::cout << "Char array sortat:" << "\n";
	Print(char_array, 10);

	std::string string_array[10] = { "cookies", "oats", "pasta", "pancakes", "pizza", "soup", "salad", "tacos", "fries", "eggs" };
	Sort(string_array, 10);
	std::cout << "String array sortat:" << "\n";
	Print(string_array, 10);

	return 0;
}