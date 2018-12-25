#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"


SListNode* BuySListNode(DataType x)
{
	SListNode*newNode = (SListNode*)malloc(sizeof(SListNode));//开辟一段空间
	if (NULL == newNode)//创建失败
	{
		printf("to create is failed\n");
	}
	newNode->_data = x;
	newNode->_next = NULL;
	return  newNode;
}

void SListPrint(SListNode* pHead)
{
	if (pHead == NULL)
	{
		printf("链表为空\n");
	}
	while (pHead)
	{
		printf("%d->", pHead->_data);
		pHead = pHead->_next;
	}
	printf("NULL");
	printf("\n");
}
void SListDestory(SListNode** ppHead)
{
	assert(ppHead);
	SListNode*next = *ppHead;;
	SListNode*cur = *ppHead;
	if (*ppHead == NULL)
	{
		return;
	}
	while (next)
	{
		cur = next;
		next = next->_next;
		free(cur);
		cur= NULL;
	}
	*ppHead = NULL;
}
void SListPushBack(SListNode** ppHead, DataType x)
{
	assert(ppHead);
	SListNode*cur;
	if (*ppHead == NULL)//如果是带头节点的空单链表，直接插入
	{
		*ppHead = BuySListNode(x);
		(*ppHead)->_next = NULL;
	}
	else
	{
		cur = *ppHead;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		cur->_next = BuySListNode(x);//当cur走到尾节点时，创建一个新节点。
	}
}
void SListPopBack(SListNode** ppHead)
{
	assert(ppHead);
	SListNode*cur = *ppHead;
	SListNode*prev = NULL;
	if (cur == NULL)
	{
		return;
	}
	else if (cur->_next == NULL)
	{
		cur = NULL;
		free(cur);
	}
	else
	{
		while (cur->_next!=NULL)
		{
			prev = cur;
			cur = cur->_next;
		}
		free(cur);
		prev->_next = NULL;
	}
}
void SListPushFront(SListNode** ppHead, DataType x)
{
	assert(ppHead);
	SListNode*cur = NULL;
	if (*ppHead == NULL)
	{
		*ppHead = BuySListNode(x);
		(*ppHead)->_next = NULL;
	}
	else
	{
		cur = *ppHead;
		*ppHead = BuySListNode(x);
		(*ppHead)->_next = cur;
	}
}
SListNode* SListFind(SListNode* pHead, DataType x)
{
	assert(pHead);
	while (pHead)
	{
		if (x == pHead->_data)
		{
			return pHead;
		}
		pHead = pHead->_next;
	}
	printf("寻找元素不存在\n");
	return NULL;
}
void SListInsest(SListNode** ppHead, SListNode* pos, DataType x)
{
	assert(ppHead != NULL&&pos != NULL);
	SListNode*prev = *ppHead;//记录pos位置的前一个节点
	SListNode*newNode = BuySListNode(x);
	if (prev == NULL || pos == prev)
	{
		SListPushFront(ppHead, x);
	}
	else
	{
		while (prev->_next != pos)
		{
			prev = prev->_next;
		}
		newNode->_next = pos;
		prev->_next = newNode;
	}
}
void SListErase(SListNode** ppHead, SListNode* pos)
{
	assert(ppHead != NULL&&pos != NULL);
	SListNode*cur = *ppHead;
	SListNode*prev = NULL;
	if (*ppHead == pos)
	{
		*ppHead = cur->_next;
		free(cur);
	}
	else
	{
		prev = *ppHead;
		while (prev->_next != pos)
		{
			prev = prev->_next;
		}
		prev->_next = pos->_next;
		free(pos);
	}
}
int main()
{
	SListNode* pHead=NULL;
	SListNode* pos = NULL;
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPrint(pHead);

	/*SListPopBack(&pHead);
	SListPrint(pHead);
	SListPushFront(&pHead, 10);
	SListPrint(pHead);
	pos = SListFind(pHead, 3);
	SListInsest(&pHead, pos, 20);
	SListPrint(pHead);
	pos = SListFind(pHead, 2);
	SListErase(&pHead, pos);
	SListPrint(pHead);
	SListDestory(&pHead);
	SListPrint(pHead);*/
	system("pause");
	return 0;
}
