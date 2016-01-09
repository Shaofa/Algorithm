/**********************************************************************
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 **********************************************************************
 * 2015 - 12 - 29
 * NJUST Lab4055, NanJing JiangSu
 **********************************************************************/
#include <iostream>
#include <stack>
using namespace std;

#define CPP 0
#if CPP
int reverse(int x) {
	stack<int> s;
	long long n = llabs(x);
	while (n)
	{
		s.push(n % 10);
		n /= 10;
	}
	int i = 0;
	long long rst = 0;
	while (!s.empty())
	{
		rst += (long long)pow(10, i++)*s.top();
		s.pop();
	}
	rst = rst > (((long long)1 << 31) - 1) ? 0 : rst;
	rst *= x > 0 ? 1 : -1;
	return (int)rst;
}
#else
int reverse(int x) 
{
	long long n = llabs(x);
	char dig[11] = { 0 };
	int len = 0;
	while (n)
	{
		dig[len++] = n % 10;
		n /= 10;
	}
	int i = len;
	long long rst = 0;
	while (i>=0)
	{
		rst += (long long)pow(10, len-i-1)*dig[i];
		i--;
	}
	rst = rst > (((long long)1 << 31) - 1) ? 0 : rst;
	rst *= x > 0 ? 1 : -1;
	return (int)rst;
}
#endif

int main(void)
{
	int x = 0x8fffff;
#if CPP
	cout << x << endl;
	cout << reverse(x) << endl;
#else
	printf("%d\n%d\n", x, reverse(x));
#endif
	return 0;
}