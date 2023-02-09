#include<iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;		//размер строки
	char* str;		//адрес строки в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	//				Constructors:
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;//функция strlen возвращает размер строки в символах, но в классе хранится размер строки в Байтах, т.е. с учетом 0 в конце строки
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = str[i];
		cout << "1ArgConstructor:\t" << this << endl;
	}
	String(const String& other)
	{
		//Deep Copy
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << endl;
	}
	String(String&& other)noexcept
	{
		//Shallow Copy
		this->size = other.size;
		this->str = other.str;		//Shallow copy
		other.size = 0;
		other.str = nullptr;		//nullptr - это указатель на 0
		cout << "MoveConstructor:" << this << endl;
	}
	~String()
	{
		delete this->str;
		cout << "Destructor:\t" << this << endl;
	}

	//				Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
	//				Operators:
	String& operator=(const String& other)
	{
		//			l-value = r-value;
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}

	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}

	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}
};

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}

#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK
	//String str1(5);
	//str1.print();

	String str1 = "Hello"; //"Hello" - это строковая константа
	str1 = str1;
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;

	/*str1 += str2;
	cout << str1 << endl;*/

	String str3;
	str3 = str1 + str2;		//MoveConstructor
	cout << str3 << endl;

	String str4 = str3;	//CopyConstructor

	/*str1 = str3;
	cout << str1 << endl;*/
#endif

	String str1;			//Default constructor
	str1.print();
	String str2 = "Hello";	//Single argument constructor
	str2.print();
	String str3 = str2;		//CopyConstructor
	str3.print();
	String str4();			//Здесь не вызывается конструктор, 
							//потому что не создается объект
							//Здесь объявляется функция str4(), которая не принимает никаких параметров,
							//и возвращает значение типа String.
	//str4.print();			//str4 - это не объект, это функция, а для функции нельзя вызвать метод.
	//если мы хотим явно вызвать конструктор по умолчанию, то это можно сделат так:
	String str5{};			//Явный вызов конструктора по умолчанию.
	str5.print();
	String str6{ 22 };
	str6.print();
	String str7{ "World" };
	str7.print();
	String str8{ str7 };	//Copy constructor
}