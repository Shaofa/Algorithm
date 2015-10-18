/*
 * 请实现一个函数，将一个字符串中的空格替换成“%20”。
 * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 */
#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define	 _STRFORMAT_VECTOR	0
#define  _STRFORMAT_CHAR	1
#define	 _STRFORMAT_STRING	2
#define _STRFORMAT	3

#if _STRFORMAT==_STRFORMAT_CHAR
void replaceSpace(char *str, int length) 
{
	if (str == NULL || length == 0)
		return;

	int len = 0;
	char *p = (char*)malloc(length*3+1);
	memset(p, 0, sizeof(length * 3 + 1));
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if(*(str+i) == ' ')
		{
			*(p + len++) = '%';
			*(p + len++) = '2';
			*(p + len++) = '0';
		}
		else
		{
			*(p+len++) = *(str+i);
		}
	}
	*(p + len) = '\0';
	memcpy(str, p, len);
	free(p);
	p = NULL;
}
#elif _STRFORMAT==_STRFORMAT_VECTOR
void replaceSpace(char *str, int length) {
	vector<char> a;
	int i = 0;
	while (*str)
	{
		if (*str == ' ')
		{
			a.push_back('%');
			a.push_back('2');
			a.push_back('0');
			str++;
		}
		else
		{
			a.push_back(*str++);
		}
	}
	str -= length;
	copy(a.begin(), a.end(), str);
}
#elif _STRFORMAT==_STRFORMAT_STRING
void replaceSpace(char *str, int length) 
{
	string s(str);
	if (str == NULL || length == 0)
		return;
	for (int i = 0; i < s.length(); i++)
	{
		if (s.at(i) == ' ')
		{
			s.erase(i, 1);
			s.insert(i, "%20");
			i += 3;
		}
	}
	memcpy(str, s.c_str(), s.length());
}
#endif

void replaceSpace(char *str, int length)
{
	if (str == NULL || length == 0)
		return;

	int newLen = length;
	int i = 0, j = 0;
	while (str[i] != '\0')
	{
		newLen += (str[i]==' ' ? 2 : 0);
		i++;
	}
	str[newLen] = '\0';
	i = length - 1;
	j = newLen - 1;
	while (i >= 0 && j>=0)
	{
		if (str[i] == ' ')
		{
			str[j--] = '0';
			str[j--] = '2';
			str[j] = '%';
		}
		else
		{
			str[j] = str[i];
		}
		j--;
		i--;
	}
}

int main(void)
{
	char str[1024] = "";//" hello world";
	replaceSpace(str, strlen(str));
	cout << str << endl;
	return 0;
}