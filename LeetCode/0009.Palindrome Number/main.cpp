/**********************************************************************
 * Determine whether an integer is a palindrome. 
 * Do this without extra space.
 **********************************************************************
 * 2015 - 12 - 29
 * NJUST Lab4055, NanJing JiangSu
 **********************************************************************/
#include <iostream>
#include <stack>
using namespace std;

#define CPP 1
#if CPP
bool isPalindrome(int x) 
{
	long long xx = x;
	if (xx < 0)
		return false;
	int len = 0;
	long long n = xx;
	while (n){
		len++;
		n /= 10;
	}
	int a, b;
	for (int i = 0; i < len / 2; i++)
	{
		a = (xx / pow(10, i));
		b = (xx / pow(10, len - i - 1));
		if ((a % 10) != (b % 10))
			return false;
	}
	return true;
}
#else
#endif

int main(void)
{
	cout << isPalindrome(12331) << endl;
	return 0;
}