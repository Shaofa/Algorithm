/*****************************************************************
 * Given a column title as appear in an Excel sheet, 
 * return its corresponding column number.
 * For example :
 * A -> 1
 * B -> 2
 * C -> 3
   ...
 * Z -> 26
 * AA -> 27
 * AB -> 28
 ****************************************************************/
#include <iostream>
#include <string>
using namespace std;

int titleToNumber(string s);

int main(void)
{
	string str = "B";
	cout << str << " -> " << titleToNumber(str) << endl;
	return 0;
}


int titleToNumber(string s)
{
	int num = 0;
	int len = s.length();
	char* str = (char*)s.c_str();
	for (int i = 0; i < len; i++)
	{
		num += (*(str + len - 1 - i) - 'A' + 1) * pow(26, i);
	}
	return num;
}