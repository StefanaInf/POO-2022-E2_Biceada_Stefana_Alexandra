#pragma once
class Number
{
	char* value;
	int base;
	//bool isNegative;
public:
	Number(); //default constructor
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int n);
	~Number();
	Number(const Number& ex); //copy constructor
	Number(const Number&& ex); //move constructor

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
	char* getValue();

	friend Number operator+(const Number& x, const Number& y);
	friend Number operator-(const Number& x, const Number& y);

	Number& operator=(Number&& ex); //move asignment operator

	void operator=(const char*);
	void operator=(const Number& n);
	void operator=(int n);
	
	void operator+=(Number nr);
	void operator--(int nr);
	void operator--();

	bool operator<(Number ex);
	bool operator>(Number ex);
	bool operator>=(Number ex);
	bool operator<=(Number ex);
	bool operator==(Number ex);
private:
	char CharToInt(int n);
	int IntToChar(char n);
};
