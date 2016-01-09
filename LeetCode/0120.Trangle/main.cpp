/***********************************************************************
* Given a m x n grid filled with non - negative numbers,
* find a path from top left to bottom right which minimizes the sum of
* all numbers along its path.
*
* Note: You can only move either down or right at any point in time.
*
**********************************************************************
* 2015 - 09 - 16
* NJUST Lab4055, NanJing JiangSu
**********************************************************************/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//int minimumTotal(vector<vector<int>>& triangle) 
//{
//	int m = triangle.size();
//	int n = triangle[m - 1].size();
//
//	vector<vector<int>> dp(m,vector<int>(n));
//	int i, j;
//	int minSum = 0;
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (0 == i)
//			{
//				if (0 == j)
//				{
//					dp[i][j] = triangle[i][j];
//				}
//			}
//			else if (0 == j)
//			{
//				dp[i][j] = dp[i-1][j] + triangle[i][j];
//			}
//			else if (i == j)
//			{
//				dp[i][j] = dp[i-1][j - 1] + triangle[i][j];
//			}
//			else
//			{
//				dp[i][j] = min(dp[i-1][j], dp[i-1][j - 1]) + triangle[i][j];
//			}
//			cout << dp[i][j] << "\t";
//			if (m-1 == i)
//			{
//				if (0 == j)
//				{
//					minSum = dp[i][0];
//				}
//				else
//				{
//					minSum = dp[i][j] < minSum ? dp[i][j] : minSum;
//				}
//			}
//		}
//		cout << "\n";
//	}
//	return minSum;
//}

int minimumTotal(vector<vector<int>>& triangle)
{
	int m = triangle.size();
	int n = triangle[m - 1].size();

	vector<int> dp(n);
	int i, j;
	int minSum = 0;
	for (i = 0; i < m; i++)
	{
		for (j = i; j >=0; j--)
		{
			if (0 == i)
			{
				if (0 == j)
				{
					dp[j] = triangle[i][j];
				}
			}
			else if (0 == j)
			{
				dp[j] = dp[j] + triangle[i][j];
			}
			else if (i == j)
			{
				dp[j] = dp[j - 1] + triangle[i][j];
			}
			else
			{
				dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
			}
			cout << dp[j] << "\t";
			if (m - 1 == i)
			{
				if (i == j)
				{
					minSum = dp[i];
				}
				else
				{
					minSum = dp[j] < minSum ? dp[j] : minSum;
				}
			}
		}
		cout << "\n";
	}
	return minSum;
}

int main(void)
{
	vector<vector<int>> tri;
	vector<int> tmp;
	tmp.push_back(2);
	tri.push_back(tmp);
	tmp.clear();
	tmp.push_back(3);
	tmp.push_back(4);
	tri.push_back(tmp);
	tmp.clear();
	tmp.push_back(6);
	tmp.push_back(5);
	tmp.push_back(7);
	tri.push_back(tmp);
	tmp.clear();
	tmp.push_back(4);
	tmp.push_back(1);
	tmp.push_back(8);
	tmp.push_back(3);
	tri.push_back(tmp);
	for (int i = 0; i < tri.size(); i++)
	{
		for (int j = 0; j < tri[i].size(); j++)
		{
			cout << tri[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << minimumTotal(tri) << endl;
	return 0;
}
