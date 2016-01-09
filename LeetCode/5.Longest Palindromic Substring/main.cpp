/**********************************************************************
 * Given a string S, find the longest palindromic substring in S. 
 * You may assume that the maximum length of S is 1000, 
 * and there exists one unique longest palindromic substring.
 **********************************************************************
 * 2015 - 12 - 28
 * NJUST Lab4055, NanJing JiangSu
 **********************************************************************/
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

#define CPP 1
#if CPP	// c++
int isPalindrome(string s, int &left)
{
	int len = s.length();
	const char *ss = s.c_str();
	int l, r;
	bool f;
	int maxlen = 0, tmplen = 0, tmpleft = 0;
	for (int i = 0; i < 2; i++)
	{
		l = left;
		r = left + i;
		f = false;
		while (l >= 0 && r < len && (*(ss+l) == *(ss+r)))
			l--, r++, f = true;
		if (f)	++l, --r;
		tmplen = r - l + 1 - (!f*(i << 1));
		tmpleft = tmplen > maxlen ? l : tmpleft;
		maxlen = tmplen >maxlen ? tmplen : maxlen;
	}
	left = tmpleft;
	return maxlen;
}
string longestPalindrome(string s) 
{
	int len = s.length();
	int maxlen = 0;
	int index = 0, left = 0;
	int tmplen = 0;
	for (int i = 0; i < len; i++)
	{
		index = i;
		tmplen = isPalindrome(s, index);
		left = tmplen > maxlen ? index : left;
		maxlen = tmplen > maxlen ? tmplen : maxlen;
	}
	return s.substr(left, maxlen);
}
#else	// c
int isPalindrome(const char *s, const int len, int *left)
{
	bool f = false;
	int l = 0, r = 0;
	int maxlen = 0, tmplen = 0, tmpleft = 0;
	for (int i = 0; i < 2; i++)
	{
		f = false;
		l = *left;
		r = (*left) + i;
		while ((l >= 0) && (r < len) && (s[l] == s[r]))
			l--, r++, f = true;
		if (f)
			l++, r--;
		tmplen = r - l + 1 - (!f)*(i * 2);
		tmpleft = maxlen >tmplen ? tmpleft : l;
		maxlen = maxlen >tmplen ? maxlen : tmplen;
	}

	*left = tmpleft;
	return maxlen;
}
char* longestPalindrome(char* s)
{
	int len = strlen(s);
	int maxlen = 0;
	int l = 0, a = 0;
	int tmp = 0;
	for (int i = 0; i < len; i++)
	{
		l = i;
		tmp = isPalindrome(s, len, &l);
		a = tmp > maxlen ? l : a;
		maxlen = tmp > maxlen ? tmp : maxlen;
	}
	s += a;
	*(s+maxlen) = '\0';
	return s;
}
#endif

int main(void)
{
#if CPP
	string s = "ukxidnpsdfwieixhjnannbmtppviyppjgbsludrzdleeiydzawnfmiiztsjqqqnthwinsqnrhfjxtklvbozkaeetmblqbxbugxycrlzizthtuwxlmgfjokhqjyukrftvfwikxlptydybmmzdhworzlaeztwsjyqnshggxdsjrzazphugckgykzhqkdrleaueuajjdpgagwtueoyybzanrvrgevolwssvqimgzpkxehnunycmlnetfaflhusauopyizbcpntywntadciopanyjoamoyexaxulzrktneytynmheigspgyhkelxgwplizyszcwdixzgxzgxiawstbnpjezxinyowmqsysazgwxpthloegxvezsxcvorzquzdtfcvckjpewowazuaynfpxsxrihsfswrmuvluwbdazmcealapulnahgdxxycizeqelesvshkgpavihywwlhdfopmmbwegibxhluantulnccqieyrbjjqtlgkpfezpxmlwpyohdyftzgbeoioquxpnrwrgzlhtlgyfwxtqcgkzcuuwagmlvgiwrhnredtulxudrmepbunyamssrfwyvgabbcfzzjayccvvwxzbfgeglqmuogqmhkjebehtwnmxotjwjszvrvpfpafwomlyqsgnysydfdlbbltlwugtapwgfnsiqxcnmdlrxoodkhaaaiioqglgeyuxqefdxbqbgbltrxcnihfwnzevvtkkvtejtecqyhqwjnnwfrzptzhdnmvsjnnsnixovnotugpzuymkjplctzqbfkdbeinvtgdpcbvzrmxdqthgorpaimpsaenmnyuyoqjqqrtcwiejutafyqmfauufwripmpcoknzyphratopyuadgsfrsrqkfwkdlvuzyepsiolpxkbijqw";
	//cout << (int)isPalindrome(s, 1, 5) << endl;
	cout << longestPalindrome(s) << endl;
#else
	char s[] = "ukxidnpsdfwieixhjnannbmtppviyppjgbsludrzdleeiydzawnfmiiztsjqqqnthwinsqnrhfjxtklvbozkaeetmblqbxbugxycrlzizthtuwxlmgfjokhqjyukrftvfwikxlptydybmmzdhworzlaeztwsjyqnshggxdsjrzazphugckgykzhqkdrleaueuajjdpgagwtueoyybzanrvrgevolwssvqimgzpkxehnunycmlnetfaflhusauopyizbcpntywntadciopanyjoamoyexaxulzrktneytynmheigspgyhkelxgwplizyszcwdixzgxzgxiawstbnpjezxinyowmqsysazgwxpthloegxvezsxcvorzquzdtfcvckjpewowazuaynfpxsxrihsfswrmuvluwbdazmcealapulnahgdxxycizeqelesvshkgpavihywwlhdfopmmbwegibxhluantulnccqieyrbjjqtlgkpfezpxmlwpyohdyftzgbeoioquxpnrwrgzlhtlgyfwxtqcgkzcuuwagmlvgiwrhnredtulxudrmepbunyamssrfwyvgabbcfzzjayccvvwxzbfgeglqmuogqmhkjebehtwnmxotjwjszvrvpfpafwomlyqsgnysydfdlbbltlwugtapwgfnsiqxcnmdlrxoodkhaaaiioqglgeyuxqefdxbqbgbltrxcnihfwnzevvtkkvtejtecqyhqwjnnwfrzptzhdnmvsjnnsnixovnotugpzuymkjplctzqbfkdbeinvtgdpcbvzrmxdqthgorpaimpsaenmnyuyoqjqqrtcwiejutafyqmfauufwripmpcoknzyphratopyuadgsfrsrqkfwkdlvuzyepsiolpxkbijqw";
	printf("%s\n",longestPalindrome(s));
#endif
	return 0;
}