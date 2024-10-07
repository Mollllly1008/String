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
	String& insert(int p0, const char* s);			// 将 s 所指向的字符串插入在本串位置 p0 之前
	String substr(int pos, int n) const;			// 取子串，取本串位置 pos 开始的 n 个字符，构成新对象
	int find(const String& Str) const;				// 查找并返回 Str 在本串中第一次出现的位置
	int length() const;							// 返回串的长度（字符个数）
	const char* c_str();							// 转换为 C-字符串
	void swap(String& Str);							// 将本串与 Str 交换
	void reverse();                      //字符串顺序反转
	int times(const String& Str) const;                   //统计字符出现的次数
	void up_to_low();                    //字符串小写转换
	void low_to_up();                    //字符串大写转换
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
