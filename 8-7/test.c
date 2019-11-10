#define _CRT_SECURE_NO_WARNINGS 1
#include"common.h"
#include"dclist.h"
int main(int argc, char *argv[])
{

	DCListNode *p = NULL;
	DCList mylist; 
	DCListInit(&mylist);

	DataType item;
	BOOL flag=TRUE;
	int select = 1;
	while (select)
	{
		printf("************************************\n");
		printf("* [1] push_back     [2] push_front *\n");
		printf("* [3] show_list     [0] quit_system*\n");
		printf("* [4] pop_back      [5] pop_front  *\n");
		printf("* [6] find_pos      [7] find_val   *\n");
		printf("* [8] insert_val    [9] delete_val *\n");
		printf("* [10] delete_pos   [11]length     *\n");
		printf("* [12] remove_all   [13] reverse   *\n");
		printf("* [14] sort         [15] clear     *\n");
		printf("************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)
			{
				DCListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)
			{
				DCListPushFront(&mylist, item);
			}
			break;
		case 3:
			DCListShow(&mylist);
			break;
		case 4:
			DCListPopBack(&mylist);
			break;
		case 5:
			DCListPopFront(&mylist);
			break;
		case 6:
			break;
		case 7:
			printf("请输入要查询的数据:>");
			scanf("%d", &item);
			p = DCListFindByVal(&mylist, item);
			if (p == NULL)
				printf("要查询的数据%d不存在.\n", item);
			break;
		case 8:
			break;
		case 9:
			printf("请输入要删除的数据:>");
			scanf("%d", &item);
			DCListEraseByVal(&mylist, item);
			break;
		case 10:
			if (flag)
				printf("删除成功.\n");
			else
				printf("删除失败.\n");
			break;
		case 11:
			printf("DCList Length = %d\n", DCListLength(&mylist));
			break;
		case 12:
			break;
		case 13:
			DCListReverse(&mylist);
			break;
		case 14:
			DCListSort(&mylist);
			break;
		case 15:
			DCListClear(&mylist);
			break;
		}
	}

	DCListDestroy(&mylist);
	return 0;
}
