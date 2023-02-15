//Fraction
#include<iostream>
#include<windows.h>
using namespace std;

//TODO:
//ВЫУЧИТЬ ТЕОРИЮ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Проверочный код должен заработать:
// #define HOME_WORK_1
// #define HOME_WORK_2
//В классе Fraction реализовать :
//1. Конструкторы и вывод на экран;
// #define CONSTRUCTORS
//		5;		//double a = 5;
//		1 / 2;
//		2(3 / 4);
//2. Написать методы :
// #define METHODS
//		Fraction& to_improper();		//целую часть интегрирует в числитель
//		Fraction& to_proper();			//выделяет целую часть из числителя
//		Fraction& reduce();				//сокращает дробь
//3. Перегрузить арифметические операторы : +, -, *, / ;
// #define OPERATORS
//4. Перегрузить операторы++ / --;
// #define IN_DE_CREMENTS
//5. Перегрузить составные присваивания : =, +=, -=, *=, /=;
// #define ASSIGNMENTS
//6. Перегрузить операторы сравнения : == , != , > , < , >= , <= ;
// #define COMPARISONS
//7. Перегрузить оператор ввода с клавиатуры;
// #define INPUT_FRACTIONS

#define delimiter "\n----------------------------------------------------\n"

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
	Fraction(double integer = 0)								//Конструктор с одним аргументом создает целое число: integer или конструктор по умолчанию
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
	Fraction(int numerator, int denominator)			//Конструктор с двумя аргументами создает дробь без целой части: numerator/denominator
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
	Fraction(int integer, int numerator, int denominator)//Конструктор с тремя аргументами создает дробь с целой частью: integer(numerator/denominator)
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
	Fraction(Fraction& other)
	{
		this->set_integer(other.get_integer());
		this->set_numerator(other.get_numerator());
		this->set_denominator(other.get_denominator());
		//cout << "CopyConstructor" << endl;
	}
	~Fraction()
	{
		//cout << "Destructor\t\t" << this << endl;
	}

	//1. Вывод на экран;
		//						Methods:
	void print()const
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
	Fraction& operator++()
	{
		if (!integer) this->set_numerator(get_numerator() + get_denominator());
		else this->set_integer(this->get_integer() + 1);
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		if (!integer) this->set_numerator(get_numerator() + get_denominator());
		else this->set_integer(this->get_integer() + 1);
		return old;
	}
	Fraction& operator--()
	{
		if (!integer) this->set_numerator(get_numerator() - get_denominator());
		else this->set_integer(this->get_integer() - 1);
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		if (!integer) this->set_numerator(get_numerator() - get_denominator());
		else this->set_integer(this->get_integer() - 1);
		return old;
	}
	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}

	//5. Перегрузить присваивания: =, +=, -=, *=, /=;
	Fraction operator=(const Fraction& other)
	{
		Fraction res(other);
		//cout << "operator=\n";
		return res;
	}
	Fraction& operator+=(const Fraction& other)
	{
		Fraction res;
		res = *this + other;
		*this = res;
		return *this;
	}
	Fraction& operator-=(const Fraction& other)
	{
		Fraction res;
		res = *this - other;
		*this = res;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		Fraction res;
		res = *this * other;
		*this = res;
		return *this;
	}
	Fraction& operator/=(const Fraction& other)
	{
		Fraction res;
		res = *this / other;
		*this = res;
		return *this;
	}
	//Проверочный код должен заработать:
	//	Преобразование типов
	operator int()const
	{
		Fraction res;
		res.set_integer(this->get_integer());
		res.set_numerator(this->get_numerator());
		res.set_denominator(this->get_denominator());
		res.to_proper();
		return res.get_integer();
	}
	explicit operator double()const
	{
		/*Fraction res;
		res.set_integer(this->get_integer());
		res.set_numerator(this->get_numerator());
		res.set_denominator(this->get_denominator());
		res.to_improper();
		return (double) res.get_numerator() / res.get_denominator();*/
		return integer + (double)numerator / denominator;
	}

	std::istream& operator>>(std::istream& is)
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
};

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

//#define HOME_WORK_0
//#define HOME_WORK_1
#define HOME_WORK_2

void main()
{
	setlocale(LC_ALL, "");

	cout << "***HOME WORK CONVERSION***\n";
	cout << "\n******************************************************\n";
#ifdef HOME_WORK_0
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
#endif

#ifdef HOME_WORK_1
	// CONVERSION_FROM_CLASS_TO_OTHER
	cout << "Conversion Fraction to int:\n";
	Fraction A(11, 4);
	A.print();
	int a = (int)A;
	cout << a << endl;

	cout << delimiter << endl;
	cout << "Conversion Fraction to double:\n";
	Fraction B(2, 3, 4);
	B.print();
	double b = B;
	cout << b << endl;
#endif // HOME_WORK_1

#ifdef HOME_WORK_2
	cout << delimiter << endl;
	cout << "Conversion from other to class:\n";
	Fraction C = 2.75;
	cout << C << endl;
#endif // HOME_WORK_2

}
