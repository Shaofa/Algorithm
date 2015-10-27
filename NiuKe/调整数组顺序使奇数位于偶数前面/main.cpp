/*
 * ����һ���������飬ʵ��һ�����������������������ֵ�˳��
 * ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ������ĺ�벿�֣�
 * ����֤������������ż����ż��֮������λ�ò��䡣
 */

#include <iostream>
#include <vector>
using namespace std;

#if 0
void reOrderArray(vector<int> &array) 
{
	int len = array.size();
	int i = 0;
	int lastOdd = 0;
	for (i = 0; i<len; i++)
	{
		if (array[i] % 2 == 0)
		{
			continue;
		}
		else
		{
			array.insert(array.begin() + lastOdd, array[i]);
			array.erase(array.begin()+i+1);
			lastOdd++;
		}
	}
}
#else
void reOrderArray(vector<int> &array)
{
	int len = array.size();
	vector<int> newArr(len);
	int lastO = 0;
	int lastE = len - 1;
	for (int i = 0; i<len; i++)
	{
		if (array[i] % 2 == 0)
		{
			newArr[lastE--] = array[i];
		}
		else
		{
			newArr[lastO++] = array[i];
		}
	}
	array = newArr;
}
#endif

void print(vector<int > &array)
{
	for (int i = 0; i < array.size(); i++)
	{
		cout << array[i] << "\t";
	}
	cout << endl;
}

int main(void)
{
	vector<int> arry;
	for (int i = 0; i < 100; i++)
	{
		arry.push_back(i);
	}
	print(arry);
	reOrderArray(arry);
	print(arry);
	return 0;
}