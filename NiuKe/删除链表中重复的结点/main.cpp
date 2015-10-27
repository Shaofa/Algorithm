/*
 * ��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 
 * ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
 */

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};


ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	ListNode* p = pHead;
	ListNode* q = p->next;
	while (p && q)
	{
		if (p->val == q->val)
		{

		}
		p = q->next;
		if (p)
		{
			q = p->next;
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
	ListNode head(-1);
	ListNode n01(2);
	ListNode n02(3);
	ListNode n03(4);
	ListNode n04(4);
	ListNode n05(4);
	ListNode n06(4);
	ListNode n07(6);

	head.next = &n01;
	n01.next = &n02;
	n02.next = &n03;
	n03.next = &n04;
	n04.next = &n05;
	n05.next = &n06;
	n06.next = &n07;
	printList(&head);

	ListNode* newHead = deleteDuplication(&head);
	cout << "newHead:\n";
	printList(newHead);

	return 0;
}