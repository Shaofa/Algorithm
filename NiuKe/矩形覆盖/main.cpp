/*
 * 我们可以用2 * 1的小矩形横着或者竖着去覆盖更大的矩形。
 * 请问用n个2 * 1的小矩形无重叠地覆盖一个2 * n的大矩形，总共有多少种方法？
 */

#include <iostream>
using namespace std;

int rectCover(int number) 
{
	if (number < 3)
		return number;
	else
	{
		int n0 = 1;
		int n1 = 2;
		int n2 = 0;
		for (int i = 3; i <= number; i++)
		{
			n2 = n0 + n1;
			n0 = n1;
			n1 = n2;
		}
		return n2;
	}
}

int main(void)
{
	cout << rectCover(6) << endl;
	return 0;
}