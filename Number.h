#pragma once
class Number {
		// add data members
		char* number;
		int number_base;
		friend int convert10(const Number& n);
	public:
		Number(const char* value, int base); // where base is between 2 and 16  
		Number(const Number& n);
		Number(int value);
		~Number();
		int  GetDigitsCount(); // returns the number of digits for the current number   
		int  GetBase(); // returns the current base
		void Print();
		void SwitchBase(int newBase);
		// add operators and copy/move constructor
		Number& operator= (const Number& n);
		Number& operator= (int n);
		Number& operator+ (const Number& n);
		Number& operator- (const Number& n);
		char operator[] (int index);
		bool operator< (const Number& n);
		bool operator> (const Number& n);
		bool operator<= (const Number& n);
		bool operator>= (const Number& n);
		bool operator== (const Number& n);
		void operator-- ();
		void operator-- (int value);
};

