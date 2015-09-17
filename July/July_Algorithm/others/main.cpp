#include <iostream>
using namespace std;

/*
 * Find the MaxSubArray
 */

/* 暴力法 */
int MaxSubArray(int* A, int n);

int main(void)
{
	int A[9] = { 1, 2, 3, 4, 5, 0, -1, 4, 5 };
	cout << MaxSubArray(A, sizeof(A)/sizeof(A[0])) << endl;
	return 0;
}

/* 暴力法 */
int MaxSubArray(int* A, int n)
{
	int maxSum = A[0];
	int maxFrom = 0;
	int maxTo = 0;
	int currSum = 0;
	int from = 0;
	int to = 0;
	for (from = 0; from < n; from++)
	{
		for (to = from; to < n; to++)
		{
			currSum = 0;
			for (int k = from; k <= to; k++)
			{
				currSum += A[k];
			}
			if (currSum > maxSum)
			{
				maxSum = currSum;
				maxFrom = from;
				maxTo = to;
			}
		}
	}
	cout << maxFrom << "->" << maxTo << endl;
	return maxSum;
}