//String.h
#include<iostream>
using namespace std;

#define BASE_CHECK
//#define CALLING_CONSTRUCTORS

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;		//размер строки
	char* str;		//адрес строки в динамической памяти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	//				Constructors:
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other)noexcept;
	~String();
	//				Methods:
	void print()const;
	//				Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);
	const char& operator[](int i)const;
	char& operator[](int i);
	String& operator+=(const String& other);
};