//Fraction.cpp
#include<iostream>
#include"Fraction.h"
using namespace std;

int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	if (numerator < 0)
	{
		(this->integer) ? (this->numerator = -numerator) : (this->numerator = numerator);
		this->integer = -integer;
	}
	else this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (!denominator) this->denominator = 1;
	else if (denominator < 0)
	{
		(this->integer) ? (this->numerator = numerator) : (this->numerator = -numerator);
		this->integer = -integer;
		this->denominator = -denominator;
	}
	else this->denominator = denominator;
}
//В классе Fraction реализовать :
//1. Конструкторы;
	//					Constructors:
Fraction::Fraction(double integer = 0)								//Конструктор с одним аргументом создает целое число: integer или конструктор по умолчанию
{
	if (!(integer - (int)integer))
	{
		this->set_integer(integer);
		this->set_numerator(0);
		this->set_denominator(1);
		//cout << "1 arg constructor\t" << this << endl;
	}
	else
	{
		int denominator = 1;
		while (integer - (int)integer)
		{
			integer *= 10;
			denominator *= 10;
		}
		this->set_integer(0);
		this->set_numerator((int)integer);
		this->set_denominator(denominator);
		this->reduce();
		this->to_proper();
		//cout << "1doubleArgConstructor" << endl;
	}
}
Fraction::Fraction(int numerator, int denominator)			//Конструктор с двумя аргументами создает дробь без целой части: numerator/denominator
{
	if (denominator == 1 || denominator == 0 || denominator == -1)
	{
		this->set_integer(numerator);
		this->set_numerator(0);
		this->set_denominator(denominator);
	}
	else
	{
		this->set_integer(0);
		this->set_numerator(numerator);
		this->set_denominator(denominator);
	}
	//cout << "\n2 arg constructor\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)//Конструктор с тремя аргументами создает дробь с целой частью: integer(numerator/denominator)
{
	if (denominator == 0 || denominator == 1 || denominator == -1)
	{
		this->set_integer(integer + numerator);
		this->set_numerator(0);
		this->set_denominator(1);
	}
	else
	{
		this->set_integer(integer);
		this->set_numerator(numerator);
		this->set_denominator(denominator);
	}
	//cout << "3 arg constructor\t" << this << endl;
}
Fraction::Fraction(Fraction& other)
{
	this->set_integer(other.get_integer());
	this->set_numerator(other.get_numerator());
	this->set_denominator(other.get_denominator());
	//cout << "CopyConstructor" << endl;
}
Fraction::~Fraction()
{
	//cout << "Destructor\t\t" << this << endl;
}

//1. Вывод на экран;
	//						Methods:
void Fraction::print()const
{
	if (this->get_integer()) cout << this->get_integer();
	if (this->get_numerator())
	{
		if (this->get_integer())cout << "(";
		cout << this->get_numerator() << "/" << this->get_denominator();
		if (this->get_integer())cout << ")";
	}
	else if (!(this->get_integer())) cout << 0;
	cout << endl;
}
//2. Написать методы :
//		Fraction & to_improper();	//целую часть интегрирует в числитель
Fraction& Fraction::to_improper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction& Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.numerator, inverted.denominator);
	return inverted;
}
Fraction& Fraction::reduce()			//сокращает дробь
{
	this->to_improper();
	int more, less, rest = 0;
	if (this->get_numerator() > this->get_denominator())
	{
		more = this->get_numerator();
		less = this->get_denominator();
	}
	else
	{
		more = this->get_denominator();
		less = this->get_numerator();
	}
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	this->set_numerator(this->get_numerator() / more);
	this->set_denominator(this->get_denominator() / more);
	return *this;
}

//4. Перегрузить операторы++ / --;
Fraction& Fraction::operator++()
{
	if (!integer) this->set_numerator(get_numerator() + get_denominator());
	else this->set_integer(this->get_integer() + 1);
}
Fraction Fraction::operator++(int)
{
	Fraction old = *this;
	if (!integer) this->set_numerator(get_numerator() + get_denominator());
	else this->set_integer(this->get_integer() + 1);
	return old;
}
Fraction& Fraction::operator--()
{
	if (!integer) this->set_numerator(get_numerator() - get_denominator());
	else this->set_integer(this->get_integer() - 1);
	return *this;
}
Fraction Fraction::operator--(int)
{
	Fraction old = *this;
	if (!integer) this->set_numerator(get_numerator() - get_denominator());
	else this->set_integer(this->get_integer() - 1);
	return old;
}
Fraction& Fraction::operator()(int integer, int numerator, int denominator)
{
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	return *this;
}

//5. Перегрузить присваивания: =, +=, -=, *=, /=;
Fraction Fraction::operator=(const Fraction& other)
{
	Fraction res(other);
	//cout << "operator=\n";
	return res;
}
Fraction& Fraction::operator+=(const Fraction& other)
{
	Fraction res;
	res = *this + other;
	*this = res;
	return *this;
}
Fraction& Fraction::operator-=(const Fraction& other)
{
	Fraction res;
	res = *this - other;
	*this = res;
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& other)
{
	Fraction res;
	res = *this * other;
	*this = res;
	return *this;
}
Fraction& Fraction::operator/=(const Fraction& other)
{
	Fraction res;
	res = *this / other;
	*this = res;
	return *this;
}
//Проверочный код должен заработать:
//	Преобразование типов
Fraction::operator int()const
{
	Fraction res;
	res.set_integer(this->get_integer());
	res.set_numerator(this->get_numerator());
	res.set_denominator(this->get_denominator());
	res.to_proper();
	return res.get_integer();
}
Fraction::operator double()const
{
	/*Fraction res;
	res.set_integer(this->get_integer());
	res.set_numerator(this->get_numerator());
	res.set_denominator(this->get_denominator());
	res.to_improper();
	return (double) res.get_numerator() / res.get_denominator();*/
	return integer + (double)numerator / denominator;
}

std::istream& Fraction::operator>>(std::istream& is)
{
	int number[3] = {};
	const int SIZE = 32;
	char buffer[SIZE] = {};
	char delimiters[] = "/ ()";

	is >> buffer;

	int n = 0;	//счетчик чисел в введенной строке
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		number[n++] = atoi(pch);	//atoi строку в число
	return is;
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (!(obj.get_numerator())) return os << obj.get_integer();
	else if (!(obj.get_integer())) return os << obj.get_numerator() << '/' << obj.get_denominator();
	else return os << obj.get_integer() << '(' << obj.get_numerator() << '/' << obj.get_denominator() << ')';
}
//7. Перегрузить оператор ввода с клавиатуры;
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj(integer, numerator, denominator);
	return is;
}

//3. Перегрузить арифметические операторы : +, -, *, / ;
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction res;
	res.set_numerator(left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator());
	res.set_denominator(left.get_denominator() * right.get_denominator());
	res.reduce();
	return res;
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction res;
	res.set_numerator(left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator());
	res.set_denominator(left.get_denominator() * right.get_denominator());
	res.reduce();
	return res;
}
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction res;
	res.set_numerator(left.get_numerator() * right.get_numerator());
	res.set_denominator(left.get_denominator() * right.get_denominator());
	res.reduce();
	return res;
}
Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	right.inverted();
	Fraction res;
	res = left * right;
	res.reduce();
	return res;
}

//6. Перегрузить операторы сравнения: == , != , > , < , >= , <= ;
bool operator==(const Fraction& left, const Fraction& right)
{
	return (((left.get_integer() * left.get_denominator() + left.get_numerator()) * right.get_denominator()) == ((right.get_integer() * right.get_denominator() + right.get_numerator()) * left.get_denominator()));
}
bool operator!=(Fraction left, Fraction right)
{
	return !(left == right);
}
bool operator>(const Fraction& left, const Fraction& right)
{
	return (((left.get_integer() * left.get_denominator() + left.get_numerator()) * right.get_denominator()) > ((right.get_integer() * right.get_denominator() + right.get_numerator()) * left.get_denominator()));
}
bool operator<(const Fraction& left, const Fraction& right)
{
	return (((left.get_integer() * left.get_denominator() + left.get_numerator()) * right.get_denominator()) < ((right.get_integer() * right.get_denominator() + right.get_numerator()) * left.get_denominator()));
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}