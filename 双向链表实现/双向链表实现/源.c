#define _CRT_SECURE_NO_WARNINGS 1
#include"DList.h"
DListNode* BuyDListNode(DataType x)
{
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	if (newNode == NULL)
	{
		printf("创建失败\n");
	}
	newNode->_data = x;
	newNode->_next = NULL;
	newNode->_prev = NULL;
	return newNode;
}
DListNode* DListInit()
{
	DListNode* Head = (DListNode*)malloc(sizeof(DListNode));
	if (Head== NULL)
	{
		printf("创建失败\n");
		return NULL;
	}
	Head->_next = Head;
	Head->_prev = Head;
	return Head;
}
void DListDestory(DListNode* head)
{
	assert(head);
	DListNode* next = head;
	DListNode* cur = head;
	if (head == NULL)
	{
		return;
	}
	while (next)
	{
		cur = next;
		next = next->_next;
		free(cur);
		cur = NULL;
	}
	head = NULL;
}
void DListPrint(DListNode* head)
{

	DListNode*next = head->_next;
	if (head == NULL)
	{
		printf("链表为空\n");
		return;
	}
	printf("Head->");
	while (next != head)
	{

		printf("%d->", next->_data);
		next = next->_next;
	}
	printf("Head\n");
}
void DListPushBack(DListNode* head, DataType x)
{
	DListNode*newNode = BuyDListNode(x);
	DListNode*prev = head->_prev;
	newNode->_next = head;
	newNode->_prev = prev;
	prev->_next = newNode;
	head->_prev = newNode;
}
void DListPushFront(DListNode* head, DataType x)
{
	DListNode*newNode = BuyDListNode(x);
	DListNode*next = head->_next;
	newNode->_next = next;
	next->_prev = newNode;
	newNode->_prev = head;
	head->_next = newNode;
}
void DListPopBack(DListNode* head)
{
	assert(head);
	DListNode*prev1 = head->_prev;
	DListNode*prev2 = prev1->_prev;
	prev2->_next = head;
	head->_prev = prev2;
	free(prev1);

}
void DListPopFront(DListNode* head)
{
	assert(head);
	DListNode*next1 = head->_next;
	DListNode*next2 = next1->_next;
	head->_next = next2;
	next2->_prev = head;
	free(next1);
}
DListNode* DListFind(DListNode* head, DataType x)
{
	assert(head);
	DListNode*cur = NULL;
	DListNode*next = head;
	while (next != cur)
	{
		if (next->_data == x)
		{
			return next;
		}
		next = next->_next;
		cur = head;
	}
	printf("寻找元素不存在\n");
	return NULL;
}
void DListInsert(DListNode* pos, DataType x)
{
	assert(pos);
	DListNode*newNode = BuyDListNode(x);
	DListNode*prev = pos->_prev;
	newNode->_next = pos;
	pos->_prev = newNode;
	newNode->_prev = prev;
	prev->_next = newNode;
}
void DListErase(DListNode* pos)
{
	assert(pos);
	DListNode*prev = pos->_prev;
	DListNode*next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;
}
int main()
{
	DListNode* list = DListInit();
	DListNode* pos;
	DListPushBack(list, 1);
	DListPushBack(list, 2);
	DListPushBack(list, 3);
	DListPushBack(list, 4);
	DListPushBack(list, 5);
	DListPrint(list);
	DListPushFront(list, 10);
	DListPrint(list);
	pos = DListFind(list, 2);
	DListInsert(pos, 20);
	DListPrint(list);
	pos = DListFind(list, 20);
	DListErase(pos);
	DListPrint(list);
	DListPopBack(list);
	DListPrint(list);
	DListPopFront(list);
	DListPrint(list);
	system("pause");
	return 0;
}
