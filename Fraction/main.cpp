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
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
//В классе Fraction реализовать :
//1. Конструкторы;
	//					Constructors:
	Fraction()											//Конструктор по умолчанию создает дробь: 0(0/1)
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		//cout << "default constructor\t" << this << endl;
	}
	Fraction(int integer)								//Конструктор с одним аргументом создает целое число: integer
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		//cout << "1 arg constructor\t" << this << endl;
	}
	Fraction(int numerator, int denominator)			//Конструктор с двумя аргументами создает дробь без целой части: numerator/denominator
	{
		this->integer = 0;
		if (denominator < 0 && numerator != 0)
		{
			this->numerator = -numerator;
			this->denominator = -denominator;
		}
		else
		{
			this->numerator = numerator;
			this->denominator = denominator;
		}
		if (numerator == 0)								//Если числитель равен 0, конструктор создает дробь 0(0/1)
		{
			Fraction();
		}
		else
		{												//Если числитель не равен 0, конструктор создает дробь: numerator/denominator
			this->numerator = numerator;
			if (denominator == 0) this->denominator = 1;//Если знаменатель равен 0, конструктор создает целое число
			else this->denominator = denominator;
		}
		//cout << "2 arg constructor\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)//Конструктор с тремя аргументами создает дробь с целой частью: integer(numerator/denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		if (integer == 0) Fraction(numerator, denominator);
		else if (numerator == 0) Fraction(integer);
		else if (denominator == 0)
		{
			this->denominator = 1;
			if ((integer < 0 && numerator < 0) || (integer > 0 && numerator > 0)) integer += numerator;
			else integer = -(integer + numerator);
			Fraction(integer);
		}
		else
		{
			if (integer < 0 && numerator < 0 && denominator < 0)
			{
				this->integer = integer;
				this->numerator = -numerator;
				this->denominator = -denominator;
			}
			else if (integer < 0 && numerator > 0 && denominator > 0)
			{
				this->integer = integer;
				this->numerator = numerator;
				this->denominator = denominator;
			}
			else if (integer > 0 && numerator < 0 && denominator > 0)
			{
				this->integer = -integer;
				this->numerator = -numerator;
				this->denominator = denominator;
			}
			else if (integer > 0 && numerator > 0 && denominator < 0)
			{
				this->integer = -integer;
				this->numerator = numerator;
				this->denominator = -denominator;
			}
			else
			{
				this->integer = integer;
				this->numerator = numerator;
				this->denominator = denominator;
			}
		}
		//cout << "3 arg constructor\t" << this << endl;
	}

//1. Вывод на экран;
	//						Methods:
	void print()const							//0(y/z); x(y/z); x(0/z); 0(0/z);
	{
		if (get_numerator() == 0) cout << ' ' << get_integer() << ' ';
		else if (get_integer() == 0) cout << ' ' << get_numerator() << '/' << get_denominator() << ' ';
		else cout << ' ' << get_integer() << '(' << get_numerator() << '/' << get_denominator() << ')' << ' ';
	}
//2. Написать методы :
//		Fraction & to_proper();	//целую часть интегрирует в числитель
	Fraction& to_proper()
	{
		if (get_integer() == 0)	return *this;
		Fraction res;
		res.set_denominator(this->get_denominator());
		res.set_numerator(this->get_integer() * this->get_denominator() + this->get_numerator());
		res.set_integer(0);
		*this = res;
		return *this;
	}
//		Fraction& to_improper();//выделяет целую часть из числителя
	Fraction& to_improper()
	{
		if (get_numerator() < get_denominator()) return *this;
		Fraction res;
		res.set_integer(this->get_numerator() / this->get_denominator() + this->get_integer());
		res.set_numerator(this->get_numerator() % this->get_denominator());
		res.set_denominator(this->get_denominator());
		*this = res;
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
Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction res;
	res.set_numerator((left.get_integer() * left.get_denominator() + left.get_numerator()) * (right.get_integer() * right.get_denominator() + right.get_numerator()));
	res.set_denominator(left.get_denominator() * right.get_denominator());
	res.to_improper();
	return res;
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

void main()
{
	setlocale(LC_ALL, "");

	cout << "***HOME WORK FRACTION***\n";
	cout << "\nConstructors:\n";

	cout << "Fraction default:\n";
	Fraction A;
	A.print();

	cout << "\nFraction with 1 argument:\n";
	Fraction B(1);
	B.print();

	cout << "\nFraction with 2 arguments:\n";
	Fraction C(2, 3);
	C.print();

	cout << "\nFraction with 3 arguments:\n";
	Fraction D(4, 5, 6);
	D.print();

	cout << "\nIncorrect fraction:\n";
	Fraction E(14, 4);
	E.print();

	cout << "\nFraction with zero integer and 1 arguments:\n";
	Fraction F(0);
	F.print();

	cout << "\nFraction with zero integer and 3 arguments:\n";
	Fraction G(0, 3, 5);
	G.print();

	cout << "\nFraction with zero numerator and 2 arguments:\n";
	Fraction H(0, 7);
	H.print();

	cout << "\nFraction with zero numerator and 3 arguments:\n";
	Fraction J(3, 0, 9);
	J.print();

	cout << "\nFraction with zero denominator:\n";
	Fraction K(4, 6, 0);
	K.print();

	cout << endl;
	cout << delimiter;

	cout << "\nCorrect fraction to incorrect fraction\n";
	D.print();
	D.to_proper();
	cout << " => ";
	D.print();
	cout << endl;
	cout << delimiter;
	
	cout << "\nIncorrect fraction to correct fraction\n";
	E.print();
	E.to_improper();
	cout << " => ";
	E.print();
	cout << endl;
	cout << delimiter;

	Fraction M(2, 1, 2);
	Fraction N(2, 1, 3);
	//cout << M.to_proper() << '\t' << N.to_proper() << endl;
	cout << M << '\t' << N << endl;

	cout << "\n*Fraction addition*\n";
	cout << M << " + " << N << " = " << M + N << endl;
	cout << delimiter;

	cout << "\n*Fraction subtraction*\n";
	cout << M << " - " << N << " = " << M - N << endl;
	cout << delimiter;
	
	cout << "\n*Fraction multiple*\n";
	cout << M << " * " << N << " = " << M * N << endl;
	cout << delimiter;

	cout << "\n*Fraction divided*\n";
	cout << M << " / " << N << " = " << M / N << endl;
	cout << delimiter;

	cout << "\n*Prefix increment*\n";
	cout << "before " << M << "\t => ";
	cout << ++M << endl;
	cout << "after " << M << endl;
	cout << "\n*Postfix increment*\n";
	cout << "before " << M << "\t => ";
	cout << M++ << '\t' << M << endl;
	cout << "after " << M << endl;
	cout << "\n*Prefix decrement*\n";
	cout << "before " << M << "\t => ";
	cout << --M << endl;
	cout << "after " << M << endl;
	cout << "\n*Postfix decrement*\n";
	cout << "before " << M << "\t => ";
	cout << M-- << '\t' << M << endl;
	cout << "after " << M << endl;
	cout << delimiter;

	cout << "\n*Overload assignment*\n";
	Fraction P(1, 1, 2);
	Fraction R(2);
	cout << "before += : " << P << '\t' << R << endl;
	P += R;
	cout << "after += : " << P << '\t' << R << endl;
	cout << "before -= : " << P << '\t' << R << endl;
	P -= R;
	cout << "after -= : " << P << '\t' << R << endl;
	cout << "before *= : " << P << '\t' << R << endl;
	P *= R;
	cout << "after *= : " << P << '\t' << R << endl;
	cout << "before /= : " << P << '\t' << R << endl;
	P /= R;
	cout << "after /= : " << P << '\t' << R << endl;
	cout << delimiter;

	cout << "\n*Overload operators ==, !=, >, <, >=, <=.*\n";
	Fraction S(2, 1, 2);
	Fraction T(2, 1, 2);
	Fraction U(2, 3, 4);
	cout << "S = " << S << "\tT = " << T << "\tU = " << U << endl;
	cout << "S == T => " << (S == T) << endl;
	cout << "S == U => " << (S == U) << endl;
	cout << "S != T => " << (S != T) << endl;
	cout << "S != U => " << (S != U) << endl;
	cout << "S > T => " << (S > T) << endl;
	cout << "S > U => " << (S > U) << endl;
	cout << "S < T => " << (S < T) << endl;
	cout << "S < U => " << (S < U) << endl;
	cout << "S >= T => " << (S >= T) << endl;
	cout << "S >= U => " << (S >= U) << endl;
	cout << "S <= T => " << (S <= T) << endl;
	cout << "S <= U => " << (S <= U) << endl;
	cout << delimiter;

	cout << "\n*input from keyboard*\n";
	cout << "Введите 3 числа: ";
	int integer, numerator, denominator;
	cin >> integer >> numerator >> denominator;
	Fraction V(integer, numerator, denominator);
	cout << "\nВы ввели " << V << endl;
	cout << delimiter;
}
