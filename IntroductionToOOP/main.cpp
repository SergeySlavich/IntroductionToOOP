//IntroductionToOOP
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//TODO:
//0. ВЫУЧИТЬ ТЕОРИЮ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//1. В классе Point написать get / set - методы;
//2. В классе Point написать метод ? ? ? distance(? ? ? ), который возвращает расстояние до указанной точки;
//3. Написать функцию ? ? ? distance(? ? ? ), которая возвращает расстояние между двумя точками;

class Point
{
	double x;
	double y;

public:
//1. В классе Point написать get / set - методы;
	void set_x(double x)			//Для примера предусмотрим возможность преобразования заданного числа в положительную координату
	{
		this->x = (x < 0) ? -x : x;
	}
	void set_y(double y)
	{
		this->y = (y < 0) ? -y : y;
	}
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	//			Methods:
//2. В классе Point написать метод ? ? ? distance(? ? ? ), который возвращает расстояние до указанной точки;
	double distance(Point other)const
	{
		// Расстояние между двумя точками в системе координат находим по теореме Пифагора, где расстояние между двумя точками - гипотенуза, разница координат 'x' и 'y' - катеты
		//return sqrt((this->x - other.x) * (this->x - other.x) + (this->y - other.y) * (this->y - other.y));
		return sqrt(pow((this->x - other.x), 2) + pow((this->y - other.y), 2));
	}
};

double distance(Point A, Point B);

void main()
{
	setlocale(LC_ALL, "");

	double x, y;
	Point A, B;
	cout << "\t\t***Домашняя работа***\n\tРасстояние между точками.\n";
	cout << "Введите координаты первой точки 'X' и 'Y':\n"; cin >> x; cin >> y;
	A.set_x(x);
	A.set_y(y);
	cout << "Введите координаты второй точки 'X' и 'Y':\n"; cin >> x; cin >> y;
	B.set_x(x);
	B.set_y(y);
	cout << "Вы ввели:\n";
	cout << "Координаты точки А: " << A.get_x() << '\t' << A.get_y() << endl;
	cout << "Координаты точки В: " << B.get_x() << '\t' << B.get_y() << endl;
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << "Расстояние между точками A и B: " << distance(A, B) << endl;
}

//3. Написать функцию ? ? ? distance(? ? ? ), которая возвращает расстояние между двумя точками;
double distance(Point A, Point B)
{
	/*double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;*/
	return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
}