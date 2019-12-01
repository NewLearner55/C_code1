#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool FindNode(struct TreeNode* root, struct TreeNode* node) {
	if (root == NULL)
		return false;

	if (root == node)
		return true;

	return FindNode(root->left, node)
		|| FindNode(root->right, node);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	if (root == NULL)
		return NULL;

	if (root == p || root == q)
		return root;

	bool pInLeft, pInRight, qInLeft, qInRight;
	if (FindNode(root->left, p)){
		pInLeft = true;
		pInRight = false;
	}
	else{
		pInRight = true;
		pInLeft = false;
	}

	if (FindNode(root->left, q)) {
		qInLeft = true;
		qInRight = false;
	}
	else {
		qInRight = true;
		qInLeft = false;
	}

	if (pInLeft && qInLeft){
		return lowestCommonAncestor(root->left, p, q);
	}
	else if (pInRight && qInRight){
		return lowestCommonAncestor(root->right, p, q);
	}
	else {
		return root;
	}
}