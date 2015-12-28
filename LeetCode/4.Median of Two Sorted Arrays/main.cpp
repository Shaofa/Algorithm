/**********************************************************************
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays.The overall run time complexity 
 * should be O(log(m + n)).
 **********************************************************************
 * 2015 - 12 - 28
 * NJUST Lab4055, NanJing JiangSu
 **********************************************************************/
#include <iostream>
#include <vector>
using namespace std;

#define CPP 0
#if CPP	// c++
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
	int m = nums1.size();
	int n = nums2.size();
	int l = m + n;
	int midx = (l % 2 == 0) ? (l / 2) + 1 : (l / 2 + 1);
	double mid = 0.0;
	vector<int> num(midx);
	int i1 = 0, i2 = 0, i = 0;
	for (i = 0; i < midx; i++)
	{
		if (i1 < m && i2<n)
			num[i] = nums1[i1]<nums2[i2] ? nums1[i1++] : nums2[i2++];
		else
			num[i] = i1 < m ? nums1[i1++] : nums2[i2++];
		cout << num[i] << '\t';
	}
	cout << endl;
	mid = (l % 2 == 0) ? (num[midx - 1] + num[midx - 2]) / 2.0 : (double)num[midx - 1];
	return mid;
}
#else	// c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int l = nums1Size + nums2Size;
	int midx = (l % 2 == 0) ? (l / 2) + 1 : (l / 2 + 1);
	double mid = 0.0;
	int *num = (int*)malloc(sizeof(int)*midx);
	int i1 = 0, i2 = 0, i = 0;
	for (i = 0; i < midx; i++)
	{
		if (i1 < nums1Size && i2<nums2Size)
			num[i] = nums1[i1]<nums2[i2] ? nums1[i1++] : nums2[i2++];
		else
			num[i] = i1 < nums1Size ? nums1[i1++] : nums2[i2++];
		cout << num[i] << '\t';
	}
	cout << endl;
	mid = (l % 2 == 0) ? (num[midx - 1] + num[midx - 2]) / 2.0 : (double)num[midx - 1];
	free(num);
	num = NULL;
	return mid;
}
#endif

int main(void)
{
	int n1[] = { 0, 1, 2, 2, 4,5};
	int n2[] = { 2, 3, 4, 7};
#if CPP
	vector<int> num1;
	vector<int> num2;
	num1.assign(n1, n1+sizeof(n1)/sizeof(n1[0]));
	num2.assign(n2, n2+sizeof(n2) / sizeof(n2[0]));
	cout << findMedianSortedArrays(num1, num2) << endl;
#else
	cout << findMedianSortedArrays(n1, sizeof(n1) / sizeof(n1[0]), n2, sizeof(n2)/sizeof(n2[0])) << endl;
#endif
	return 0;
}