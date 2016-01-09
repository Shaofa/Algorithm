/***********************************************************************
 * Implement next permutation, which rearranges numbers into
 * the lexicographically next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as 
 * the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 * Here are some examples. Inputs are in the left-hand column and its 
 * corresponding outputs are in the right-hand column.
 *
 *	1,2,3 ¡ú 1,3,2
 *	3,2,1 ¡ú 1,2,3
 *	1,1,5 ¡ú 1,5,1
 **********************************************************************
 * 2015-07-06
 * NJUST Lab4055,NanJing JiangSu
 **********************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void nextPermutation(vector<int>& nums)
{
	vector<int>::iterator i = nums.begin();
	i++;
	int tmp = 0;
	string dic[9] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	for (; i < nums.end(); i++)
	{
		//if (dic[*i])
	}
}

int main(void)
{
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);

	nextPermutation(num);
	vector<int>::iterator i = num.begin();
	for (; i < num.end(); i++)
	{
		cout << *i << endl;
	}
	return 0;
}

