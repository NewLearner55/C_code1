#define _CRT_SECURE_NO_WARNINGS 1
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
	struct ListNode* reverseList(struct ListNode* head) {
		struct ListNode* newhead = NULL;
		struct ListNode* cur = head;
		while (cur)
		{
			struct ListNode* next = cur->next;
			cur->next = newhead;
			newhead = cur;
			cur = next;
		}

		return newhead;
	}

	bool chkPalindrome(ListNode* A) {
		int n = 0;
		struct ListNode* cur = A;
		while (cur)
		{
			cur = cur->next;
			++n;
		}

		cur = A;
		int mid = n / 2;
		while (mid--)
		{
			cur = cur->next;
		}

		struct ListNode* head1 = A;
		struct ListNode* head2 = reverseList(cur);

		mid = n / 2;
		while (mid--)
		{
			if (head1->val == head2->val)
			{
				head1 = head1->next;
				head2 = head2->next;
			}
			else
			{
				return false;
			}
		}

		return true;
	}
};

»ò

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		int a[900];
		int n = 0;
		struct ListNode* cur = A;
		while (cur)
		{
			a[n++] = cur->val;
			cur = cur->next;
		}

		int left = 0, right = n - 1;
		while (left < right)
		{
			if (a[left] != a[right])
				return false;
			++left;
			--right;
		}

		return true;
	}
};