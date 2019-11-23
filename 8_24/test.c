#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
typedef struct BTNode
{
	struct BTNode* _left;
	struct BTNode* _right;
	char _data;
}BTNode;

BTNode* CreateTree(char* str, int* pi)
{
	if (str[*pi] == '#')
	{
		return NULL;
	}
	else
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = str[*pi];
		++(*pi);
		root->_left = CreateTree(str, pi);
		++(*pi);
		root->_right = CreateTree(str, pi);
		return root;
	}
}

void InOrder(BTNode* root)
{
	if (root == NULL) return;

	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}

int main()
{
	char str[100] = { 0 };
	scanf("%s", str);
	int i = 0;
	BTNode* tree = CreateTree(str, &i);
	InOrder(tree);
	return 0;
}

