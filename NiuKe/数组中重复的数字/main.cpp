/*
 * ��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� 
 * ������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
 * Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� 
 * ���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ��������ظ�������2����3��
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

#if 0
bool duplicate(int numbers[], int length, int* duplication) 
{
	vector<int> isDup(length);

	for (int i = 0; i < length; i++)
	{
		isDup[numbers[i]]++;
		if (isDup[i] > 1)
		{
			duplication[cnt++] = i;
		}
	}
	
	return (cnt!=0);
}
#else
bool duplicate(int numbers[], int length, int* duplication)
{
	map<int, int> nmap;
	int cnt = 0;

	for (int i = 0; i < length; i++)
	{
		int val = numbers[i];
		if (nmap.find(val)!=nmap.end() && nmap[val]==1)
		{
			duplication[cnt++] = val;
			nmap[val]++;
		}
		else
		{
			nmap[val] = 1;
		}
	}
	
	return (cnt != 0);
}
#endif

int main(void)
{
	bool isDuplicate = false;
	int number[] = { 1, 2, 3, 2, 3, 3, 4, 5, 6, 7 };
	int length = sizeof(number) / sizeof(number[0]);
	int *dup = new int(length);
	for (int i = 0; i < length; i++)
	{
		dup[i] = length;
	}

	isDuplicate = duplicate(number, length, dup);

	for (int i = 0; i < length; i++)
	{
		if (dup[i] < length)
			cout << dup[i] << '\t';
	}
	cout << endl;
	delete []dup;
	return 0;
}