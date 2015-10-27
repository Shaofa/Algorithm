/*
 * 输入一个链表，反转链表后，输出链表的所有元素。
 */
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {}
};

ListNode* ReverseList(ListNode* pHead) 
{
	ListNode* p = NULL;
	ListNode* h = NULL;

	if (NULL == pHead)
	{
		return NULL;
	}

	p = pHead;
	while (p)
	{
		ListNode* q = p->next;
		p->next = h;
		h = p;
		p = q;
	}
	return h;
}

int main(void)
{
	ListNode head(0);
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);
	ListNode n6(6);
	ListNode n7(7);

	head.next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;

	ListNode* newHead = ReverseList(&head);
	if (!newHead)
		return 0;

	ListNode* p = newHead->next;
	while (p)
	{
		cout << p->val << endl;
		p = p->next;
	}
	return 0;
}