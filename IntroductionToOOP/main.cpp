//IntroductionToOOP
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-----------------------------------------------------------------\n"

class Point
{
	double x;
	double y;
public:
//1. В классе Point написать get / set - методы;
	void set_x(double x)			//Для примера предусмотрим возможность преобразования заданного числа в положительную координату
	{
		if (x < 0) this->x = -x;
		else this->x = x;
	}
	void set_y(double y)
	{
		if (y < 0) this->y = -y;
		else this->y = y;
	}
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}

	//						Constructors:
	//Point()
	//{
	//	//RAII - Resource Aqualisation - Is Inicialisation 
	//	//(Выделение ресурсов - значит инициализация)
	//	x = y = 0;
	//	cout << "DefConstructor:\t" << this << endl;
	//}
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//						Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Point& operator++()
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}
	Point& operator()(double x, double y)
	{
		set_x(x);
		set_y(y);
		return *this;
	}

	//						Methods:
//2. В классе Point написать метод ? ? ? distance(? ? ? ), который возвращает расстояние до указанной точки;
	double distance(const Point& other)const
	{
		// Расстояние между двумя точками в системе координат находим по теореме пифагора, где расстояние между двумя точками - гипотенуза, разница координат 'x' и 'y' - катеты
		return sqrt((this->x - other.x) * (this->x - other.x) + (this->y - other.y) * (this->y - other.y));
		//return sqrt(pow((this->x - other.x), 2) + pow((this->y - other.y), 2));
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK_1
//#define ASSIGNMENT_CHECK_2
#define A1

double distance(const Point& A, const Point& B);
Point operator+(const Point& left, const Point& right);
bool operator==(const Point& left, const Point& right);
bool operator!=(const Point& left, const Point& right);
std::ostream& operator<<(std::ostream& os, const Point& obj);
std::istream& operator>>(std::istream& is, Point& obj);

void main()
{
	setlocale(LC_ALL, "");

	//cout << "Hello OOP" << endl;
#ifdef STRUCT_POINT
	//int a;		//Объявление переменной 'a' nbgf 'int'
	Point A;	// Объявление переменной 'A' типа 'Point'
				//или объявление объекта 'A'структуры 'Point'
				//или создание экземпляра 'A' струткуры 'Point'
	//Объекты часто называют экземплярами класса или структуры

	Point B;
	A.set_x(3);
	A.set_y(4);
	B.set_x(0);
	B.set_y(0);
	cout << "Координаты точки А: " << A.get_x() << '\t' << A.get_y() << endl;
	cout << "Координаты точки В: " << B.get_x() << '\t' << B.get_y() << endl;
//3. Написать функцию ? ? ? distance(? ? ? ), которая возвращает расстояние между двумя точками;
	double s = A.distance(A, B);
	cout << "Расстояние между заданными точками равно: " << s << endl;
#endif

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << '\t' << A.get_y() << endl;
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << '\t' << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками A и B: " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и A: " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif

#ifdef CONSTRUCTORS_CHECK
	Point A; // default constructor
	A.print();
	Point B(2, 3);
	B.print();
	Point C = 4; //Single-Argument constructor
	C.print();
	Point D = C;
	D.print();
#endif

#ifdef ASSIGNMENT_CHECK_1
	Point A(2, 3);
	A.print();
	Point B = A;		//CopyConstructor
	B.print();
	Point C;			//DefaultConstructor
	C = B;				//Assignment operator
	C.print();
#endif

#ifdef ASSIGNMENT_CHECK_2
	int a, b, c;
	a = b = c = 0;

	cout << delimiter << endl;
	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	//Point(2, 3) - явный вызов конструктора, и этот конструктор создает временный безымянный объект
	//Временные безымянные объекты существуют в пределах одного выражения
	cout << delimiter << endl;
#endif

#ifdef A1
	//int a = 2;
	//int b = 3;
	//int c = a + b;

	//Point A(2, 3);
	//Point B(4, 5);
	////Point C = A + B;
	////C.print();
	////C++;
	////C.print();
	//cout << (A != B) << endl;

	Point A(2, 3);
	A.print();

	//A.set_x(12);
	//A.set_y(13);
	//A.print();

	A(22, 33);
	//A.print();
	cout << A << endl;

	cout << "Введите координаты точки: ";
	cin >> A;		//cin - объект класса istream
	cout << A << endl;

#endif
}

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

Point operator+(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
}

//						Comparison operators:
bool operator==(const Point& left, const Point& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else
		return false;*/
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}

bool operator!=(const Point& left, const Point& right)
{
	return !(left == right);
}

std::ostream& operator<<(std::ostream& os, const Point& obj)
{
	return os << "X = " << obj.get_x() << "\tY = " << obj.get_y();
}

std::istream& operator>>(std::istream& is, Point& obj)
{
	double x, y;
	is >> x >> y;
	obj(x, y);
	return is;
}