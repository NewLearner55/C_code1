#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
struct TreeNode* _buildTree(int* prevorder, int* pindex, int* inorder, int inbegin, int inend)
{
	if (inbegin > inend)
		return NULL;

	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = prevorder[*pindex];

	int rootindex = inbegin;
	for (; rootindex <= inend; ++rootindex)
	{
		if (inorder[rootindex] == root->val)
			break;
	}

	if (inbegin <= rootindex - 1)
	{
		(*pindex)++;
		root->left = _buildTree(prevorder, pindex, inorder, inbegin, rootindex - 1);
	}
	else
	{
		root->left = NULL;
	}

	if (rootindex + 1 <= inend)
	{
		(*pindex)++;
		root->right = _buildTree(prevorder, pindex, inorder, rootindex + 1, inend);
	}
	else
	{
		root->right = NULL;
	}


	return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	int index = 0;
	return _buildTree(preorder, &index, inorder, 0, inorderSize - 1);
}