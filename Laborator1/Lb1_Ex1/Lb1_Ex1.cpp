// Lb1_Ex1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int ConvertCharToInt(char s[100])
{
    int number = 0;
    int len = strlen(s);
    printf("%d\n", len);
    for (int i = 0; i < len - 1; i++)
    {
        printf("%d\n", number);
        number = number * 10 + (int(s[i]) - 48);
    }
    return number;
}

int main()
{
    FILE* fisier;
    fopen_s(&fisier, "in.txt", "r");
    char numar[100];
    int sum = 0;

    while (fgets(numar, 100, fisier) != 0)
    {
        int nr;
        nr = ConvertCharToInt(numar);
        printf("%d\n", nr);
        sum += nr;
    }
    
    printf("%d", sum);

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
