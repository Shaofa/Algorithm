/*
 * ����һ��double���͵ĸ�����base��int���͵�����exponent��
 * ��base��exponent�η���
 */
#include <iostream>
using namespace std;

#if 0
double Power(double base, int exponent) 
{
	return pow(base, exponent);
}
#else
double Power(double base, int exponent)
{
	if (fabs(base) < 1e-10)
	{
		try
		{
			if (exponent == 0)
				throw int(-1);
		}
		catch (int data)
		{
			cout << "��������Ϊ��\n";
			return -1;
		}
		return 0;
	}
}
#endif

int main(void)
{
	cout << Power(0, 0) << endl;
	return 0;
}