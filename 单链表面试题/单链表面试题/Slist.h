
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


void SLitsPrintTailToHead(SListNode* pHead);//从尾到头打印
void SListPrintTailToHeadR(SListNode* pHead);//从尾到头打印 递归

void SListDelNonTailNode(SListNode* pos);//删除一个无头单链表的非尾节点（不能遍历链表）
void SListInsertFrontNode(SListNode* pos, DataType x);// 在无头单链表的一个节点前插入一个节点（不能遍历链表）
SListNode* SListJosephCircle(SListNode* pHead, int k);//单链表实现约瑟夫环(JosephCircle) 
SListNode* SListReverse(SListNode* list);//逆置/反转单链表 
void SListBubbleSort(SListNode* list);//单链表排序（冒泡排序&快速排序） 升序 ;
SListNode* SListMerge(SListNode* list1, SListNode* list2);//合并两个有序链表,合并后依然有序 
SListNode* SListFindMidNode(SListNode* list);// 查找单链表的中间节点，要求只能遍历一次链表
SListNode* SListFindTailKNode(SListNode* list, size_t k); //查找单链表的倒数第k个节点，要求只能遍历一次链表
// 链表带环问题 
SListNode* SListIsCycle(SListNode* list);//判断单链表是否带环？若带环，求环的长度？求环的入口点？并计算 
int SListCycleLen(SListNode* list, SListNode*passNode);//求带环链表长度
int SListEntryNode(SListNode* list, SListNode* meetNode);
// 链表相交问题 
int SListIsCrossNode1(SListNode* list1, SListNode* list2);//判断两个链表是否相交，若相交，求交点。（假设链表不带环） 
SListNode* SListCrossNode1(SListNode* list1, SListNode* list2);

void UnionSet(SListNode* list1, SListNode* list2);//求两个已排序单链表中相同的数据。 


