
/*
 * һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
 * �����������һ��n����̨���ܹ��ж�����������
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