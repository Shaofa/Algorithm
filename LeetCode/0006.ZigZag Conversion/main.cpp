/**********************************************************************
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given 
 * number of rows like this: 
 *		(you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string text, int nRows);
 *
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 **********************************************************************
 * 2015 - 12 - 28
 * NJUST Lab4055, NanJing JiangSu
 **********************************************************************/
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

#define CPP 0

#if CPP
string convert(string s, int numRows) 
{
	int len = s.length();
	if (numRows <=1 || numRows >= len)
		return s;
	int idx = 0;
	string rst(len, 0);
	int n = 2 * (numRows - 1);
	for (int i = 0; i < numRows; i++){
		if (i == 0 || i==numRows-1){
			for (int j = i; j < len; j += n){
				rst[idx++] = s[j];
			}
		}
		else{
			int j = i;
			while (j<len){
				rst[idx++] = s[j];
				j += n - (i<<1);
				if (j < len){
					rst[idx++] = s[j];
					j += (i<<1);
				}
			}
		}
	}

	return rst;
}
#else
char* convert(char* s, int numRows) {
	int len = strlen(s);
	if (numRows <= 1 || numRows >= len)
		return s;
	int idx = 0;
	char *rst = (char*)malloc(sizeof(char)*len);
	int n = 2 * (numRows - 1);
	for (int i = 0; i < numRows; i++){
		if (i == 0 || i == numRows - 1){
			for (int j = i; j < len; j += n){
				rst[idx++] = s[j];
			}
		}
		else{
			int j = i;
			while (j<len){
				rst[idx++] = s[j];
				j += n - (i << 1);
				if (j < len){
					rst[idx++] = s[j];
					j += (i << 1);
				}
			}
		}
	}
	memcpy(s, rst, len);
	free(rst);
	rst = NULL;
	return s;
}
#endif
int main(void)
{
#if CPP
	string s = "ABc";
	string s1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout << convert(s1, 4) << endl;
#else
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	printf("%s\n", convert(s, 4));
#endif
	return 0;
}