#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n ; i++)
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
void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin<end)
	{
		int max = begin;
		int min = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] >= a[max])
			{
				max = i;
			}
			if (a[i] < a[min])
			{
				min = i;
			}
		}
		Swap(&a[begin], &a[min]);
		if (begin == max)
		{
		max = min;
		}
		Swap(&a[end], &a[max]);
		++begin;
		--end;
	}
}

void SelectSortTest()
{
	int arr[] = {9, 3, 4, 1, 6, 7, 0, 5, 8, 1, 9};
	SelectSort(arr, sizeof(arr) / sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));
	printf("\n");
}