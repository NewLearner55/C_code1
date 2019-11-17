#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL)
		return l2;
	else if (l2 == NULL)
		return l1;

	// 先取一个小的节点做头
	struct ListNode* head, *tail;
	if (l1->val < l2->val)
	{
		head = l1;
		l1 = l1->next;
	}
	else
	{
		head = l2;
		l2 = l2->next;
	}

	// 取小的节点进行尾插
	tail = head;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}

	if (l1 != NULL)
		tail->next = l1;

	if (l2 != NULL)
		tail->next = l2;

	return head;
}

