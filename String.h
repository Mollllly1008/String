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

private:
	char* str;
};
#endif
