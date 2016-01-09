/**********************************************************************
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. 
 * If you want a challenge, please do not see below and ask yourself 
 * what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
 * You are responsible to gather all the input requirements up front.
 **********************************************************************
 * 2015 - 12 - 29
 * NJUST Lab4055, NanJing JiangSu
 **********************************************************************/
#include <iostream>
#include <stack>
using namespace std;

#define CPP 0
#if CPP
int myAtoi(string str) {
	int i = 0;
	int l, r;
	int len = str.length();
	int sign = 1;

	while (str[i] == ' '){
		if (++i >= len)
			return 0;
	}
	
	if (str[i] == '-'){
		sign = -1;
		i++;
	}
	else if (str[i] == '+'){
		i++;
	}
	l = i;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	r = i;
	if (l == r)
		return 0;
	long long rst = 0;
	for (i = l; i<r; i++)
	{
		rst = rst * 10 + str[i]-'0';
		if (rst*sign >= INT_MAX)	return INT_MAX;
		if (rst*sign <= INT_MIN)	return INT_MIN;
	}
	return rst*(sign);
}
#else
int myAtoi(char* str) {
	int i = 0;
	int l, r;
	int len = strlen(str);
	int sign = 1;

	while (str[i] == ' '){
		if (++i >= len)
			return 0;
	}

	if (str[i] == '-'){
		sign = -1;
		i++;
	}
	else if (str[i] == '+'){
		i++;
	}
	l = i;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	r = i;
	if (l == r)
		return 0;
	long long rst = 0;
	for (i = l; i<r; i++)
	{
		rst = rst * 10 + str[i] - '0';
		if (rst*sign >= INT_MAX)	return INT_MAX;
		if (rst*sign <= INT_MIN)	return INT_MIN;
	}
	return rst*(sign);
}
#endif

int main(void)
{
#if CPP
	cout << myAtoi("-+1234a") << endl;
#else
	printf("%d\n", myAtoi("  -123456789"));
#endif
}