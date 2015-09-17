/***********************************************************************
 * Find the contiguous subarray within an array 
 * (containing at least one number) which has the largest sum.
 *
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 *
 **********************************************************************
 * 2015 - 09 - 16
 * NJUST Lab4055, NanJing JiangSu
 **********************************************************************/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int maxSubArray(vector<int>& nums) 
{
	int m = nums.size();
	int sum = 0;
	int maxS = INT_MIN;
	for (int i = 0; i < m; i++)
	{
		sum = max(sum + nums[i], nums[i]);
		maxS = maxS < sum ? sum : maxS;
	}
	return maxS;
}

int main(void)
{
	int n[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	vector<int> nums(n, n + 9);
	cout << maxSubArray(nums) << endl;
	return 0;
}