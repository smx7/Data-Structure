#define _CRT_SECURE_NO_WARNINGS 1
#include"Complex.h"
ComplexListNode* BuyComplexNode(int x)
{
	ComplexListNode* newNode = (ComplexListNode*)malloc(sizeof(ComplexListNode));
	if (newNode == NULL)
	{
		printf("创建失败\n");
		return NULL;
	}
	newNode->_data = x;
	newNode->_next = NULL;
	newNode->_random = NULL;
	return newNode;
}
void printfComplexList(ComplexListNode* list)
{
	ComplexListNode* cur = list;
	while (cur )
	{
		if (cur->_random==NULL)
		{
			printf("%d:NULL->", cur->_data);
		}
		else
		{
			printf("%d:%d->", cur->_data, cur->_random->_data);
		}
		cur = cur->_next;
	}
	printf("NULL\n");
}
ComplexListNode* CopyComplexList(ComplexListNode* list)
{
	assert(list);
	ComplexListNode* oldList = list;
	ComplexListNode* newList = NULL;
	ComplexListNode* copyList = NULL;
	while (oldList)//创建一个新的链表并将新链表的每一个节点复制到原链表相应节点的后面
	{
		newList = BuyComplexNode(oldList->_data);
		newList->_next = oldList->_next;
		oldList->_next = newList;
		oldList = newList->_next;
	}

	oldList = list;
	newList = oldList->_next;
	while (oldList)                        //复制_random
	{
		if (oldList->_random == NULL)
		{
			newList->_random = NULL;
		}
		else
		{
			newList->_random = oldList->_random->_next;
		}
		oldList = newList->_next;
		if (oldList == NULL)
		{
			break;
		}
		newList = oldList->_next;
	}

	oldList = list;
	copyList = oldList->_next;
	while (oldList)
	{
		newList = oldList->_next;
		if (newList->_next == NULL)
		{
			break;
		}
		oldList->_next = newList->_next;
		newList->_next = oldList->_next->_next;
		oldList = oldList->_next;
	}
	return copyList;
}
int main()
{
	ComplexListNode* copy;

	ComplexListNode* pos1 = BuyComplexNode(1);
	ComplexListNode* pos2 = BuyComplexNode(2);
	ComplexListNode* pos3 = BuyComplexNode(3);
	ComplexListNode* pos4 = BuyComplexNode(4);
	ComplexListNode* pos5 = BuyComplexNode(5);
	pos1->_next = pos2;
	pos2->_next = pos3;
	pos3->_next = pos4;
	pos4->_next = pos5;
	pos5->_next = NULL;

	pos1->_random = pos3;
	pos2->_random = pos1;
	pos3->_random = NULL;
	pos4->_random = pos4;
	pos5->_random = pos2;


	printfComplexList(pos1);
	copy = CopyComplexList(pos1);
	printfComplexList(copy);
	system("pause");
	return 0;
}
