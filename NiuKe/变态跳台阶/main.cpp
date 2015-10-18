
/*
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
 * 求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */
#include <iostream>
#include <vector>
using namespace std;

int jumpFloorII(int number) 
{
	vector<int> a(number+1);
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i <= number; i++)
	{
		for (int j = 0; j < i; j++)
		{
			a[i] += a[j];
		}
	}
	return a[number];
}

int main(void)
{
	cout << jumpFloorII(5) << endl;
	return 0;
}