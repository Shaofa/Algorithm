/*
 * 输入一个链表，输出该链表中倒数第k个结点。
 */
#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

#if 1
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
{
	ListNode* p = pListHead;
	int len = 0;
	while (p)
	{
		len++;
		p = p->next;
	}

	int i = 0;
	p = pListHead;
	while (p && ++i < len - k + 1)
		p = p->next;
	return p;
}
#else
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	ListNode* p = pListHead;
	int len = 0;
	while (p != NULL) {
		len++;
		p = p->next;
	}
	if (len < k) return NULL;
	int i = 0;
	p = pListHead;
	while (p != NULL && ++i < (len - k + 1)) 
		p = p->next;
	return p;
}
#endif

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
	ListNode* p = (&head);
	while (p)
	{
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;
	int k = 8;
	if (p = FindKthToTail(&head, 8))
	{
		cout << k << "th:"<< p->val << endl;
	}
	return 0;
}