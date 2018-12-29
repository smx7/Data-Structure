#include<stdio.h>
#include<windows.h>
#include<assert.h>

typedef int DataType;

typedef struct DListNode
{
	struct DListNode* _next;
	struct DListNode* _prev;
	DataType _data;
}DListNode;


DListNode* BuyDListNode(DataType x);//创建新的节点
DListNode* DListInit();//初始化
void DListDestory(DListNode* head);//销毁链表
void DListPrint(DListNode* head);//打印链表

void DListPushBack(DListNode* head, DataType x);//尾插
void DListPushFront(DListNode* head, DataType x);//头插
void DListPopBack(DListNode* head);//尾删
void DListPopFront(DListNode* head);//头删

DListNode* DListFind(DListNode* head, DataType x);//寻找指定数，返回地址
void DListInsert(DListNode* pos, DataType x);//指定位置之前插入
void DListErase(DListNode* pos);//指定位置删除
