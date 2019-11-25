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
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;

	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
	if (root == NULL)
		return NULL;

	int depth = maxDepth(root);
	int** levelArray = (int**)malloc(sizeof(int*)*depth);

	int maxLevelSize = 1000;//pow(2, depth-1);
	struct TreeNode** a1 = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*maxLevelSize);

	struct TreeNode** a2 = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*maxLevelSize);
	int a1Size = 0;
	int a2Size = 0;

	*returnSize = depth;
	*columnSizes = (int*)malloc(sizeof(int)*depth);

	if (root)
	{
		a1[0] = root;
		a1Size = 1;
	}

	int level = 0;
	while (level < depth)
	{
		levelArray[level] = malloc(sizeof(int)*a1Size);
		for (int i = 0; i < a1Size; ++i)
		{
			levelArray[level][i] = a1[i]->val;
		}
		(*columnSizes)[level] = a1Size;

		int k = 0;
		for (int j = 0; j < a1Size; ++j)
		{
			if (a1[j]->left)
				a2[k++] = a1[j]->left;

			if (a1[j]->right)
				a2[k++] = a1[j]->right;
		}
		a2Size = k;

		struct TreeNode** a = a1;
		a1 = a2;
		a2 = a;

		a1Size = a2Size;
		a2Size = 0;

		++level;
	}

	return levelArray;
}