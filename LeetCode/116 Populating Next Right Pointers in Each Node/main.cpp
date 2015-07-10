/*********************************************************************************************
 * Given a binary tree
 *
    struct TreeLinkNode 
    {
		TreeLinkNode *left;
		TreeLinkNode *right;
		TreeLinkNode *next;
	}
 * Populate each next pointer to point to its next right node.
 * If there is no next right node, the next pointer should be set to NULL.

 * Initially, all next pointers are set to NULL.

 * Note:

 * You may only use constant extra space.
 * You may assume that it is a perfect binary tree(ie, all leaves are at the same level, 
 * and every parent has two children).
 * For example,
 * Given the following perfect binary tree,
 *      1
 *     / \
 *   2     3
 *  / \   / \
 * 4   5 6   7
 * After calling your function, the tree should look like :
 *     1->NULL
 *   /   \
 *  2 ->  3->NULL
 * / \   / \
 * 4->5->6->7->NULL
 *******************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root)
{
	if (root)
	{
		if (root->left != NULL)
		{
			root->left->next = root->right;
		}
		if (root->right != NULL && root->next != NULL)
		{
			root->right->next = root->next->left;
		}
		connect(root->left);
		connect(root->right);
	}
}

vector<int> rst;
vector<int> preorderTraversal(TreeLinkNode* root)
{
	if (root != NULL)
	{
		cout << root->val << '\t';
		if (root->next == NULL)
			cout << "->\tNULL" << endl;
		else
			cout << "->\t" << root->next->val << endl;
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}

	return rst;
}

int main(void)
{
	TreeLinkNode root(0);
	TreeLinkNode node1(1), node2(2), node3(3), node4(4), node5(5), node6(6), node7(7);
	TreeLinkNode node8(8), node9(9), node10(10), node11(11), node12(12), node13(13), node14(14);

	root.left = &node1;
	root.right = &node2;
	node1.left = &node3;
	node1.right = &node4;
	node2.left = &node5;
	node2.right = &node6;
	node3.left = &node7;
	node3.right = &node8;
	node4.left = &node9;
	node4.right = &node10;
	node5.left = &node11;
	node5.right = &node12;

	preorderTraversal(&root);
	connect(&root);
	cout << endl;
	preorderTraversal(&root);
	return 0;
}