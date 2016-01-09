#include <iostream>
#include <fstream>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

int maxDepth(TreeNode* root);

int main(void)
{
	TreeNode root(0);
	TreeNode node1(1), node2(2), node3(3), node4(4), node5(5), node6(6), node7(7), node8(8);

	root.left = &node1;
	root.val = 0;

	node1.left = &node2;

	cout << maxDepth(&root) << endl;

	return 0;
}
#define max(a,b)	((a)>(b)? (a):(b))
int maxDepth(TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
	{
		return 1 + (max(maxDepth(root->left), maxDepth(root->right)));
	}
}