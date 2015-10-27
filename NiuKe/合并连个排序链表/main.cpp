/*
 * 输入两个单调递增的链表，输出两个链表合成后的链表，
 * 当然我们需要合成后的链表满足单调不减规则。
 */
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	ListNode* h1 = NULL;
	ListNode* h2 = NULL;
	ListNode* h = NULL;
	if (NULL == pHead1)
		return pHead2;
	if (NULL == pHead2)
		return pHead1;
	if (pHead1->val < pHead2->val)
	{
		h1 = pHead1;
		h2 = pHead2;
	}
	else
	{
		h1 = pHead2;
		h2 = pHead1;
	}
	h = h1;
	ListNode* h11 = NULL;
	ListNode* h22 = NULL;
	while (h2)
	{
		while (h1 && (h2->val > h1->val))		// find the first one in h1 >= h2
		{
			h11 = h1;
			h1 = h1->next;
		}

		if (h1 == NULL)
		{
			h11->next = h2;
			break;
		}
		else
		{
			h22 = h2->next;
			h2->next = h1;
			h11->next = h2;
			h11 = h11->next;
			h2 = h22;
		}
	}
	return h;
}
void printList(ListNode* head)
{
	ListNode* p = head;
	while (p)
	{
		cout << p->val << '\t';
		p = p->next;
	}
	cout << endl;
}

int main(void)
{
	ListNode head1(-1);
	ListNode head2(-2);
	ListNode n01(2);
	ListNode n02(3);
	ListNode n03(4);
	ListNode n11(-3);
	ListNode n12(-4);
	ListNode n13(5);
	ListNode n14(6);

	//head1.next = &n01;
	//n01.next = &n02;
	//n02.next = &n03;
	cout << "Head1:\n";
	printList(&head1);

	//head2.next = &n11;
	//n11.next = &n12;
	//n12.next = &n13;
	//n13.next = &n14;
	cout << "Head2:\n";
	printList(&head2);
	
	ListNode* newHead = Merge(NULL, &head2);
	cout << "newHead:\n";
	printList(newHead);

	return 0;
}