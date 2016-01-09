/***********************************************************************
 * Given a m x n grid filled with non - negative numbers, 
 * find a path from top left to bottom right which minimizes the sum of
 * all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 **********************************************************************
 * 2015 - 09 - 14
 * NJUST Lab4055, NanJing JiangSu
 **********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPathSum_cpp(vector<vector<int>>& grid) 
{
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> dp(m,vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0)
			{
				if (j == 0)
				{
					dp[i][j] = grid[0][0];
				}
				else
				{
					dp[i][j] = dp[i][j - 1] + grid[i][j];
				}
			}
			else if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] + grid[i][j];
			}
			else
			{
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
			cout << dp[i][j] << '\t';
		}
		cout << endl; 
	}
	return dp[m - 1][n - 1];
}

int minPathSum_c(int* a, int gridRowSize, int gridColSize)
{
	int *dp = (int*)malloc(gridColSize * sizeof(int));
	int i = 0;
	int j = 0;
	int ret = 0;
	int **grid = (int**)a;
	memset(dp, 0, gridColSize*sizeof(int));
	for (i = 0; i < gridRowSize; i++)
	{
		for (j = 0; j < gridColSize; j++)
		{
			if (i == 0)
			{
				if (j == 0)
				{
					dp[j] = grid[i][j];
				}
				else
				{
					dp[j] = dp[j - 1] + grid[i][j];
				}
			}
			else if (j == 0)
			{
				dp[j] = dp[j] + grid[i][j];
			}
			else
			{
				dp[j] = dp[j]<dp[j - 1] ? dp[j] : dp[j - 1] + grid[i][j];
			}
			printf("%d\t", dp[j]);
		}
		printf("\n");
	}

	ret = dp[j - 1];
	free(dp);
	dp = NULL;
	return ret;
}
int main(void)
{
	int m = 10;
	int n = 5;
	vector<vector<int>> a(m,vector<int>(n));
	int b[10][5] = { 0 };
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp = rand() % 10;
			a[i][j] = tmp;
			b[i][j] = tmp;
			cout << a[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
	cout << minPathSum_cpp(a) << endl;

	cout << minPathSum_c((int*)b, m, n);
}