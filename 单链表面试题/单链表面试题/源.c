#define _CRT_SECURE_NO_WARNINGS 1
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
	SListNode*tmp;
	if (*ppHead == NULL)
	{
		return;
	}
	while (*ppHead)
	{
		tmp = (*ppHead)->_next;
		free(*ppHead);
		*ppHead = NULL;
	}
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
		while (cur->_next != NULL)
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
//void test1()
//{
//	SListNode* pHead = NULL;
//	SListNode* pos = NULL;
//	SListPopBack(&pHead);
//	SListPrint(pHead);
//	SListPushFront(&pHead, 10);
//	SListPrint(pHead);
//	pos = SListFind(pHead, 3);
//	SListInsest(&pHead, pos, 20);
//	SListPrint(pHead);
//	pos = SListFind(pHead, 2);
//	SListErase(&pHead, pos);
//	SListPrint(pHead);
//	//SListDestory(&pHead);
//	//SListPrint(pHead);
//}
void SLitsPrintTailToHead(SListNode* pHead)
{
	assert(pHead);
	SListNode* tail1=pHead;
	SListNode* tail2 = NULL;
	while (tail2 != pHead)
	{
		while (tail1->_next != tail2)
		{
			tail1 = tail1->_next;
		}
		printf("%d->", tail1->_data);
		tail2 = tail1;
		tail1 = pHead;
	}
	printf("\n");
}
void SLitsPrintTailToHeadR(SListNode* pHead)
{
	assert(pHead);
	if (pHead->_next != NULL)
	{

		SLitsPrintTailToHeadR(pHead->_next);
	}
	printf("%d->", pHead->_data);
}
void SListDelNonTailNode(SListNode* pos)
{
	assert(pos);
	SListNode* next = pos->_next;
	pos->_data = next->_data;
	pos->_next = next->_next;
	free(next);
}
void SListInsertFrontNode(SListNode* pos, DataType x)
{
	assert(pos);
	SListNode* newNode = BuySListNode(x);
	SListNode* next = pos->_next;
	newNode->_data=pos->_data;
	pos->_data = x;
	newNode->_next = next;
	pos->_next = newNode;
}
SListNode* SListJosephCircle(SListNode* pHead, int k)
{
	assert(pHead);
	SListNode* tail = pHead;
	SListNode* cur = pHead;
	SListNode* prev = NULL;

	int n = k;
	while (tail->_next)
	{
		tail = tail->_next;
	}
	tail->_next = pHead;
	while (pHead->_next!=pHead)
	{
		n = k;
		while (--n)
		{
			prev = cur;
			cur = cur->_next;
		}
		pHead = cur->_next;
		prev->_next = pHead;
		free(cur);
		cur = pHead;
	}
	return pHead;
}
SListNode* SListReverse(SListNode* list)
{
	SListNode* newHead = list;
	SListNode* cur1;
	SListNode* cur2;
	assert(list);
	cur1 = list->_next;
	newHead->_next = NULL;
	while (cur1)
	{
		cur2 = cur1;
		cur1 = cur1->_next;
		cur2->_next = newHead;
		newHead = cur2;
	}
	list = newHead;
	return list;
}
void SListBubbleSort(SListNode* list)
{
	assert(list);
	SListNode* cur = list;
	SListNode* next = list->_next;
	int i = 0;
	int count = 1;
	int j = 0;
	while (cur->_next)
	{
		cur = cur->_next;
		count++;
	}
	cur = list;
	for (i = 0; i < count - 1; i++)
	{
		cur = list;
		next = list->_next;
		for (j = 0; j < count - 1 - i; j++)
		{

			if (cur->_data>next->_data)
			{
				int tmp = next->_data;
				next->_data = cur->_data;
				cur->_data = tmp;
			}
			cur = cur->_next;
			next = next->_next;
		}
	}
}
SListNode* SListMerge(SListNode* list1, SListNode* list2)
{
	assert(list1);
	assert(list2);
	SListNode* cur1 = list1;
	SListNode* cur2 = list2;
	SListNode* newHead = NULL;
	SListNode* cur3 = NULL;
	if (cur1->_data > cur2->_data)
	{
		newHead = cur2;
		cur2 = cur2->_next;
	}
	else
	{
		newHead = cur1;
		cur1 = cur1->_next;
	}
	cur3 = newHead;
	while (cur1&&cur2)
	{
		if (cur1->_data < cur2->_data)
		{
			cur3->_next = cur1;
			cur1 = cur1->_next;
			cur3 = cur3->_next;
		}
		else
		{
			cur3->_next = cur2;
			cur2 = cur2->_next;
			cur3 = cur3->_next;
		}
	}
	if (cur1 != NULL)
	{
		cur3->_next = cur1;
	}
	else
	{
		cur3->_next = cur2;
	}
	return newHead;

}
SListNode* SListFindMidNode(SListNode* list)
{
	assert(list);
	SListNode* fast = list;
	SListNode* slow = list;
	while (fast->_next != NULL)
	{
		slow = slow->_next;
		fast = fast->_next;
		fast = fast->_next;
	}
	return slow;
}
SListNode* SListFindTailKNode(SListNode* list, size_t k)
{
	assert(list);
	SListNode* slow = list;
	SListNode* fast = list;
	while (--k)
	{
		fast = fast->_next;
	}
	while (fast->_next != NULL)
	{
		slow = slow->_next;
		fast = fast->_next;
	}
	return slow;
}
SListNode* SListIsCycle(SListNode* list)  //判断单链表是否带环？若带环，求环的长度？求环的入口点？
{
	assert(list);
	SListNode* fast = list;
	SListNode* slow = list;
	SListNode* cur1 = list;
	SListNode* cur2;
	SListNode* next;
	int count = 1;
	while (fast->_next!=NULL)
	{
		slow = slow->_next;
		fast = fast->_next;
		fast = fast->_next;
		if (slow == fast)
		{
			cur2 = fast;
			next = cur2->_next;
			while (next != cur2)
			{
				next = next->_next;
				count++;
			}
			printf("环的长度为%d\n", count);
			break;
		}
	}
	if (fast->_next == NULL)
	{
		return NULL;
	}
	while (cur1 != fast)
	{
		cur1 = cur1->_next;
		fast = fast->_next;
	}
	return cur1;
}
int SListCycleLen(SListNode* list, SListNode*passNode)//求带环链表长度
{
	assert(list);
	SListNode* cur1 = list;
	SListNode* cur2 = passNode;
	int n = 0;
	int len = 0;
	while (cur1->_next != NULL)
	{
		if (cur1 == cur2)
		{
			n++;
		}
		if (n == 2)
		{
			break;
		}
		len++;
		cur1 = cur1->_next;
	}
	if (cur1->_next == NULL)
	{
		return -1;
	}
	return len;
}
int SListIsCrossNode1(SListNode* list1, SListNode* list2)// 判断两链表是否相交(链表不带环)
{
	assert(list1);
	assert(list2);
	SListNode* tail1 = list1;
	SListNode* tail2 = list2;
	while (tail1->_next)
	{
		tail1 = tail1->_next;
	}
	while (tail2->_next)
	{
		tail2 = tail2->_next;
	}
	if (tail1 == tail2)
	{
		return 1;
	}
	return 0;
}
SListNode* SListCrossNode1(SListNode* list1, SListNode* list2)//求两链表的交点（链表不带环）
{
	assert(list1);
	assert(list2);
	SListNode* cur1 = list1;
	SListNode* cur2 = list2;
	SListNode* cur3;
	int steps = 0;
	int len1 = 0;
	int len2 = 0;
	int result = SListIsCrossNode1(list1, list2);
	if (result == 0 || list1 == NULL || list2 == NULL)
	{
		return NULL;
	}
	while (cur1)
	{
		len1++;
		cur1 = cur1->_next;
	}
	while (cur2)
	{
		len2++;
		cur2 = cur2->_next;
	}
	if (len1 > len2)
	{
		steps = len1 - len2;
		cur3 = list1;
	}
	else
	{
		steps = len2 - len1;
		cur3 = list2;
	}
	while (steps--)
	{
		cur3 = cur3->_next;
	}
	if (len1 > len2)
	{
		list1 = cur3;
	}
	else
	{
		list2 = cur3;
	}
	while (list1 != list2)
	{
		list1 = list1->_next;
		list2 = list2->_next;
	}
	return list1;
}
int SListIsCrossNode2(SListNode* list1, SListNode* list2)
{
	assert(list1);
	assert(list2);
	SListNode* slow = list1;
	SListNode* fast = list2;
	while (fast && slow && fast != slow)
	{
		slow = slow->_next;
		if (fast->_next)
		{
			fast = fast->_next->_next;
		}
		else
		{
			fast = fast->_next;
		}
	}
	if (fast && slow && fast == slow)
		return 1;
	else
		return 0;
}
SListNode* SListCrossNode2(SListNode* list1, SListNode* list2)
{
	assert(list1);
	assert(list2);
	SListNode* head1 = list1;
	SListNode* head2 = list2;
	SListNode* slow1 = list1;
	SListNode* fast1 = slow1;
	SListNode* slow2 = list2;
	SListNode* fast2 = slow2;
	SListNode* meet1 = NULL;
	SListNode* meet2 = NULL;

	SListNode* cur1 = SListIsCycle(list1);
	SListNode* cur2 = SListIsCycle(list2);
	int len1 = SListCycleLen(list1, cur1);
	int len2 = SListCycleLen(list2, cur2);
	int steps = 0;
	if (len1 > len2)
	{
		steps = len1 - len2;
	}
	else
	{
		steps = len2 - len1;
	}
	int result = SListIsCrossNode2(list1, list2);
	if (result == 1)
	{
		if (cur1 == cur2)//交点在环外的情况
		{
			if (len1 > len2)
			{
				while (steps--)
				{
					head1 = head2->_next;
				}
			}
			else
			{
				while (steps--)
				{
					head2 = head2->_next;
				}
			}
			while (head1 != head2)
			{
				head1 = head1->_next;
				head2 = head2->_next;
			}
			return head1;
		}
		else//交点在环内的情况
		{
			slow1 = slow1->_next;
			fast1 = fast1->_next;
			fast1 = fast1->_next;
			while (slow1 != fast1)
			{
				slow1 = slow1->_next;
				fast1 = fast1->_next;
				fast1 = fast1->_next;
			}
			meet1 = fast1;
			slow2 = slow2->_next;
			fast2 = fast2->_next;
			fast2 = fast2->_next;
			while (slow2 != fast2)
			{
				slow2 = slow2->_next;
				fast2 = fast2->_next;
				fast2 = fast2->_next;
			}
			meet2 = fast2;
			while (head1 != meet1)
			{
				head1 = head1->_next;
				meet1 = meet1->_next;
			}
			return head1;
			//while (head2 != meet1)
			//{
			//	head2 = head2->_next;
			//	meet2 = meet2->_next;
			//}
			//return head2;
		}
	}
	
}
void UnionSet(SListNode* list1, SListNode* list2)
{
	assert(list1);
	assert(list2);
	SListNode* cur1 = list1;
	SListNode* cur2 = list2;
	while (cur2)
	{
		while (cur1)
		{
			if (cur2->_data == cur1->_data)
			{
				printf("%d ", cur1->_data);
			}
			cur1 = cur1->_next;
		}
		cur2 = cur2->_next;
		cur1 = list1;
	}
}
int main()
{
	SListNode* pHead = NULL;
	SListNode* pHead1 = NULL;
	SListNode* pos1 = NULL;
	SListNode* pos2 = NULL;
	SListNode* pos3 = NULL;
	SListNode* pos4 = NULL;
	SListNode* pos5 = NULL;
	SListNode* passNode = NULL;
	int len = 0;

	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 8);

	//pos1 = SListFind(pHead, 8);
	//pos2 = SListFind(pHead, 3);
	//pos1->_next = pos2;
	//passNode = SListIsCycle(pHead);
	//len = SListCycleLen(pHead,passNode);
	//printf("%d\n", len);

	SListPushBack(&pHead1, 0);
	SListPushBack(&pHead1, 2);
	SListPushBack(&pHead1, 4);  
	SListPushBack(&pHead1, 6);

	UnionSet(pHead, pHead1);
	//pos3 = SListFind(pHead1, 2);
	//pos4 = SListFind(pHead, 6);
	//pos3->_next = pos4;
	//pos5 = SListCrossNode2(pHead, pHead1);
	//if (pos2 == pos5)
	//{
	//	printf("测试通过！\n");
	//}

	//SListPrint(pHead);
	//SListPrint(pHead1);
	//pos1 = SListFind(pHead1, 4);
	//pos2 = SListFind(pHead1, 6);
	//pos3 = SListFind(pHead, 6);//构造相交
	//pos2 = pos3;
	//pos1->_next = pos2;

	//pos4 = SListCrossNode2(pHead, pHead1);
	//SListPrint(pos4);
	system("pause");
	return 0;
}

