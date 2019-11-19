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
int PartSort(int* a, int begin, int end)
{
	int key = a[begin];
	int start = begin;
	while (begin < end)
	{
		//end’“–°
		while (begin<end && a[end] >= key)
		{
			--end;
		}
		//begin’“¥Û
		while (begin<end && a[begin]<=key)
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[start]);
	return begin;
}
void Qsort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int div = PartSort(a,left,right);
	Qsort(a, left, div-1);
	Qsort(a, div + 1, right);
}
void QsortTest()
{
	int arr[] = { 3, 4, 7, 8, 1, 2, 5, 6, 0 };
	Qsort(arr,0,sizeof(arr)/sizeof(int)-1);
	PrintArray(arr, sizeof(arr) / sizeof(int));
}