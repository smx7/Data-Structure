#include<stdio.h>
#include<windows.h>
#include<assert.h>

typedef int DataType;

typedef struct QueueNode
{
	DataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
	DataType _size;
}Queue;

Queue* QueueInit();
void QueuePush(Queue* q, DataType x);
void QueuePop(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
size_t QueueSize(Queue* q);
int QueueEmpty(Queue* q);

void EnStack(Queue* q1, Queue* q2, DataType x);
void DeStack(Queue* q1, Queue* q2);