//Fraction.h
#pragma once
#include<iostream>
#include"Fraction.cpp"
using namespace std;

class Fraction;
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

class Fraction
{
	int integer;		//Целая часть
	int numerator;		//Числитель
	int denominator;	//Знаменатель
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	//В классе Fraction реализовать :
	//1. Конструкторы;
		//					Constructors:
	Fraction(double integer = 0);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(Fraction& other);
	~Fraction();
	//1. Вывод на экран;
		//						Methods:
	void print()const;
	//2. Написать методы :
	//		Fraction & to_improper();	//целую часть интегрирует в числитель
	Fraction& to_improper();
	Fraction& to_proper();
	Fraction inverted()const;
	Fraction& reduce();
	//4. Перегрузить операторы++ / --;
	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);
	Fraction& operator()(int integer, int numerator, int denominator);
	//5. Перегрузить присваивания: =, +=, -=, *=, /=;
	Fraction operator=(const Fraction& other);
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);
	//	Преобразование типов
	operator int()const;
	explicit operator double()const;
	std::istream& operator>>(std::istream& is);
};