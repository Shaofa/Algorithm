/*
 * 在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
 * 数组中某些数字是重复的，但不知道有几个数字是重复的。
 * 也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
 * 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是重复的数字2或者3。
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