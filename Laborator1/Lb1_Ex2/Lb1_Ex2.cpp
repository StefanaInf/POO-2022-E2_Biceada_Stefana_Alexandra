#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char s[200];
	char cuv[100][20];
	int  nr = 0;

	scanf_s("%d", &nr);

	for (int i = 0; i < nr; i++)
	{
		scanf_s("%s", cuv[i], 20);
	}
	
	//sortare vector
	for(int i = 0; i < nr - 1; i++)
		for (int j = 0; j < nr - i - 1; j++)
		{
			if (strlen(cuv[j]) < strlen(cuv[j+1]))
			{
				char aux[20];
				strcpy(aux, cuv[j]);
				strcpy(cuv[j], cuv[j + 1]);
				strcpy(cuv[j + 1], aux);
			}
			else
			{
				if (strlen(cuv[j]) == strlen(cuv[j + 1])) {
					if (strcmp(cuv[j], cuv[j + 1]) > 0)
					{
						char aux[20];
						strcpy(aux, cuv[j]);
						strcpy(cuv[j], cuv[j + 1]);
						strcpy(cuv[j + 1], aux);
					}
				}
			}
		}

	for (int i = 0; i < nr; i++)
	{
		printf("%s\n", cuv[i]);
	}
	return 0;
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
