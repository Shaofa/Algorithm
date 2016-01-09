/**********************************************************************
 * Given an array S of n integers, are there elements a, b, c in S 
 * such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
 * The solution set must not contain duplicate triplets.
 * For example, given array S = {-1 0 1 2 -1 -4},
 * 
 * A solution set is:
 * (-1, 0, 1)
 * (-1, -1, 2)
 **********************************************************************
 * 2015 - 12 - 30
 * NJUST Lab4055, NanJing JiangSu
 **********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define CPP 1
#if CPP
vector<vector<int>> threeSum(vector<int>& nums) {
	int n = nums.size();
	vector< vector<int>> threesum;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n; i++){
		if (i>0 && nums[i] == nums[i - 1])
			continue;
		int l = i + 1;
		int r = n - 1;
		while (l < r){
			int sum = nums[i] + nums[l] + nums[r];
			if (sum>0) r--;
			else if (sum < 0) l++;
			else{
				threesum.push_back(vector<int>{nums[i], nums[l], nums[r]});
				while (nums[l] == nums[l + 1]) l++;
				while (nums[r] == nums[r - 1]) r--;
				l++, r--;
			}
		}
	}
	return threesum;
}
#else
int** threeSum(int* nums, int numsSize, int* returnSize) {

}
#endif
int main(void)
{
	int nums[] = { 7, -1, 14, -12, -8, 7, 2, -15, 8, 8, -8, -14, -4, -5, 7, 9, 11, -4, -15,
		-6, 1, -14, 4, 3, 10, -5, 2, 1, 6, 11, 2, -2, -5, -7, -6, 2, -15, 11, -6, 8, -4, 2, 
		1, -1, 4, -6, -15, 1, 5, -15, 10, 14, 9, -8, -6, 4, -6, 11, 12, -15, 7,-1, -9, 9, -1, 
		0, -4, -1, -12, -2, 14, -9, 7, 0, -3, -4, 1, -2, 12, 14, -10, 0, 5, 14, -1, 14, 3, 8, 
		10, -8, 8, -5, -2, 6, -11, 12, 13, -7, -12, 8, 6, -13, 14, -2, -5, -11, 1, 3, -6 };
#if CPP
	vector<int> num(nums, nums + sizeof(nums) / sizeof(nums[0]));
	vector< vector<int> > result;
	result = threeSum(num);
	for (int i = 0; i < result.size(); i++){
		cout << "{" << result[i][0] << "," << result[i][1] << "," << result[i][2] << "}" << endl;
	}
#else
	
#endif
	return 0;
}
