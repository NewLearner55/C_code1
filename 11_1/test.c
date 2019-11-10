#define _CRT_SECURE_NO_WARNINGS 1
#include"common.h"
#include"seqlist.h"

int main(int argc, char *argv[])
{
	SeqList mylist;
	SeqListInit(&mylist, DEFAULT_SIZE);

	DataType item;
	int pos, index;
	BOOL flag;
	int select = 1;
	while (select)
	{
		printf("************************************\n");
		printf("* [1] push_back     [2] push_front *\n");
		printf("* [3] show_list     [0] quit_system*\n");
		printf("* [4] pop_back      [5] pop_front  *\n");
		printf("* [6] find_pos      [7] find_val   *\n");
		printf("* [8] insert_pos    [9] delete_val *\n");
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
				SeqListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&mylist, item);
			}
			break;
		case 3:
			SeqListShow(&mylist);
			break;
		case 4:
			SeqListPopBack(&mylist);
			break;
		case 5:
			SeqListPopFront(&mylist);
			break;
		case 6:
			printf("请输入要查询的位置:>");
			scanf("%d", &pos);
			printf("要查询的数据:%d\n", SeqListFindByPos(&mylist, pos));
			break;
		case 7:
			printf("请输入要查询的数据:>");
			scanf("%d", &item);
			index = SeqListFindByVal(&mylist, item);
			if (index == -1)
				printf("要查询的数据%d不存在.\n", item);
			else
				printf("要查询数据的下标为:>%d\n", index);
			break;
		case 8:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			flag = SeqListInsertByPos(&mylist, pos, item);
			if (flag)
				printf("插入成功.\n");
			else
				printf("插入失败.\n");
			break;
		case 9:
			printf("请输入要删除的数据:>");
			scanf("%d", &item);
			flag = SeqListEraseByVal(&mylist, item);
			break;
		case 10:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			flag = SeqListEraseByPos(&mylist, pos);
			if (flag)
				printf("删除成功.\n");
			else
				printf("删除失败.\n");
			break;
		case 11:
			printf("SeqList Length = %d\n", SeqListLength(&mylist));
			break;
		case 12:
			printf("请输入要删除的数据:>");
			scanf("%d", &item);
			SeqListRemoveAll(&mylist, item);
			break;
		case 13:
			SeqListReverse(&mylist);
			break;
		case 14:
			SeqListSort(&mylist);
			break;
		case 15:
			SeqListClear(&mylist);
			break;
		}
	}

	SeqListDestroy(&mylist);
	return 0;
}
