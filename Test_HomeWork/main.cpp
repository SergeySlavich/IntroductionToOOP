//Fraction
#include<iostream>
#include<windows.h>
using namespace std;

class Fraction
{
	int integer;		//Целая часть
	int numerator;		//Числитель
	int denominator;	//Знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		if (numerator < 0)
		{
			(this->integer) ? (this->numerator = -numerator) : (this->numerator = numerator);
			this->integer = -integer;
		}
		else this->numerator = numerator;
	}
	void set_denominator(int denominator)
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
	Fraction(int integer = 0)								//Конструктор с одним аргументом создает целое число: integer или конструктор по умолчанию
	{
		this->integer = integer;
		this->set_numerator(0);
		this->set_denominator(1);
		cout << "1 arg constructor\t" << this << endl;
	}
	Fraction(int numerator, int denominator)			//Конструктор с двумя аргументами создает дробь без целой части: numerator/denominator
	{
		if (denominator == 1 || denominator == 0 || denominator == -1)
		{
			this->integer = numerator;
			this->numerator = 0;
		}
		else
		{
			this->integer = 0;
			this->set_numerator(numerator);
		}
		this->set_denominator(denominator);
		cout << "\n2 arg constructor\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)//Конструктор с тремя аргументами создает дробь с целой частью: integer(numerator/denominator)
	{
		if (denominator == 0 || denominator == 1 || denominator == -1)
		{
			this->integer = integer + numerator;
			this->set_numerator(0);
			this->set_denominator(1);
		}
		else
		{
			this->integer = integer;
			this->set_numerator(numerator);
			this->set_denominator(denominator);
		}
		//cout << "3 arg constructor\t" << this << endl;
	}
	Fraction(double number)//Конструктор с 1 аргументом типа double - переводит десятичную дробь в обыкновенную
	{
		this->set_integer((int)number);
		cout << this->get_integer() << "\tinteger\n";
		double numerator = number - this->get_integer();
		cout << numerator << "\tnumerator\n" << endl;
		this->set_numerator((int) (numerator * 10));
		cout << get_numerator() << "\t numerator\n";
		this->set_denominator(10);
		cout << get_denominator() << "\t denominator\n";
		while (!(numerator - this->get_numerator()))
		{
			numerator *= 10;
			this->set_numerator((int) numerator);
			this->set_denominator(this->get_denominator() * 10);
			cout << numerator << endl;
		}
	}
	~Fraction()
	{
		//cout << "Destructor\t\t" << this << endl;
	}

	//1. Вывод на экран;
		//						Methods:
	void print()const
	{
		if (integer) cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");

	cout << "***HOME WORK FRACTION TEST***\n";
	Fraction Test(4.725);

	cout << Test.get_integer() << endl;
	cout << Test.get_numerator() << endl;
	cout << Test.get_denominator() << endl;

	Test.print();
	cout << endl;
}
