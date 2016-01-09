/**********************************************************************
 * Write a function to find the longest common prefix string 
 * amongst an array of strings.
 **********************************************************************
 * 2015 - 12 - 30
 * NJUST Lab4055, NanJing JiangSu
 **********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define CPP 0
#if CPP
string longestCommonPrefix(vector<string>& strs) {
	int n = strs.size();
	if (n == 0)
		return "";
	int minlen = INT_MAX;
	int minidx = n;
	int maxcom = 0;
	for (int i = 0; i < n; i++){
		int len = strs[i].length();
		minidx = len < minlen ? i : minidx;
		minlen = len < minlen ? len : minlen;
	}
	string common;
	for (int i = 0; i < minlen; i++){
		common = strs[minidx].substr(0, i+1);
		for (int j = 0; j < n; j++){
			if (strs[j].substr(0, i+1) != common)
				return strs[minidx].substr(0, i);
		}
	}
	return common;
}
#else
char* longestCommonPrefix(char** strs, int strsSize) {
	int n = strsSize;
	if (n == 0 || strs==NULL)
		return "";
	int minlen = INT_MAX;
	int minidx = n;
	int maxcom = 0;
	int i, j;
	for (i = 0; i < n; i++){
		if (strs + i == NULL)
			return NULL;
		int len = strlen(*(strs + i));
		minidx = len < minlen ? i : minidx;
		minlen = len < minlen ? len : minlen;
	}
	char *common = (char*)malloc(minlen + 1);
	for (i = 0; i < minlen; i++){
		memset(common, 0, sizeof(minlen + 1));
		memcpy(common, *(strs + minidx), i + 1);
		for (j = 0; j < n; j++){
			if (strncmp(*(strs + j), common, i + 1) != 0){
				*(common + i) = '\0';
				return common;
			}
		}
	}
	*(common + i) = '\0';
	return common;
}
#endif
int main(void)
{
#if CPP
	vector<string> s(4);
	s[0] = "avbe";
	s[1] = "abce";
	s[2] = "abce";
	s[3] = "abce";
	cout << longestCommonPrefix(s) << endl;
#else
	char *s[4] = { "abcc", "abcc", "abcc", "abcc" };
	char *a = longestCommonPrefix(s, 4);
	printf("%s\n",a);
	free(a);
	a = NULL;
#endif
	return 0;
}