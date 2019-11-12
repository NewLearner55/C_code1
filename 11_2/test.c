#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
#include<string.h>

struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL)
	{
		return head;
	}
	struct ListNode *pre = NULL;
	struct ListNode *curr = head;
	struct ListNode *next = 0;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = pre;
		pre = curr;
		curr = next;
	}
	return pre;
}