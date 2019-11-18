#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void BubbleSort(int* a, int n)
{
	assert(a);
	int end = n;
	int flag = 0;
	while (end > 0)
	{
		for (int i = 1; i < end; i++)
		{
			if (a[i-1]>a[i])
			{
				Swap(&a[i-1], &a[i]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
		--end;
	}
}


void BubbleSortTest()
{
	int arr[] = { 9, 3, 4, 1, 6, 7, 0, 5, 8, 1, 9 };
	BubbleSort(arr, sizeof(arr) / sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));
	printf("\n");
}