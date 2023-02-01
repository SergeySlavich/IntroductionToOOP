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
//		Fraction& to_improper();		//целую часть интегрирует в числитель
//		Fraction& to_proper();			//выделяет целую часть из числителя
//		Fraction& reduce();				//сокращает дробь
//3. Перегрузить арифметические операторы : +, -, *, / ;
//4. Перегрузить операторы++ / --;
//5. Перегрузить составные присваивания : =, +=, -=, *=, /=;
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
		this->set_numerator((int)(numerator * 10));
		cout << get_numerator() << "\t numerator\n";
		this->set_denominator(10);
		cout << get_denominator() << "\t denominator\n";
		while (!(numerator - this->get_numerator()))
		{
			numerator *= 10;
			this->set_numerator((int)numerator);
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
//2. Написать методы :
//		Fraction & to_improper();	//целую часть интегрирует в числитель
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()			//сокращает дробь
	{
		this->to_improper();
		for (int i = 2; ; i++)
		{
			if (!(this->get_numerator() % i) && !(this->get_denominator() % i))
			{
				this->set_numerator(this->get_numerator() / i);
				this->set_denominator(this->get_denominator() / i);
			}
		}
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

	/*cout << "Fraction default:\n";
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
	F.print();*/

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

	cout << "\nFraction with double argument:\n";
	Fraction X(1.125);
	X.print();

	cout << endl;
	cout << delimiter;

	/*cout << "\nCorrect fraction to incorrect fraction\n";
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
	cout << delimiter;*/
}
