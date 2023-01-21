//IntroductionToOOP
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//TODO:
//0. ������� ������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//1. � ������ Point �������� get / set - ������;
//2. � ������ Point �������� ����� ? ? ? distance(? ? ? ), ������� ���������� ���������� �� ��������� �����;
//3. �������� ������� ? ? ? distance(? ? ? ), ������� ���������� ���������� ����� ����� �������;

class Point
{
	double x;
	double y;

public:
//1. � ������ Point �������� get / set - ������;
	void set_x(double x)			//��� ������� ������������ ����������� �������������� ��������� ����� � ������������� ����������
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
//2. � ������ Point �������� ����� ? ? ? distance(? ? ? ), ������� ���������� ���������� �� ��������� �����;
	double distance(Point other)const
	{
		// ���������� ����� ����� ������� � ������� ��������� ������� �� ������� ��������, ��� ���������� ����� ����� ������� - ����������, ������� ��������� 'x' � 'y' - ������
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
	cout << "\t\t***�������� ������***\n\t���������� ����� �������.\n";
	cout << "������� ���������� ������ ����� 'X' � 'Y':\n"; cin >> x; cin >> y;
	A.set_x(x);
	A.set_y(y);
	cout << "������� ���������� ������ ����� 'X' � 'Y':\n"; cin >> x; cin >> y;
	B.set_x(x);
	B.set_y(y);
	cout << "�� �����:\n";
	cout << "���������� ����� �: " << A.get_x() << '\t' << A.get_y() << endl;
	cout << "���������� ����� �: " << B.get_x() << '\t' << B.get_y() << endl;
	cout << "���������� �� ����� � �� ����� �: " << A.distance(B) << endl;
	cout << "���������� �� ����� B �� ����� A: " << B.distance(A) << endl;
	cout << "���������� ����� ������� A � B: " << distance(A, B) << endl;
}

//3. �������� ������� ? ? ? distance(? ? ? ), ������� ���������� ���������� ����� ����� �������;
double distance(Point A, Point B)
{
	/*double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;*/
	return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
}