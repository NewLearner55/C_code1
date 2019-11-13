#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* middleNode(struct ListNode* head)
{
	if (head == NULL)
	{
		return head;
	}
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
