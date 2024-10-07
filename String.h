//String.h
#ifndef MY_STRING_H
#define MY_STRING_H
#include <iostream>
using namespace std;

class String
{
public:
	String(const char *s="");						// 构造函数
	String(const String &Str, int pos, int n);
	String(const char *s, int n);
	String(int n, char c);
	String(const String &Str);						// 拷贝构造函数
	String & operator=(const String &Str);			// 必须为成员函数
	virtual ~String();								// 析构函数（虚函数）
        friend ostream & operator<<(ostream &out, const String &Str);
	friend istream & operator>>(istream &in, String &Str);
        char & operator[](int index);					// 方括号（下标）运算符。引用返回可作左值、右值
	friend String operator+(const String &str1, const String &Str2); // 友元函数，字符串拼接
	String & operator+=(const String &Str);			// 字符串拼接及赋值
	// 重载关系运算
	friend bool operator==(const String &Str1, const String &Str2);
	friend bool operator!=(const String &Str1, const String &Str2);
	friend bool operator> (const String &Str1, const String &Str2);
	friend bool operator>=(const String &Str1, const String &Str2);
	friend bool operator< (const String &Str1, const String &Str2);
	friend bool operator<=(const String &Str1, const String &Str2);
private:
	char* str;
};
#endif
