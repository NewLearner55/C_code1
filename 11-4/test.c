#define _CRT_SECURE_NO_WARNINGS 1

struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode* newhead = NULL;
	struct ListNode* cur = head;
	if (head == NULL)
	{
		return head;
	}
	while (cur)
	{
		struct ListNode* next = cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	return newhead;
}