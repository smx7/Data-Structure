#pragma once 

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
	BTDataType _data;
}BTNode;


BTNode* BuyBTNode(BTDataType x);//�������Ľڵ�
// ���������� 
BTNode* CreateBTree(BTDataType* a, size_t* pIndex, BTDataType invalid);
void BTreePrevOrder(BTNode* root);//�������
void BTreeInOrder(BTNode* root);//�������
void BTreePostOrder(BTNode* root);//�������
size_t BTreeSize(BTNode* root);//���Ľڵ����
size_t BTreeLeafSize(BTNode* root);//Ҷ�ڵ����
size_t BTreeKLevelSize(BTNode* root, size_t k);//��k��ڵ����
size_t BTreeDepth(BTNode* root);//���
BTNode* BTreeFind(BTNode* root, BTDataType x);//����
void BTreeLevelOrder(BTNode* root);//�������
void BTreePrevOrderNonR(BTNode* root);//��������ǵݹ�
void BTreeInOrderNonR(BTNode* root);//��������ǵݹ�
void BTreePostOrderNonR(BTNode* root);//��������ǵݹ�


typedef BTNode* DataType;

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
size_t QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void Queueprint(Queue* q);

typedef struct Stack
{
	DataType* _array;
	size_t _top; //ջ�� 
	size_t _end;
}Stack;

// ջ��ʵ�ֽӿ� 
void StackInit(Stack* s);
void StackPush(Stack* s, DataType x);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
size_t StackSize(Stack* s);
int StackEmpty(Stack* s);
