//IntroductionToOOP
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Point
{
	double x;
	double y;
public:
//1. � ������ Point �������� get / set - ������;
	void set_x(double x)			//��� ������� ������������ ����������� �������������� ��������� ����� � ������������� ����������
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
	//			Constructors:
	//Point()
	//{
	//	//RAII - Resource Aqualisation - Is Inicialisation 
	//	//(��������� �������� - ������ �������������)
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
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//			Methods:
//2. � ������ Point �������� ����� ? ? ? distance(? ? ? ), ������� ���������� ���������� �� ��������� �����;
	double distance(Point other)const
	{
		// ���������� ����� ����� ������� � ������� ��������� ������� �� ������� ��������, ��� ���������� ����� ����� ������� - ����������, ������� ��������� 'x' � 'y' - ������
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

double distance(Point A, Point B);

void main()
{
	setlocale(LC_ALL, "");

	//cout << "Hello OOP" << endl;
#ifdef STRUCT_POINT
	//int a;		//���������� ���������� 'a' nbgf 'int'
	Point A;	// ���������� ���������� 'A' ���� 'Point'
				//��� ���������� ������� 'A'��������� 'Point'
				//��� �������� ���������� 'A' ��������� 'Point'
	//������� ����� �������� ������������ ������ ��� ���������

	Point B;
	A.set_x(3);
	A.set_y(4);
	B.set_x(0);
	B.set_y(0);
	cout << "���������� ����� �: " << A.get_x() << '\t' << A.get_y() << endl;
	cout << "���������� ����� �: " << B.get_x() << '\t' << B.get_y() << endl;
//3. �������� ������� ? ? ? distance(? ? ? ), ������� ���������� ���������� ����� ����� �������;
	double s = A.distance(A, B);
	cout << "���������� ����� ��������� ������� �����: " << s << endl;
#endif

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << A.get_x() << '\t' << A.get_y() << endl;
	cout << "���������� �� ����� � �� ����� �: " << A.distance(B) << endl;
	cout << "���������� �� ����� B �� ����� A: " << B.distance(A) << endl;
	cout << "���������� ����� ������� A � B: " << distance(A, B) << endl;
#endif
	Point A; // default constructor
	A.print();
	Point B(2, 3);
	B.print();
	Point C = 4; //Single-Argument constructor
	C.print();
}

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}