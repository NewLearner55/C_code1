#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void InsertSort(int* arr, int n)
{
	assert(arr);
	int i = 0;
	for (i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0 && arr[end]>tmp)
		{
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = tmp;
	}
}
void TestInsertSort()
{
	int arr[] = { 3, 4, 7, 8, 2, 1, 6, 4, 5, 9, 1 };
	InsertSort(arr, sizeof(arr) / sizeof(int));
	PrintArray(arr,sizeof(arr)/sizeof(int));
}