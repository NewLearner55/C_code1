#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

char valuestr[30] = { 0 };
void _tree2str(struct TreeNode* t, char* str) {
	if (t == NULL)
		return;

	//_itoa(t->val, valuestr, 10);
	sprintf(valuestr, "%d", t->val);
	strcat(str, valuestr);

	if (t->left == NULL)
	{
		if (t->right == NULL)
			return;
		else
			strcat(str, "()");
	}
	else
	{
		strcat(str, "(");
		_tree2str(t->left, str);
		strcat(str, ")");
	}

	if (t->right == NULL)
	{
		return;
	}
	else
	{
		strcat(str, "(");
		_tree2str(t->right, str);
		strcat(str, ")");
	}
}

char str[100000];
char* tree2str(struct TreeNode* t) {
	str[0] = '\0';
	_tree2str(t, str);

	return str;
}
