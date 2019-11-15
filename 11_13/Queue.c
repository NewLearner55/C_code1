#define _CRT_SECURE_NO_WARNINGS 1
#include"common.h"
#include"Queue.h"
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}
void QueueDestroy(Queue* q)
{
	assert(q);
	QueueNode* cur = q->front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur->_next;
	}
	q->front = q->rear = NULL;
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
	if (q->front == NULL)
	{
		q->front = q->rear = BuyQueueNode(x);
	}
	else
	{
		q->rear->_next = BuyQueueNode(x);
		q->rear = q->rear->_next;
	}
}
void QueuePop(Queue* q)
{
	if (q->front)
	{
		QueueNode* next = q->front = q->front->_next;
		q->front = next;
	}
	if (q->front == NULL)
	{
		q->rear = NULL;
	}
}
int QueueSize(Queue* q)
{
	assert(q);
	int size = 0;
	QueueNode* cur = q->front;
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
	return q->front == NULL ? 0 : 1;
}
QUDataType QueueFront(Queue* q)
{
	assert(q);
	return q->front->_data;
}
QUDataType QueueBack(Queue* q)
{
	assert(q);
	return q->rear->_data;
}
void QueueTest()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q , 1);
	QueuePush(&q , 2);
	QueuePush(&q , 3);
	QueuePush(&q , 4);
	while (QueueEmpty(&q))
	{
		printf("front:%d\n", QueueFront(&q));
		QueuePop(&q);
	}
}