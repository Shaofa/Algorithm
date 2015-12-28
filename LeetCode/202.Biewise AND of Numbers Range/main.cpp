/**********************************************************************
 * Given a range[m, n] where 0 <= m <= n <= 2147483647, 
 * return the bitwise AND of all numbers in this range, inclusive.
 *
 * For example, given the range[5, 7], you should return 4.
 **********************************************************************
 * 2015 - 12 - 25
 * NJUST Lab4055, NanJing JiangSu
 **********************************************************************/
#include <iostream>
using namespace std;

int rangeBitwiseAnd(int m, int n) 
{
	while (m < n)
		n &= (n-1);
	return n;
}

int main(void)
{
	int rst = 0;
	int m = 10;
	int n = 14;
	cout << rangeBitwiseAnd(m,n) << endl;
	return 0;
}