/*
 * ��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
 * ����һ���ǵݼ����е�һ����ת�������ת�������СԪ�ء�
 * ��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
 */
#include <iostream>
#include <vector>
using namespace std;

int minNumberInRotateArray(vector<int> rotateArray) 
{
	int n = rotateArray.size();
	if (n <= 0)
		return -1;

	int i = 0;
	int preN = rotateArray[i];
	while (++i < n)
	{
		if (rotateArray[i] < preN)
			return rotateArray[i];
	}
	return rotateArray[0];
}

int main(void)
{
	 int array[] = { 3, 4, 5, 7, 10 };
	 vector<int> rotateArr(array,array+sizeof(array)/sizeof(array[0]));
	cout << minNumberInRotateArray(rotateArr) << endl;

	return 0;
}