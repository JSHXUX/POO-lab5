#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <string.h>
#include <iostream>
using namespace std;
int convert10(const Number& n)
{
	int aux = 0, p=1, len = strlen(n.number);
	for (int i = len - 1; i >= 0; i--)
	{
		int c = 0;
		if (n.number[i] >= 'A' && n.number[i] <= 'Z') c = n.number[i] - 'A' + 10;
		else c = n.number[i] - '0';
		aux = aux + p * c;
		p *= n.number_base;
	}
	return aux;
}
Number::Number(const char* value, int base)
{
	this->number_base = base;
	int aux = strlen(value);
	this->number = new char[aux + 1];
	for (int i = 0; i < aux; i++)
		this->number[i] = value[i];
	this->number[aux] = 0;
}
Number::Number(const Number& n)
{
	this->number_base = n.number_base;
	this->number = n.number;
}
Number::Number(int value)
{
	this->number_base = 10;
	int aux = 0, cl = value;
	while (cl)
	{
		aux++;
		cl /= 10;
	}
	this->number = new char[aux + 1];
	for (int i = aux - 1; i >= 0; i--)
	{
		this->number[i] = (value % 10) + '0';
		value /= 10;
	}
	this->number[aux] = 0;
}
Number::~Number()
{
	this->number_base = 0;
	delete this->number;
	this->number = nullptr;
}
void Number::Print()
{
	printf("%s\n", this->number);
}
int  Number::GetDigitsCount()
{
	return strlen(this->number);
}
int  Number::GetBase()
{
	return this->number_base;
}
void Number::SwitchBase(int newBase)
{
	int aux = convert10(*this), i=0;
	char* x = new char[100];
	while (aux)
	{
		if (aux % newBase < 10)
			x[i++] = (aux % newBase) + '0';
		else
			x[i++] = (aux % newBase) + 'A' - 10;
		aux /= newBase;
	}
	x[i] = 0;
	char* p = new char[i + 1];
	this->number = p;
	int k = 0;
	for (int j = i - 1; j >= 0; j--)
		this->number[k++] = x[j];
	this->number[k] = 0;
	this->number_base = newBase;
}
Number& Number::operator= (const Number& n)
{
	this->number_base = n.number_base;
	this->number = n.number;
	return (*this);
}
Number& Number::operator= (int n)
{
	int aux = n, i = 0;
	char* x = new char[100];
	while (aux)
	{
		x[i++] = (aux % 10) + '0';
		aux /= 10;
	}
	x[i] = 0;
	char* p = new char[i + 1];
	this->number = p;
	int k = 0;
	for (int j = i - 1; j >= 0; j--)
		this->number[k++] = x[j];
	this->number[k] = 0;
	this->number_base = 10;
	return (*this);
}
Number& Number::operator+ (const Number& n)
{
	int aux1 = convert10(*this);
	int aux2 = convert10(n);
	aux1 += aux2;
	if (n.number_base > this->number_base)
		this->number_base = n.number_base;
	int aux = aux1, i = 0;
	char* x = new char[100];
	while (aux)
	{
		if (aux % this->number_base < 10)
			x[i++] = (aux % this->number_base) + '0';
		else
			x[i++] = (aux % this->number_base) + 'A' - 10;
		aux /= this->number_base;
	}
	x[i] = 0;
	char* p = new char[i + 1];
	this->number = p;
	int k = 0;
	for (int j = i - 1; j >= 0; j--)
		this->number[k++] = x[j];
	this->number[k] = 0;
	this->number_base = this->number_base;
	return (*this);
}
Number& Number::operator- (const Number& n)
{
	int aux1 = convert10(*this);
	int aux2 = convert10(n);
	aux1 -= aux2;
	if (n.number_base > this->number_base)
		this->number_base = n.number_base;
	int aux = aux1, i = 0;
	char* x = new char[100];
	while (aux)
	{
		if (aux % this->number_base < 10)
			x[i++] = (aux % this->number_base) + '0';
		else
			x[i++] = (aux % this->number_base) + 'A' - 10;
		aux /= this->number_base;
	}
	x[i] = 0;
	char* p = new char[i + 1];
	this->number = p;
	int k = 0;
	for (int j = i - 1; j >= 0; j--)
		this->number[k++] = x[j];
	this->number[k] = 0;
	this->number_base = this->number_base;
	return (*this);
}
char Number::operator[] (int index)
{
	return this->number[index];
}
bool Number::operator< (const Number& n)
{
	int aux1 = convert10(*this);
	int aux2 = convert10(n);
	if (aux1 < aux2) return true;
	else return false;
}
bool Number::operator<= (const Number& n)
{
	int aux1 = convert10(*this);
	int aux2 = convert10(n);
	if (aux1 <= aux2) return true;
	else return false;
}
bool Number::operator> (const Number& n)
{
	int aux1 = convert10(*this);
	int aux2 = convert10(n);
	if (aux1 > aux2) return true;
	else return false;
}
bool Number::operator>= (const Number& n)
{
	int aux1 = convert10(*this);
	int aux2 = convert10(n);
	if (aux1 >= aux2) return true;
	else return false;
}
bool Number::operator== (const Number& n)
{
	int aux1 = convert10(*this);
	int aux2 = convert10(n);
	if (aux1 == aux2) return true;
	else return false;
}
void Number::operator-- ()
{
	int aux = strlen(this->number);
	for (int i = 0; i < aux - 1; i++)
		this->number[i] = this->number[i + 1];
	this->number[aux] = 0;
}
void Number::operator-- (int value)
{
	this->number[strlen(this->number) - 1] = 0;
}