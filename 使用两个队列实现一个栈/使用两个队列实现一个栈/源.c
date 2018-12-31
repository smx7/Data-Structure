#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"
Queue* QueueInit()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if (q == NULL)
	{
		printf("创建失败\n");
		return NULL;
	}
	q->_head = NULL;
	q->_tail = NULL;
	q->_size = 0;
	return q;
}
void QueuePush(Queue* q, DataType x)
{
	assert(q);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("创建失败\n");
		return;
	}
	newNode->_data = x;
	newNode->_next = NULL;
	if (q->_size == 0)
	{
		q->_head = newNode;
		q->_tail = newNode;
	}
	else
	{
		q->_tail->_next = newNode;
		q->_tail = newNode;
	}
	q->_size++;
}
void QueuePop(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_head->_next;
	if (q->_size == 0)
	{
		printf("队列为空无法删除\n");
		return;
	}
	else if (q->_size == 1)
	{
		free(q->_head);
		q->_head = NULL;
		q->_tail = NULL;
	}
	else
	{
		free(q->_head);
		q->_head = cur;
	}
	q->_size--;
}
DataType QueueFront(Queue* q)
{
	assert(q);
	if (q->_size == 0)
	{
		printf("队列为空\n");
		return -1;
	}
	else
	{
		return q->_head->_data;
	}
}
DataType QueueBack(Queue* q)
{
	assert(q);
	if (q->_size == 0)
	{
		printf("队列为空\n");
		return -1;
	}
	else
	{
		return q->_tail->_data;
	}
}
size_t QueueSize(Queue* q)
{
	return (size_t)q->_size;
}
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->_size == 0)
	{
		return 1;
	}
	else
		return 0;
}
void Queueprint(Queue* q)
{
	QueueNode*cur = q->_head;
	if (q->_size == 0)
	{
		printf("队列为空\n");
		return;
	}
	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
void EnStack(Queue* q1, Queue* q2, DataType x)
{
	QueuePush(q1, x);
}
void DeStack(Queue* q1, Queue* q2)
{
	while (q1->_size != 1)
	{
		QueuePush(q2, QueueFront(q1));
		QueuePop(q1);
	}
	QueuePop(q1);
	while (q2->_size != 0)
	{
		QueuePush(q1, QueueFront(q2));
		QueuePop(q2);
	}
}
int main()
{
	Queue *q1 = QueueInit();
	Queue *q2 = QueueInit();
	EnStack(q1, q2, 1);
	EnStack(q1, q2, 2);
	EnStack(q1, q2, 3);
	EnStack(q1, q2, 4);
	EnStack(q1, q2, 5);
	Queueprint(q1);
	DeStack(q1, q2);
	DeStack(q1, q2);
	Queueprint(q1);
	system("pause");
	return 0;
}
