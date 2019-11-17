#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		printf("%d ", a[i]);
	}
}

void ShellSort(int* a, int n)
{
	int gap = 0;
	gap = gap / 3 + 1;
	for (int i = 0; i < n - gap; ++i)
	{
		int end = i;
		int tmp = a[end + gap];
		while (end >= 0 && a[end]>tmp)
		{
			a[end + gap] = a[end];
			end -= gap;
		}
		a[end + gap] = tmp;
	}
}
void SortTest()
{
	int arr[] = { 3, 7, 9, 1, 4, 2, 8, 5, 4, 8, 6 };
	ShellSort(arr,sizeof(arr)/sizeof(int));
	PrintArray(arr, sizeof(arr)/sizeof(int));
	printf("\n");
}