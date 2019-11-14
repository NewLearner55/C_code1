#define _CRT_SECURE_NO_WARNINGS 1
int* pst;
int stTop;

int* pminST;
int minSTTop;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
	MinStack* pst = (MinStack*)malloc(sizeof(MinStack));
	pst->pst = (int*)malloc(sizeof(int)*maxSize);
	pst->stTop = 0;

	pst->pminST = (int*)malloc(sizeof(int)*maxSize);
	pst->minSTTop = 0;

	return pst;
}

void minStackPush(MinStack* obj, int x) {
	int* pst = obj->pst;
	int* pminST = obj->pminST;

	pst[obj->stTop++] = x;
	if (obj->minSTTop == 0
		|| x <= pminST[obj->minSTTop - 1])
	{
		pminST[obj->minSTTop++] = x;
	}
}

void minStackPop(MinStack* obj) {
	int* pst = obj->pst;
	int* pminST = obj->pminST;
	if (pst[obj->stTop - 1] == pminST[obj->minSTTop - 1])
	{
		--obj->minSTTop;
	}

	--obj->stTop;
}

int minStackTop(MinStack* obj) {
	return obj->pst[obj->stTop - 1];
}

int minStackGetMin(MinStack* obj) {
	return obj->pminST[obj->minSTTop - 1];
}

void minStackFree(MinStack* obj) {
	free(obj->pst);
	free(obj->pminST);
	free(obj);
}

/**
* Your MinStack struct will be instantiated and called as such:
* struct MinStack* obj = minStackCreate(maxSize);
* minStackPush(obj, x);
* minStackPop(obj);
* int param_3 = minStackTop(obj);
* int param_4 = minStackGetMin(obj);
* minStackFree(obj);
*/
