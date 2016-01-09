/*****************************************************************************
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * For example :
 * Given binary tree{ 1, #, 2, 3 },
 *  1
 *   \
 *    2
 *   /
 *  3
 *
 * return[1, 2, 3].
 ****************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#define CPP		0

#if CPP
vector<int> rst;
vector<int> preorderTraversal(TreeNode* root)
{
	if (root != NULL)
	{
		rst.push_back(root->val);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}

	return rst;
}
#else
int rst[1024];
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	if (root == NULL)
		return NULL;

	preorderTraversal(root->left, returnSize);
	rst[(*returnSize)++] = root->val;
	preorderTraversal(root->right, returnSize);

	return rst;
}
#endif

int main(void)
{
	TreeNode root(0);
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(4);
	TreeNode node5(5);
	TreeNode node6(6);
	TreeNode node7(7);

	root.left = &node1;
	root.right = &node2;
	node1.left = &node3;
	node1.right = &node4;
#if CPP
	vector<int> rst = preorderTraversal(&root);
	for (int i = 0; i < rst.size(); i++)
	{
		cout << rst[i] << endl;
	}
#else
	int size = 0;
	int *r = preorderTraversal(&root, &size);
	for (size_t i = 0; i < size; i++)
	{
		cout << r[i] << endl;
	}
#endif
	return 0;
}

