/*
 * 输入一个链表，从尾到头打印链表每个节点的值。
 */
#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
            val(x), next(NULL) {
      }
};


vector<int> printListFromTailToHead(struct ListNode* head) 
{
	vector<int> rst;
	vector<int>::iterator it;
	ListNode* p = head->next;

	while (p != NULL){
		it = rst.begin();
		rst.insert(it, p->val);
		p = p->next;
	}
	return rst;
}


int main(void)
{
	ListNode head(0);
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);

	head.next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	vector<int> result = printListFromTailToHead(&head);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}