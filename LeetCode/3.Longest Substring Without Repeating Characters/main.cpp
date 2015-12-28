/**********************************************************************
 * Given a string, find the length of the longest substring without 
 * repeating characters.
 *
 * For example, the longest substring without repeating letters for 
 * "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest 
 * substring is "b", with the length of 1.
 **********************************************************************
 * 2015 - 12 - 28
 * NJUST Lab4055, NanJing JiangSu
 **********************************************************************/
#include <iostream>
#include <map>
#include <string>
using namespace std;

// 16ms
int lengthOfLongestSubstring(string s) {
	int len = s.length();
	int pos[256];
	int start = 0;
	int maxlen = 0;
	memset(pos, -1, sizeof(pos));
	for (int i = 0; i < len; i++)
	{
		if (pos[(int)s[i]] != -1 && pos[(int)s[i]]>=start)
		{
			maxlen = (i - start) > maxlen ? i - start : maxlen;
			start = pos[(int)s[i]] + 1;
		}
		pos[(int)s[i]] = i;
	}
	return (len - start) > maxlen ? len - start : maxlen;
}

int main(void)
{
	cout << lengthOfLongestSubstring("abcdebacf") << endl;
	return 0;
}
