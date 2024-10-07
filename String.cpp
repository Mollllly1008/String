//String.cpp
#include "String.h"
#include <cstring>
#include <iomanip>
String::String(const char* s)
{
	str = new char[strlen(s) + 1];
	strcpy(str, s);
}

String::String(const String& Str, int pos, int n)
{
	int i, m;
	m = strlen(Str.str);
	if (pos > m)
	{
		str = new char[1];
		str[0] = '\0';
		return;
	}
	if (m - pos < n) n = m - pos;
	if (n < 0) n = 0;
	str = new char[n + 1];
	for (i = 0; i < n; i++)
		str[i] = Str.str[pos + i];
	str[i] = '\0';
}

String::String(const char* s, int n)
{
	int i, m = strlen(s);
	if (m < n) n = m;
	if (n < 0) n = 0;
	str = new char[n + 1];
	for (i = 0; i < n; i++)
		str[i] = s[i];
	str[i] = '\0';
}

String::String(int n, char c)
{
	int i;
	if (n < 0) n = 0;
	str = new char[n + 1];
	for (i = 0; i < n; i++)
		str[i] = c;
	str[i] = '\0';
}

String::String(const String& Str)
{
	str = new char[strlen(Str.str) + 1];
	strcpy(str, Str.str);
}

String& String::operator=(const String& Str)
{
	if (&Str == this) return *this;
	delete[] str;
	str = new char[strlen(Str.str) + 1];
	strcpy(str, Str.str);
	return *this;
}

String::~String()
{
	if (str != NULL)
		delete[] str;
}
String & String::insert(int p0, const char *s)
{
	int n = strlen(str);
	if(p0 > n) p0 = n;
	char *p = new char[strlen(str)+strlen(s)+1];
	strncpy(p, str, p0);		// 原字符串内容的第一部分
	p[p0] = '\0';
	strcat(p, s);				// 插入的部分
	strcat(p, str+p0);			// 原字符串的剩余部分
	delete [] str;				// 释放原字符串
	str	= p;					// 保存新字符串的首地址
	return *this;
}

String String::substr(int pos, int n) const//取子串
{
	String temp(*this, pos, n);
	return temp;
}

int String::find(const String &Str) const//找到字符串的位置
{
	int i, j, m, n, flag;
	m = strlen(Str.str);
	n = strlen(str);
	if(m > n) return -1;
	for(i=0; i<n-m; i++)
	{
		flag = 1;
		for(j=0; j<m; j++)
			if(str[i+j]!=Str.str[j])
			{
				flag = 0;
				break;
			}
		if(flag==1)
			return i;
	}
	return -1;
}

int String::length () const//统计字符串长度
{
	return strlen(str);
}

const char * String::c_str()//变C_字符串
{
	return str;
}

void String::swap(String &Str)//交换
{
	char *temp = Str.str;
	Str.str = str;
	str = temp;
}

void String::reverse()//反转
{
	if (str == nullptr) return;  // 如果字符串为空，则不执行任何操作  

	char* start = str;
	char* end = str + length - 1;
	char temp;

	while (start < end) {
		temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
}

int String::times(const String& Str) const//统计字符出现次数
{
	int i, j, m, n, flag , k=0;
	m = strlen(Str.str);
	n = strlen(str);
	if (m > n) return 0;            //字符串次数为0
	for (i = 0; i < n - m; i++)
	{
		flag = 1;
		for (j = 0; j < m; j++)
			if (str[i + j] != Str.str[j])
			{
				flag = 0;
				break;
			}
		if (flag == 1)
			k++;
	}
	return k;
}

void String::up_to_low()//字符串小写转换
{
	for (size_t i = 0; i < str.lengh(); ++i)
	{
		if (str[i] <= 'Z' && str[i] >= 'A')
			str[i] = str[i] + 'a' - 'A';
			
	}
}

void String::low_to_up()//字符串大写转换
{
	for (size_t i = 0; i < str.lengh(); ++i)
	{
		if (str[i] <= 'z' && str[i] >= 'a')
			str[i] = str[i] + 'A' - 'a';

	}
}

ostream& operator<<(ostream& out, const String& Str)
{
	out << Str.str;
	return out;
}

istream& operator>>(istream& in, String& Str)
{
	char str[1000];
	in >> str;
	Str = str;				// 利用转换构造函数（自动转换），再利用赋值运算
	return in;
}

char & String::operator[](int index)		// 重载方括号运算符
{
	return str[index];
}

String operator+(const String &Str1, const String &Str2)
{
	String temp;
	temp.str = new char[strlen(Str1.str)+strlen(Str2.str)+1];
										// 自动扩展资源空间
	strcpy(temp.str, Str1.str);
	strcat(temp.str, Str2.str);
	return temp;
}

String & String::operator+=(const String &Str)
{
	*this = *this + Str;
	return *this;	
}

bool operator==(const String &Str1, const String &Str2)
{
	return strcmp(Str1.str, Str2.str)==0;
}

bool operator!=(const String &Str1, const String &Str2)
{
	return strcmp(Str1.str, Str2.str)!=0;
}

bool operator> (const String &Str1, const String &Str2)
{
	return strcmp(Str1.str, Str2.str) > 0;
}

bool operator>=(const String &Str1, const String &Str2)
{
	return strcmp(Str1.str, Str2.str) >= 0;
}

bool operator< (const String &Str1, const String &Str2)
{
	return strcmp(Str1.str, Str2.str) < 0;
}

bool operator<=(const String &Str1, const String &Str2)
{
	return strcmp(Str1.str, Str2.str) <= 0;
}
