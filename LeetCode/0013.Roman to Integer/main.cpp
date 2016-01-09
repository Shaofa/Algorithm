/**********************************************************************
 * Given a roman numeral, convert it to an integer.
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
#include <map>
using namespace std;
#if 1
int romanToInt(string s) {
	
	map< string, int> m;
	map<char, int> base;
	m["M"] = 1000, m["MM"] = 2000, m["MMM"] = 3000;
	m["C"] = 100,	m["CC"] = 200,	m["CCC"] = 300, m["CD"] = 400,	m["D"] = 500,	m["DC"] = 600,	m["DCC"] = 700,	m["DCCC"] = 800, m["CM"] = 900;
	m["X"] = 10,	m["XX"] = 20,	m["XXX"] = 30,	m["XL"] = 40,	m["L"] = 50,	m["LX"] = 60,	m["LXX"] = 70,	m["LXXX"] = 80, m["XC"] = 90;
	m["I"] = 1,		m["II"] = 2,	m["III"] = 3,	m["IV"] = 4,	m["V"] = 5,		m["VI"] = 6,	m["VII"] = 7,	m["VIII"] = 8, m["IX"] = 9;
	base['I'] = 1, base['V'] = 2, base['X'] = 3, base['L'] = 4, base['C'] = 5, base['D'] = 6, base['M'] = 7;

	int len = s.length();
	int n = 0;
	char ss[64] = { 0 };
	char tmp[64] = { 0 };
	strcpy(ss, s.c_str());
	char *r = ss + len - 1;
	char *l = r;
	while (l >= ss)
	{
		while (base[*(l-1)] <= base[*l] && (l-1)>=ss)
		{
			l--;
		}
		memset(tmp, 0, sizeof(tmp));
		strncpy(tmp, l, r - l+1);
		n += m[tmp];
		r = l-1;
		*l = '\0';
		l = r;
	}
	return n;
}
#else

#endif
int main(void)
{
	cout << romanToInt("MCDLXXVI") << endl;
	return 0;
}