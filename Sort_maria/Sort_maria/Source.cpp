#include <iostream>
#include <string>

template <class T>
void IncreasingSort(T v[], size_t n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i+1; j < n; j++)
			if (v[i] > v[j])
			{
				T aux;
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
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
	int int_array1[10] = { 10,5,4,3,7,8,1,2,9,6 };
	IncreasingSort(int_array1, 10);
	std::cout << "Int array sortat:" << "\n";
	Print(int_array1, 10);

	int int_array2[10] = { 10,9,8,7,6,5,4,3,2,1};
	IncreasingSort(int_array2, 10);
	std::cout << "Int array sortat:" << "\n";
	Print(int_array2, 10);

	int int_array3[10] = { 10,5,6,7,6,7,4,1,2,1 };
	IncreasingSort(int_array3, 10);
	std::cout << "Int array sortat:" << "\n";
	Print(int_array3, 10);

	double double_array[10] = { 4.5,1.2,7.12,9,5,6.7,12,34,5.6,1.3 };
	IncreasingSort(double_array, 10);
	std::cout << "Double array sortat:" << "\n";
	Print(double_array, 10);

	return 0;
}