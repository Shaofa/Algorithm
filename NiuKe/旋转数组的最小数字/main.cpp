/*
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个非递减序列的一个旋转，输出旋转数组的最小元素。
 * 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
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