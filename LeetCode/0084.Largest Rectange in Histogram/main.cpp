/***********************************************************************
 * Given n non-negative integers representing the histogram's bar height 
 * where the width of each bar is 1, 
 * find the area of largest rectangle in the histogram.
 *              6	
               ___
            5  | |
           ___ | |
           | | | |      3
    2      | | | |  2  ___ 
   ___   1 | | | | ___ | | 
   | | ___ | | | | | | | | 
   | | | | | | | | | | | |  
  --------------------------

 * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 * The largest rectangle is shown in the shaded area, which has area = 10 unit.

 * For example,
 * Given height = [2,1,5,6,2,3],
 * return 10.
 *
 **********************************************************************
 * 2015 - 09 - 14
 * NJUST Lab4055, NanJing JiangSu
 **********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int>& height) 
{
	int n = height.size();
	int maxRect = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = height[i];
		for (int j = i-1; j >-1; j--)
		{
			if (height[j] >= height[i])
				sum += height[i];
		}
		for (int j = i + 1; j < n; j++)
		{
			if (height[j] >= height[i])
				sum += height[i];
		}
		maxRect = sum > maxRect ? sum : maxRect;
	}
	return maxRect;
}

int main(void)
{
	int n = 0;
	cin >> n;

	vector<int> h(n);
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	cout << "Max Rectangle: " << largestRectangleArea(h) << endl;
}