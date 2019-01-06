#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<malloc.h>
#include"BTree.h"
BTNode* BuyBTNode(BTDataType x)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	if (newNode == NULL)
		return NULL;
	newNode->_data = x;
	newNode->_left = NULL;
	newNode->_right = NULL;
	return newNode;
}
BTNode* CreateBTree(BTDataType* a, size_t* pIndex, BTDataType invalid)
{
	assert(a);
	if (a[*pIndex]!=invalid)
	{
		BTNode* root = BuyBTNode(a[*pIndex]);
		(*pIndex)++;
		root->_left = CreateBTree(a, pIndex, invalid);
		(*pIndex)++;
		root->_right = CreateBTree(a, pIndex, invalid);
		return root;
	}
	return NULL;
}
void BTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	else
	{
		printf("%d ", root->_data);
		BTreePrevOrder(root->_left);
		BTreePrevOrder(root->_right);
	}
}
void BTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	else
	{
		BTreeInOrder(root->_left);
		printf("%d ", root->_data);
		BTreeInOrder(root->_right);
	}
}
void BTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	else
	{
		BTreePostOrder(root->_left);
		BTreePostOrder(root->_right);
		printf("%d ", root->_data);
	}
}
void BTreePrevOrderNonR(BTNode* root)
{
	Stack s;
	StackInit(&s);
	BTNode* Top;
	BTNode* cur = root;
	while (cur || !StackEmpty(&s))
	{
		while (cur)
		{
			printf("%d ", cur->_data);
			StackPush(&s, cur);
			cur = cur->_left;
		}
		Top = StackTop(&s);
		StackPop(&s);
		cur = Top->_right;
	}
	printf("\n");
}
void BTreeInOrderNonR(BTNode* root)
{
	Stack s;
	StackInit(&s);
	BTNode* Top;
	BTNode* cur = root;
	while (cur || !StackEmpty(&s))
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		Top = StackTop(&s);
		printf("%d ", Top->_data);
		StackPop(&s);
		cur = Top->_right;
	}
	printf("\n");
}
void BTreePostOrderNonR(BTNode* root)
{
	Stack s;
	StackInit(&s);
	BTNode* Top;
	BTNode* last = NULL;
	BTNode* cur = root;
	while (cur || !StackEmpty(&s))
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur=cur->_left;
		}
		Top = StackTop(&s);
		if (Top->_right == NULL || Top->_right == last)
		{
			printf("%d ", Top->_data);
			last = Top;
			StackPop(&s);
		}
		else
		{
			cur = Top->_right;
		}
	}
	printf("\n");
}
size_t BTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return BTreeSize(root->_left) + BTreeSize(root->_right) + 1;
	}
}
size_t BTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL&&root->_right == NULL)
	{
		return 1;
	}
	return BTreeSize(root->_left) + BTreeSize(root->_right);
}
size_t BTreeKLevelSize(BTNode* root, size_t k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	else
	{
		k--;
		return BTreeKLevelSize(root->_left, k) + BTreeKLevelSize(root->_right, k);
	}
}
size_t BTreeDepth(BTNode* root)
{
	int left;
	int right;
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL&&root->_right == NULL)
	{
		return 1;
	}
	else
	{
		left = BTreeDepth(root->_left) + 1;
		right = BTreeDepth(root->_right) + 1;
		return left > right ? left : right;
	}
}
BTNode* BTreeFind(BTNode* root, BTDataType x)
{
	BTNode* res = NULL;
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	if (root->_left != NULL)
	{
		res = BTreeFind(root->_left, x);
		if (res->_data == x)
			return res;
	}
	if (root->_right != NULL)
	{
		res = BTreeFind(root->_right, x);
		if (res->_data == x)
			return res;
	}
}
void BTreeLevelOrder(BTNode* root)
{
	Queue*q=QueueInit();
	QueuePush(q, root);
	while (q->_size)
	{
		BTNode* Front = QueueFront(q);
		printf("%d ", Front->_data);
		QueuePop(q);
		if (Front->_left)
			QueuePush(q, Front->_left);
		if (Front->_right)
			QueuePush(q, Front->_right);
	}
}

//void BTreeLevelOrder(BTNode* root)
//{
//	BTNode* node;
//	Queue* q = QueueInit();
//	QueuePush(q, root->_data);
//	QueueNode *cur = q->_head;
//	
//	while (cur!=NULL)
//	{
//	
//		node = BTreeFind(root, cur->_data);
//		if (node->_left)
//		{
//			QueuePush(q, node->_left->_data);
//		}
//		if (node->_right)
//		{
//			QueuePush(q, node->_right->_data);
//		}
//		cur = cur->_next;
//	}
//	Queueprint(q);
//}
// 队列
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
//栈
void StackInit(Stack* s)
{
	s->_array = (DataType*)malloc(10 * sizeof(DataType));
	if (s->_array)
	{
		s->_end = 0;
		s->_top = 0;
	}
}
void StackPush(Stack* s, DataType x)
{
	assert(s);
	s->_array[s->_top] = x;
	s->_top++;
}
void StackPop(Stack* s)
{
	s->_top--;
}
DataType StackTop(Stack* s)
{
	assert(s);
	return s->_array[s->_top - 1];
}
size_t StackSize(Stack* s)
{
	assert(s);
	return (s->_top) - (s->_end);
}
int StackEmpty(Stack* s)
{
	if (s->_top - s->_end == 0)
	{
		return 1;
	}
	else
		return 0;
}
void TestBinaryTree()
{
	int a[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6, '#', '#', '#' };
	size_t index = 0;

	BTNode* tree = CreateBTree(a, &index, '#');
	BTNode* pos;
	BTreePrevOrder(tree);
	printf("\n");
	BTreePrevOrderNonR(tree);
	BTreeInOrder(tree);
	printf("\n");
	BTreeInOrderNonR(tree);
	BTreePostOrder(tree);
	printf("\n");
	BTreePostOrderNonR(tree);
	printf("BTreeSize: %d\n", BTreeSize(tree));
	printf("BTreeLeafSize: %d\n", BTreeLeafSize(tree));
	printf("BTreeKLevelSize: %d\n", BTreeKLevelSize(tree, 3));
	printf("BTreeDepth: %d\n", BTreeDepth(tree));
	BTreeLevelOrder(tree);
	printf("\n");
	pos = BTreeFind(tree, 5);
	printf("%d\n", pos->_data);
	pos = BTreeFind(tree, 4);
	printf("%d\n", pos->_data);
	pos = BTreeFind(tree, 3);
	printf("%d\n", pos->_data);
	pos = BTreeFind(tree, 2);
	printf("%d\n", pos->_data);
}
int main()
{
	TestBinaryTree();
	system("pause");
	return 0;
}
