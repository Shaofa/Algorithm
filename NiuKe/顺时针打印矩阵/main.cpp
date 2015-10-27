/*
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
 * 例如，如果输入如下矩阵： 
 * 1	2	3	4 
 * 5	6	7	8		 
 * 9	10	11	12
 * 13	14	15	16 
 *
 * 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) 
{
	int m = matrix.size();
	int n = matrix[0].size();
	int cm, cn;
	cm = cn = 0;
	vector<int> rst(m*n);
	int i = 0;
	int state = 0;
	while (i < m*n)
	{
		switch (state)
		{
		case 0:
			while (cn < n && (matrix[cm][cn] != INT_MAX))
			{
				rst[i++] = matrix[cm][cn];
				matrix[cm][cn++] = INT_MAX;
			}
			cn--;
			cm++;
			state = 1;
			break;
		case 1:
			while (cm < m && matrix[cm][cn] != INT_MAX)
			{
				rst[i++] = matrix[cm][cn];
				matrix[cm++][cn] = INT_MAX;
			}
			cm--;
			cn--;
			state = 2;
			break;
		case 2:
			while(cn >=0 && matrix[cm][cn] != INT_MAX)
			{
				rst[i++] = matrix[cm][cn];
				matrix[cm][cn--] = INT_MAX;
			}
			cn++;
			cm--;
			state = 3;
			break;
		case 3:
			while (cm < m && matrix[cm][cn] != INT_MAX)
			{
				rst[i++] = matrix[cm][cn];
				matrix[cm--][cn] = INT_MAX;
			}
			cm++;
			cn++;
			state = 0;
			break;
		}
	}
	return rst;
}

vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) 
{
	vector<int> rst;
	if (mat.empty())
		return rst;

	int l = 0;
	int u = 0;
	int r = mat.size() - 1;
	int b = mat[0].size() - 1;
	
	while (l <= r && u<= b){
		for (int i = l; i <= r; i++)
			rst.push_back(mat[u][i]);
		u++;
		for (int i = u; i <= b; i++)
			rst.push_back(mat[i][r]);
		r--;
		for (int i = r; i >= l; i--)
			rst.push_back(mat[b][i]);
		b--;
		for (int i = b; i >= u; i--)
			rst.push_back(mat[i][l]);
		l++;
	}
	return rst;
}
int main(void)
{
	int m = 3;
	int n = 3;
	vector<vector<int>> matrix(m,vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = i*(m - 1) + j;
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}

	vector<int> rst = printMatrix(matrix);
	for (int i = 0; i < m*n; i++)
	{
		cout << rst[i] << '\n';
	}

	rst = clockwisePrint(matrix,m,n);
	for (int i = 0; i < m*n; i++)
	{
		cout << rst[i] << '\n';
	}
	return 0;
}