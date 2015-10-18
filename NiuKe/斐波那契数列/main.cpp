/*
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
 */
#include <iostream>
using namespace std;

#if 1
int Fibonacci(int n)
{
	int sum = 0;
	if (n==0)
		return 0;
	else if (n==1)
		return 1;
	else
	{
		int sum1 = 0;
		int sum2 = 1;
		while (n-- > 1)
		{
			sum = sum1 + sum2;
			sum1 = sum2;
			sum2 = sum;
		}
	}
	return sum;
}
#else
int Fibonacci(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return (Fibonacci(n - 1) + Fibonacci(n - 2));
}
#endif
int main(void)
{
	cout << Fibonacci(45) << endl;
	return 0;
}