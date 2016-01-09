/**********************************************************************
 * Given an integer, convert it to a roman numeral.
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 * 
 * I(1),V(2),X(10),L(50),C(100),D(500),M(1000)
 * VII=7, XII=12, CII=102
 * IIV=3, IIX=8, IIC=98
 * MCMLXXX=1980
 **********************************************************************
 * 2015 - 12 - 29
 * NJUST Lab4055, NanJing JiangSu
 **********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
#define C	1
#if C
char* intToRoman(int num) {
	int n = num;
	int dig[4] = { 0 };
	char* rom[4][9] = {
		{"M","MM","MMM"},
		{ "C", "CC", "CCC", "CD" , "D", "DC", "DCC", "DCCC", "CM" },	// 900~100
		{ "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },	// 90~10
		{ "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" }	// 9~1
	};
	char *rst = (char*)malloc(100);
	int i = 3;
	while (n){
		dig[i--] = n % 10;
		n /= 10;
	}

	for (i = 0; i < 4; i++)
	{
		if (dig[i] == 0)
			continue;
		else
			strcat(rst, rom[i][dig[i] - 1]);
	}
	return rst;
}
#else
string intToRoman(int num) {
	int n = num;
	int dig[4] = { 0 };
	string rom[4][9] = {
		{"M","MM","MMM"},
		{ "C", "CC", "CCC", "CD" , "D", "DC", "DCC", "DCCC", "CM" },	// 900~100
		{ "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },	// 90~10
		{ "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" }	// 9~1
	};
	string rst;
	int i = 3;
	while (n){
		dig[i--] = n % 10;
		n /= 10;
	}
	
	for (i = 0; i < 4; i++)
	{
		if (dig[i] == 0)
			continue;
		else
			rst.append(rom[i][dig[i]-1]);
	}
	return rst;
}
#endif

int main(void)
{
	cout << intToRoman(1234) << endl;
	return 0;
}