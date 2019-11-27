#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;

	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}


// O(N^2)的算法
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int _maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;

	int leftDepth = _maxDepth(root->left);
	int rightDepth = _maxDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
		return true;

	int leftDepth = _maxDepth(root->left);
	int rightDepth = _maxDepth(root->right);
	return abs(leftDepth - rightDepth) < 2
		&& isBalanced(root->left)
		&& isBalanced(root->right);
}

// O(N)的算法
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool _isBalanced(struct TreeNode* root, int* pDepth) {
	if (root == NULL) {
		*pDepth = 0;
		return true;
	}

	int leftDepth = 0, rightDepth = 0;
	if (_isBalanced(root->left, &leftDepth)
		&& _isBalanced(root->right, &rightDepth)
		&& abs(leftDepth - rightDepth) < 2)
	{
		*pDepth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
		return true;
	}
	else
	{
		return false;
	}

}

bool isBalanced(struct TreeNode* root) {
	int depth = 0;
	return _isBalanced(root, &depth);
}
