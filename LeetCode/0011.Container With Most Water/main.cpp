/**********************************************************************
 * Given n non-negative integers a1, a2, ..., an, 
 * where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two endpoints of line i is 
 * at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, 
 * such that the container contains the most water.
 *
 * Note: You may not slant the container.
 **********************************************************************
 * 2015 - 12 - 29
 * NJUST Lab4055, NanJing JiangSu
 **********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define C	1
#if C
int maxArea(int* height, int heightSize) {
	int maxA = 0, tmpA = 0;
	int l = 0, r = heightSize - 1;
	while (l < r)
	{
		tmpA = (r - l) * (height[l]>height[r] ? height[l] : height[r]);
		maxA = tmpA > maxA ? tmpA : maxA;
		height[l] < height[r] ? l++ : r--;
	}
	return maxA;
}
#else
int maxArea(vector<int>& height) {
	int n = height.size();
	int maxA = 0, tmpA = 0;
	int l = 0, r = n - 1;
	while (l < r)
	{
		tmpA = (r - l) * min(height[l], height[r]);
		maxA = max(maxA, tmpA);
		height[l] < height[r] ? l++ : r--;
	}
	return maxA;
}
#endif
int main(void)
{
	int a[] = { 2,3,2,5,3,4 };
#if C
	printf("%d\n", maxArea(a, 6));
#else
	vector<int> h(a, a + 6);
	cout << maxArea(h) << endl;
#endif
	return 0;
}