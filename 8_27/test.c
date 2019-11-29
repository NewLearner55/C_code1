#define _CRT_SECURE_NO_WARNINGS 1
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	void _Convert(TreeNode* cur, TreeNode** pprev)
	{
		if (cur == NULL)
			return;
		_Convert(cur->left, pprev);

		// �����ߣ���ǰ�ڵ����ָ��ǰһ��
		// ǰһ���ڵ����ָ��ǰ�ڵ�
		cur->left = *pprev;
		if (*pprev)
			(*pprev)->right = cur;

		*pprev = cur;

		_Convert(cur->right, pprev);
	}

	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		TreeNode* prev = NULL;
		_Convert(pRootOfTree, &prev);

		TreeNode* head = pRootOfTree;
		while (head && head->left)
		{
			head = head->left;
		}

		return head;
	}
};