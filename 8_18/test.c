#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

int GetTreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	return GetTreeSize(root->left)
		+ GetTreeSize(root->right)
		+ 1;
}

void _preorderTraversal(struct TreeNode* root, int* array, int* pIndex)
{
	if (root == NULL)
		return;

	array[*pIndex] = root->val;
	++(*pIndex);
	_preorderTraversal(root->left, array, pIndex);
	_preorderTraversal(root->right, array, pIndex);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = GetTreeSize(root);
	int* array = (int*)malloc(*returnSize * sizeof(int));
	int index = 0;

	_preorderTraversal(root, array, &index);

	return array;
}