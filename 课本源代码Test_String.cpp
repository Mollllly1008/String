// Test_String.cpp
#include "String.h"

int main()
{
	String str1="world.", str2, str3;
	
	str2 = str1;
	str2[0] = 'W';
	cout << "\"" << str1 << "\"" << endl;
	cout << "\"" << str2 << "\"" << endl;

	str2 = "Hello, " + str2;
	str1 = str1;
//	str3 = "C++ " + "programm"; 
	str3 = String("C++ ") + "programm"; 	// OK
	str3 = "C++ " + String("programm");		// OK
	cout << "\"" << str1 << "\"" << endl;
	cout << "\"" << str2 << "\"" << endl;
	cout << "\"" << str3 << "\"" << endl;
	
	cout << &(str1[0]) << endl;
	
	cout << "Input a string: ";
	getline(cin, str1, 80);
	cout << "\"" << str1 << "\"" << endl;

	return 0;
}
