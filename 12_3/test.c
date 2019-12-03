#define _CRT_SECURE_NO_WARNINGS 1
typedef int QUDataType;

typedef struct QueueNode
{
	QUDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _rear;
}Queue;

void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
}

void QueueDestory(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}

	q->_front = q->_rear = NULL;
}

QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->_data = x;
	node->_next = NULL;
	return node;
}

void QueuePush(Queue* q, QUDataType x)
{
	assert(q);
	if (q->_front == NULL)
	{
		q->_front = q->_rear = BuyQueueNode(x);
	}
	else
	{
		q->_rear->_next = BuyQueueNode(x);
		q->_rear = q->_rear->_next;
	}
}

void QueuePop(Queue* q)
{
	if (q->_front)
	{
		QueueNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;

		if (q->_front == NULL)
		{
			q->_rear = NULL;
		}
	}
}

int QueueSize(Queue* q)
{
	assert(q);
	int size = 0;
	QueueNode* cur = q->_front;
	while (cur)
	{
		++size;
		cur = cur->_next;
	}

	return size;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front == NULL ? 0 : 1;
}

QUDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}

QUDataType QueueBack(Queue* q)
{
	assert(q);

	return q->_rear->_data;
}

typedef struct {
	Queue q1;
	Queue q2;

} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);

	return pst;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (QueueEmpty(&obj->q1) != 0)
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Queue* pEmpty = &obj->q1, *pNonEmpty = &obj->q2;
	if (QueueEmpty(&obj->q1) != 0)
	{
		pEmpty = &obj->q2;
		pNonEmpty = &obj->q1;
	}

	while (QueueSize(pNonEmpty) > 1)
	{
		QueuePush(pEmpty, QueueFront(pNonEmpty));
		QueuePop(pNonEmpty);
	}

	int top = QueueFront(pNonEmpty);
	QueuePop(pNonEmpty);

	return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	Queue* pEmpty = &obj->q1, *pNonEmpty = &obj->q2;
	if (QueueEmpty(&obj->q1) != 0)
	{
		pEmpty = &obj->q2;
		pNonEmpty = &obj->q1;
	}

	return QueueBack(pNonEmpty);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return !(QueueEmpty(&obj->q1) | QueueEmpty(&obj->q2));
}

void myStackFree(MyStack* obj) {
	QueueDestory(&obj->q1);
	QueueDestory(&obj->q2);
	free(obj);
}

/**
* Your MyStack struct will be instantiated and called as such:
* struct MyStack* obj = myStackCreate(maxSize);
* myStackPush(obj, x);
* int param_2 = myStackPop(obj);
* int param_3 = myStackTop(obj);
* bool param_4 = myStackEmpty(obj);
* myStackFree(obj);
*/