#define _CRT_SECURE_NO_WARNINGS

#include "Number.h"
#include <iostream>
#include <cmath>

Number::Number() {
	printf("Default constructor\n");
}

Number::Number(const char* value, int base) {
	this->value = new char[strlen(value)];
	memcpy(this->value, value, strlen(value) + 1);
	this->base = base;
	//isNegative = value[0] == '-';
}

Number::~Number() {

}

char Number::CharToInt(int n) {
	return n - '0';
}

int Number::IntToChar(char n) {
	return n + '0';
}

int val(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}

//converteste la baza 10 si returneaza un int
int toDeci(char* str, int base)
{
	int len = strlen(str);
	int power = 1; 
	int num = 0;  
	int i;

	for (i = len - 1; i >= 0; i--)
	{
		if (val(str[i]) >= base)
		{
			printf("Invalid Number");
			return -1;
		}

		num += val(str[i]) * power;
		power = power * base;
	}

	return num;
}

char reVal(int num)
{
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}

void strev(char* str)
{
	int len = strlen(str);
	int i;
	for (i = 0; i < len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

//converteste un nr din baza 10, la alta baza si returneaza un char
char* fromDeci(char res[], int base, int inputNum)
{
	int index = 0;  

	while (inputNum > 0)
	{
		res[index++] = reVal(inputNum % base);
		inputNum /= base;
	}
	res[index] = '\0';

	strev(res);

	return res;
}

Number::Number(int nr) {
	char* s;
	char* c = fromDeci(s, 10, nr);
	this->value = c;
}

void Number::SwitchBase(int newBase) {
	int nr = toDeci(value, base);
	//std::cout << "Nr in baza 10 este: " << nr <<std::endl;
	char v[100] = { 0 };
	char* number = fromDeci(v,newBase,nr);
	//printf("Nr in baza respectiva este: %s", number);
	this->value = number;
	this->base = newBase;
}

int  Number::GetDigitsCount() {
	int leng = 0;
	leng = strlen(this->value);
	return leng;
}

int Number::GetBase() {
	return this->base;
}

void Number::Print() {
	std::cout << this->value;
}

char* Number::getValue() {
	return this->value;
}

Number operator+(const Number& x, const Number& y) {
	Number n1 = x;
	Number n2 = y;
	
	int base_nr1 = n1.GetBase();
	int base_nr2 = n2.GetBase();
	int max_base = 0;
	
	if (base_nr1 > base_nr2) { 
		max_base = base_nr1;
	}
	else { 
		max_base = base_nr2;
	}
	
	int n1_10 = toDeci(n1.getValue(),n1.GetBase());
	int n2_10 = toDeci(n2.getValue(),n2.GetBase());

	int nr = n1_10 + n2_10;
	char v[100] = { 0 };

	Number n(fromDeci(v,max_base,nr), max_base);
	
	return n;
}

Number operator-(const Number& x, const Number& y) {
	Number n1 = x;
	Number n2 = y;

	int base_nr1 = n1.GetBase();
	int base_nr2 = n2.GetBase();
	int max_base = 0;

	if (base_nr1 > base_nr2) {
		max_base = base_nr1;
	}
	else {
		max_base = base_nr2;
	}

	int n1_10 = toDeci(n1.getValue(), n1.GetBase());
	int n2_10 = toDeci(n2.getValue(), n2.GetBase());

	int nr;
	if (n1_10 > n2_10) {
		nr = n1_10 - n2_10;
	}
	else {
		nr = n2_10 - n1_10;
	}
	
	char v[100] = { 0 };

	Number n(fromDeci(v, max_base, nr), max_base);

	return n;
}

//Copy constructor
Number::Number(const Number& ex) {
	this->value = ex.value;
}

//Move constructor
Number::Number(const Number&& ex) {
	this->value = ex.value;
}

//Move assignment operator
Number& Number::operator=(Number&& ex) {
	this->value = ex.value;
	return *this;
}

void Number::operator=(int n) {
	//Number nr(toString(n), 10);
	char* s;
	Number nr(fromDeci(s, this->base, n),this->base);
	*this = nr;
}

void Number::operator=(const char* s) {
	Number nr(s, 10);
	*this = nr;
}

void Number::operator=(const Number& n) {
	base = n.base;
	value = n.value;
}

bool Number::operator<(Number ex) {
	if (this->value < ex.value)
		return true;
	return false;
}

bool Number::operator>(Number ex) {
	if (this->value > ex.value)
		return true;
	return false;
}

bool Number::operator>=(Number ex) {
	if (this->value >= ex.value)
		return true;
	return false;
}

bool Number::operator<=(Number ex) {
	if (this->value > ex.value)
		return true;
	return false;
}

bool Number::operator==(Number ex) {
	if (this->value > ex.value)
		return true;
	return false;
}

void Number::operator+=(Number nr) {
	char* s;
	int n = toDeci(this->value, this->base);
	int sum = n; 
	int nr1 = toDeci(nr.value, nr.base);
	sum += nr1;
	char* c = fromDeci(s, 10, sum);
	nr.value = c;
}

void Number::operator--(int) {
	value[strlen(value) - 1] = '\0';
}

void Number::operator--() {
	value++;
}
