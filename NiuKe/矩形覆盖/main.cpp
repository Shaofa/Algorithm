/*
 * ���ǿ�����2 * 1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
 * ������n��2 * 1��С�������ص��ظ���һ��2 * n�Ĵ���Σ��ܹ��ж����ַ�����
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