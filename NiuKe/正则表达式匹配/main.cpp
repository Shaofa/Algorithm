/*
 * ��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��
 * ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� 
 * �ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ��
 * ���磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��
 */
#include <iostream>
using namespace std;

bool match(char* str, char* pattern)
{
	if (str == NULL || pattern == NULL)
		return false;

	while (*pattern)
	{
		if (*pattern == '.')
		{
			str++;
			pattern++;
		}
		else if (*pattern == '*')
		{

		}
		else if (*pattern != *str)
			return false;
	}
}

int main(void)
{
	cout << match("abcdddf", "abcd*.e*") << endl;
	return 0;
}