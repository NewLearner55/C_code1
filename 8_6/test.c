#define _CRT_SECURE_NO_WARNINGS 1
#include"common.h"
#include"slist.h"


int main(int argc, char *argv[])
{
	//SeqList mylist;

	SListNode *p = NULL;
	SList mylist;
	SListInit(&mylist);

	DataType item;
	BOOL flag;
	int select = 1;
	while (select)
	{
		printf("************************************\n");
		printf("* [1] push_back     [2] push_front *\n");
		printf("* [3] show_list     [0] quit_system*\n");
		printf("* [4] find_val      [5] insert_val *\n");
		printf("* [6] erase_val     [7] length     *\n");
		printf("* [8] reverse       [9] clear      *\n");
		printf("************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)
			{
				SListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)
			{
				SListPushFront(&mylist, item);
			}
			break;
		case 3:
			SListShow(&mylist);
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			printf("������Ҫ��ѯ������:>");
			scanf("%d", &item);
			p = SListFindByVal(&mylist, item);
			if (p == NULL)
				printf("Ҫ��ѯ������%d������.\n", item);
			break;
		case 8:
			printf("������Ҫ���������:>");
			scanf("%d", &item);
			flag = SListInsertByVal(&mylist, item);
			if (flag)
				printf("����ɹ�.\n");
			else
				printf("����ʧ��.\n");
			break;
		case 9:
			printf("������Ҫɾ��������:>");
			scanf("%d", &item);
			SListEraseByVal(&mylist, item);
			break;
		case 10:
			break;
		case 11:
			printf("SList Length = %d\n", SListLength(&mylist));
			break;
		case 12:
			printf("������Ҫɾ��������:>");
			scanf("%d", &item);
			break;
		case 13:
			SListReverse(&mylist);
			break;
		case 14:
			break;
		case 15:
			SListClear(&mylist);
			break;
		}
	}

	SListDestroy(&mylist);
	return 0;
}