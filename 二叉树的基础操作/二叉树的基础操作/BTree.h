#pragma once 

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
	BTDataType _data;
}BTNode;


BTNode* BuyBTNode(BTDataType x);//创建树的节点
// 创建二叉树 
BTNode* CreateBTree(BTDataType* a, size_t* pIndex, BTDataType invalid);
void BTreePrevOrder(BTNode* root);//先序遍历
void BTreeInOrder(BTNode* root);//中序遍历
void BTreePostOrder(BTNode* root);//后序遍历
size_t BTreeSize(BTNode* root);//树的节点个数
size_t BTreeLeafSize(BTNode* root);//叶节点个数
size_t BTreeKLevelSize(BTNode* root, size_t k);//第k层节点个数
size_t BTreeDepth(BTNode* root);//深度
BTNode* BTreeFind(BTNode* root, BTDataType x);//查找
void BTreeLevelOrder(BTNode* root);//层序遍历
void BTreePrevOrderNonR(BTNode* root);//先序遍历非递归
void BTreeInOrderNonR(BTNode* root);//中序遍历非递归
void BTreePostOrderNonR(BTNode* root);//后序遍历非递归


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
	size_t _top; //栈顶 
	size_t _end;
}Stack;

// 栈的实现接口 
void StackInit(Stack* s);
void StackPush(Stack* s, DataType x);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
size_t StackSize(Stack* s);
int StackEmpty(Stack* s);
