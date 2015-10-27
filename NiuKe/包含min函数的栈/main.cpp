/*
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
 */
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	stack<int> s;
	void push(int value) {
		s.push(value);
	}
	void pop() {
		if (!s.empty())
			s.pop();
	}
	int top() {
		if (!s.empty())
			return s.top();
	}
	int min() {
		stack<int> tmp;
		int min = s.top();
		while (!s.empty())
		{
			int top = s.top();
			min = top < min ? top : min;
			tmp.push(top);
			s.pop();
		}
		while (!tmp.empty())
		{
			s.push(tmp.top());
			tmp.pop();
		}
		return min;
	}
};

int main(void)
{
	Solution s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(0);
	s.push(5);
	cout << s.min() << endl;
	return 0;
}