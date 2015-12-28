/**********************************************************************
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes 
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 **********************************************************************
 * 2015 - 12 - 25
 * NJUST Lab4055, NanJing JiangSu
 **********************************************************************/
#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{

	if (l1 == NULL || l2 == NULL)
		return NULL;

	ListNode *p = NULL;
	long n1 = 0, n2 = 0;
	int cnt = 0;
	p = l1;
	while (p != NULL)
	{
		n1 += (p->val*pow(10, cnt++));
		p = p->next;
	}
	cnt = 0;
	p = l2;
	while (p != NULL)
	{
		n2 += (p->val*pow(10, cnt++));
		p = p->next;
	}
	cout << n1 << '\t' << n2 << '\t' << n1 + n2 << endl;
	n1 += n2;
	ListNode *h = (ListNode*)malloc(sizeof(ListNode));
	h->next = NULL;
	h->val = n1%10;
	n1 /= 10;
	ListNode *t = h;
	while (n1)
	{
		p = (ListNode*)malloc(sizeof(ListNode));
		p->val = n1 % 10;
		t->next = p;
		p->next = NULL;
		t = p;
		n1 /= 10;
	}

	return h;
}

int main(void)
{
	ListNode n11(9);
	ListNode n12(0);
	ListNode n13(9);
	ListNode n21(1);
	ListNode n22(9);
	ListNode n23(9);

	//n11.next = &n12;
	//n12.next = &n13;
	n21.next = &n22;
	n22.next = &n23;
	ListNode *h = addTwoNumbers(&n11, &n21);
	ListNode *p = h;
	while (h)
	{
		cout << p->val;
		p = h->next;
		free(h);
		h = p;
	}
	cout << endl;
}