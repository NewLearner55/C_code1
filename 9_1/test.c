#define _CRT_SECURE_NO_WARNINGS 1
typedef struct {
	int* queue;
	int front;
	int rear;
	int k
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* pcq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	pcq->queue = (int*)malloc(sizeof(int)*(k + 1));
	pcq->front = 0;
	pcq->rear = 0;
	pcq->k = k;

	return pcq;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if ((obj->rear + 1) % (obj->k + 1) == obj->front)
	{
		return false;
	}

	obj->queue[obj->rear++] = value;
	if (obj->rear == obj->k + 1)
		obj->rear = 0;

	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		return false;

	++obj->front;
	if (obj->front == obj->k + 1)
		obj->front = 0;

	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		return -1;
	else
		return obj->queue[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		return -1;

	if (obj->rear == 0)
		return obj->queue[obj->k];
	else
		return obj->queue[obj->rear - 1];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->rear;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return (obj->rear + 1) % (obj->k + 1) == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->queue);
	free(obj);
}

/**
* Your MyCircularQueue struct will be instantiated and called as such:
* struct MyCircularQueue* obj = myCircularQueueCreate(k);
* bool param_1 = myCircularQueueEnQueue(obj, value);
* bool param_2 = myCircularQueueDeQueue(obj);
* int param_3 = myCircularQueueFront(obj);
* int param_4 = myCircularQueueRear(obj);
* bool param_5 = myCircularQueueIsEmpty(obj);
* bool param_6 = myCircularQueueIsFull(obj);
* myCircularQueueFree(obj);
*/