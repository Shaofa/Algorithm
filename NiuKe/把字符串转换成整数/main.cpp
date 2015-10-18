/*
 * 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
 */

#include <string>
#include <iostream>
using namespace std;

int StrToInt(string str) 
{
	int len = str.length();
	int rst = 0;
	int end = 0;
	if (len == 0)
		return 0;
	if (str.at(0) == '+' || str.at(0) == '-')
		end = 0;
	else
		end = -1;
	for (int i = len - 1; i>end; i--)
	{
		if (str.at(i) < '0' || str.at(i) > '9')
			return 0;
		rst += (int)(str.at(i) - '0')*pow(10, len - 1 - i);
	}

	rst *= (str.at(0) == '-' ? -1 : 1);
	return rst;
}

int main(void)
{
	cout << StrToInt("a") << endl;
	return 0;
}