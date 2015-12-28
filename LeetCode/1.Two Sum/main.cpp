/**********************************************************************
 * Given an array of integers, find two numbers such that they add up 
 * to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that 
 * they add up to the target, where index1 must be less than index2.
 * Please note that your returned answers(both index1 and index2) are not zero - based.
 * 
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers = { 2, 7, 11, 15 }, target = 9
   Output : index1 = 1, index2 = 2
 **********************************************************************
 * 2015 - 12 - 25
 * NJUST Lab4055, NanJing JiangSu
 **********************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#if 0
vector<int> twoSum(vector<int>& nums, int target) 
{
	int n = nums.size();
	int i, j;
	for (i = 0; i < n; i++)
	{
		int t = target - nums[i];
		for (j = i + 1; j < n; j++)
		{
			if (nums[j] == t)
			{
				vector<int> index(2);
				index[0] = i+1;
				index[1] = j+1;
				return index;
			}
		}
	}
}
#else
vector<int> twoSum(vector<int>& nums, int target)
{
	int n = nums.size();
	map<int, int> m;
	map<int, int>::iterator it;
	int i, j;

	for (i = 0; i < n; i++)
	{
		m[nums[i]] = i;
	}
	for (i = 0; i < n; i++)
	{
		it = m.find(target - nums[i]);
		if (it != m.end() && it->second > i)
		{
			vector<int> index(2);
			index[0] = i + 1;
			index[1] = it->second+1;
			return index;
		}
	}
}
#endif

int main(void)
{
	vector<int> nums(10);
	for (int i = 0; i < nums.size(); i++)
	{
		nums[i] = i+1;
	}

	vector<int> index;
	index = twoSum(nums, 9);
	cout << index[0] << '\t' << index[1] << endl;
	return 0;
}