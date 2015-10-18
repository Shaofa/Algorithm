/*
 * ��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
 * �����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
 */

#include <vector>
#include <iostream>
using namespace std;


bool Find(vector<vector<int> > array, int target) 
{
	for (int i = 0; i < array.size(); i++)
	{
		int l = 0;
		int r = array[0].size() - 1;
		int m = (l + r) / 2;
		while (l<=r)
		{
			if (target == array[i][m])
				return true;
			else if (target < array[i][m])
				r = m - 1;
			else
				l = m + 1;
			m = (l + r) / 2;
		}
	}
	return false;
}

int main(void)
{
	int b[4][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	vector<vector<int>> a(4,vector<int>(4));
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[0].size(); j++)
		{
			a[i][j] = b[i][j];
			cout << a[i][j] << '\t';
		}
		cout << endl;
	}
	cout << Find(a,7) << endl;
}