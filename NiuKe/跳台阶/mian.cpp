/*
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
 * 求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */
#include <iostream>
using namespace std;

#if 0
int jumpFloor(int number)
{
	if (number < 2)
		return 1;
	else
		return jumpFloor(number - 1) + jumpFloor(number - 2);
}
#else 
int jumpFloor(int number)
{
	if (number == 0)
		return 0;
	else if (number == 1)
		return 1;

	int f0 = 1;
	int f1 = 1;
	int f2 = 0;
	for (int i = 2; i <= number; i++)
	{
		f2 = f0 + f1;
		f0 = f1;
		f1 = f2;
	}
	return f2;
}
#endif

int main(void)
{
	cout << jumpFloor(5) << endl;
	return 0;
}