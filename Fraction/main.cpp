//Fraction
#include<iostream>
#include<windows.h>
using namespace std;

//TODO:
//ВЫУЧИТЬ ТЕОРИЮ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//В классе Fraction реализовать :
//1. Конструкторы и вывод на экран;
//		5;		//double a = 5;
//		1 / 2;
//		2(3 / 4);
//2. Написать методы :
//		Fraction & to_proper();	//целую часть интегрирует в числитель
//		Fraction& to_improper();//выделяет целую часть из числителя
//3. Перегрузить арифметические операторы : +, -, *, / ;
//4. Перегрузить операторы++ / --;
//5. Перегрузить составные присваивания : +=, -=, *=, /=;
//6. Перегрузить операторы сравнения : == , != , > , < , >= , <= ;
//7. Перегрузить оператор ввода с клавиатуры;

#define delimiter "\n----------------------------------------------------\n"

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
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	//					Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Default constructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "2ArgConstructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "3ArgConstructor\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor\t\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//						Methods:
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer) cout << '(';
			cout << numerator << '/' << denominator;
			if (integer) cout << ')';
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
//2. Написать методы :
//		Fraction & to_proper();	//целую часть интегрирует в числитель
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
//		Fraction& to_improper();//выделяет целую часть из числителя
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
//4. Перегрузить операторы++ / --;
	Fraction& operator++()
	{
		this->to_improper();
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		this->to_improper();
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		this->to_improper();
		integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		this->to_improper();
		Fraction old = *this;
		integer--;
		return old;
	}
	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}

	//					Type-cast operators:
	operator int()const
	{
		return Fraction(*this).to_proper().integer;
		//вызываем конструктор для создания безымянной копии объекта для вызова константного метода
	}
};

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_numerator() == 0) return os << ' ' << obj.get_integer() << ' ';
	else if (obj.get_integer() == 0) return os << ' ' << obj.get_numerator() << '/' << obj.get_denominator() << ' ';
	else return os << ' ' << obj.get_integer() << '(' << obj.get_numerator() << '/' << obj.get_denominator() << ") ";
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
Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction res;
	res.set_numerator((left.get_integer() * left.get_denominator() + left.get_numerator()) * right.get_denominator() + (right.get_integer() * right.get_denominator() + right.get_numerator()) * left.get_denominator());
	res.set_denominator(left.get_denominator() * right.get_denominator());
	res.to_improper();
	return res;
}
Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction res;
	res.set_numerator((left.get_integer() * left.get_denominator() + left.get_numerator()) * right.get_denominator() - (right.get_integer() * right.get_denominator() + right.get_numerator()) * left.get_denominator());
	res.set_denominator(left.get_denominator() * right.get_denominator());
	res.to_improper();
	return res;
}
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	//Fraction result;
	//result.set_numerator(left.get_numerator() * right.get_numerator());
	//result.set_denominator(left.get_denominator() * right.get_denominator());
	
	//Fraction result
	//(
	//	left.get_numerator() * right.get_numerator(),
	//	left.get_denominator() * right.get_denominator()
	//);
	//return result;
	
	//Явно вызываем конструктор и создаем временный безымянный объект
	//который сразу же возвращается на место вызова:
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction res;
	res.set_numerator((left.get_integer() * left.get_denominator() + left.get_numerator()) * right.get_denominator());
	res.set_denominator(left.get_denominator() * (right.get_integer() * right.get_denominator() + right.get_numerator()));
	res.to_improper();
	return res;
}

//5. Перегрузить составные присваивания : +=, -=, *=, /=;
Fraction& operator+=(Fraction& left, const Fraction& right)
{
	Fraction res;
	res.set_numerator((left.get_integer() * left.get_denominator() + left.get_numerator()) * right.get_denominator() + (right.get_integer() * right.get_denominator() + right.get_numerator()) * left.get_denominator());
	res.set_denominator(left.get_denominator() * right.get_denominator());
	res.to_improper();
	left = res;
	return left;
}
Fraction& operator-=(Fraction& left, const Fraction& right)
{
	Fraction res;
	res.set_numerator((left.get_integer() * left.get_denominator() + left.get_numerator()) * right.get_denominator() - (right.get_integer() * right.get_denominator() + right.get_numerator()) * left.get_denominator());
	res.set_denominator(left.get_denominator() * right.get_denominator());
	res.to_improper();
	left = res;
	return left;
}
Fraction& operator*=(Fraction& left, const Fraction& right)
{
	Fraction res;
	res.set_numerator((left.get_integer() * left.get_denominator() + left.get_numerator()) * (right.get_integer() * right.get_denominator() + right.get_numerator()));
	res.set_denominator(left.get_denominator() * right.get_denominator());
	res.to_improper();
	left = res;
	return left;
}
Fraction& operator/=(Fraction& left, const Fraction& right)
{
	Fraction res;
	res.set_numerator((left.get_integer() * left.get_denominator() + left.get_numerator()) * right.get_denominator());
	res.set_denominator(left.get_denominator() * (right.get_integer() * right.get_denominator() + right.get_numerator()));
	res.to_improper();
	left = res;
	return left;
}

//6. Перегрузить операторы сравнения : == , != , > , < , >= , <= ;
bool operator==(const Fraction& left, const Fraction& right)
{
	return (((left.get_integer() * left.get_denominator() + left.get_numerator()) * right.get_denominator()) == ((right.get_integer() * right.get_denominator() + right.get_numerator()) * left.get_denominator()));
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return (((left.get_integer() * left.get_denominator() + left.get_numerator()) * right.get_denominator()) != ((right.get_integer() * right.get_denominator() + right.get_numerator()) * left.get_denominator()));
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
	return (((left.get_integer() * left.get_denominator() + left.get_numerator()) * right.get_denominator()) >= ((right.get_integer() * right.get_denominator() + right.get_numerator()) * left.get_denominator()));
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return (((left.get_integer() * left.get_denominator() + left.get_numerator()) * right.get_denominator()) <= ((right.get_integer() * right.get_denominator() + right.get_numerator()) * left.get_denominator()));
}

//#define CONSTRUCTOR_CHECK
//#define COMPARISON_OPERATORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTOR_CHECK

	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(2, 3);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();
#endif // CONSTRUCTOR_CHECK

#ifdef HOME_WORK_1
	Fraction B(2, 3, 4);
	double b = B;
	cout << b << endl;
#endif // HOME_WORK_1

#ifdef HOME_WORK_2
	Fraction B = 2.75;
	cout << B << endl;
#endif // HOME_WORK_2
}
