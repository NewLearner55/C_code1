#define _CRT_SECURE_NO_WARNINGS 1
/**
<<<<<<< HEAD
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
	else
		return GetTreeSize(root->left) + GetTreeSize(root->right) + 1;
=======
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
    if(root == NULL) 
        return 0;
    else
        return GetTreeSize(root->left) + GetTreeSize(root->right) + 1;
>>>>>>> 39dc5627ea9445ec92d2b253cb7eedcf0f8d6c20
}

void _inorderTraversal(struct TreeNode* root, int* array, int* pIndex)
{
<<<<<<< HEAD
	if (root == NULL)
		return;

	_inorderTraversal(root->left, array, pIndex);

	array[*pIndex] = root->val;
	(*pIndex)++;

	_inorderTraversal(root->right, array, pIndex);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = GetTreeSize(root);
	int* array = (int*)malloc(*returnSize*sizeof(int));
	int index = 0;
	_inorderTraversal(root, array, &index);

	return array;
}
=======
    if(root == NULL)
        return;
    
    _inorderTraversal(root->left, array, pIndex);
    
    array[*pIndex] = root->val;
    (*pIndex)++;
    
   _inorderTraversal(root->right, array, pIndex); 
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = GetTreeSize(root);
    int* array = (int*)malloc(*returnSize*sizeof(int));
    int index = 0;
    _inorderTraversal(root, array, &index);
    
    return array;
}
>>>>>>> 39dc5627ea9445ec92d2b253cb7eedcf0f8d6c20
