
#include<stdio.h>
#include<assert.h>
#include<windows.h>
#include<stdlib.h>

typedef int DataType;

typedef struct SListNode
{
	struct SListNode* _next;
	DataType _data;
}SListNode;


SListNode* BuySListNode(DataType x);//创建新的节点
void SListPrint(SListNode* pHead);//打印
void SListDestory(SListNode** ppHead);//销毁

void SListPushBack(SListNode** ppHead, DataType x);//尾插
void SListPopBack(SListNode** ppHead);//尾删
void SListPushFront(SListNode** ppHead, DataType x);//头插
SListNode* SListFind(SListNode* pHead, DataType x);//寻找x 返回地址
void SListInsest(SListNode** ppHead, SListNode* pos, DataType x);//指定插入
void SListErase(SListNode** ppHead, SListNode* pos);//指定删除
