#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* removeElements(struct ListNode* head, int val)
{
	if (head == NULL)
	{
		return head;
	}
	struct ListNode* pre = NULL;
	struct ListNode* cur = head;
	while (cur)
	{
		if (cur->val == val)
		{
			struct ListNode* next = cur->next;
			if (pre == NULL)
			{
				head = next;
			}
			else
			{
				pre->next = next;
			}
			free(cur);
			cur = next;
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
	return head;
}