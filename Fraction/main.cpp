//FractionSeparation
#include<iostream>
#include<windows.h>
#include"Fraction.h"
using namespace std;

//TODO:
//Создать ветку FractionSeparation и в этой ветке разделить класс Fraction на файлы;

#define delimiter "\n----------------------------------------------------\n"

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
	double b = (double)B;
	cout << b << endl;
#endif // HOME_WORK_1

#ifdef HOME_WORK_2
	cout << delimiter << endl;
	cout << "Conversion from other to class:\n";
	Fraction C = 2.75;
	C.print();
#endif // HOME_WORK_2

}
