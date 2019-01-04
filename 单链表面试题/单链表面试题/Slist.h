
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

SListNode* BuySListNode(DataType x);//�����µĽڵ�
void SListPrint(SListNode* pHead);//��ӡ
void SListDestory(SListNode** ppHead);//����
void SListPushBack(SListNode** ppHead, DataType x);//β��
void SListPopBack(SListNode** ppHead);//βɾ
void SListPushFront(SListNode** ppHead, DataType x);//ͷ��
SListNode* SListFind(SListNode* pHead, DataType x);//Ѱ��x ���ص�ַ
void SListInsest(SListNode** ppHead, SListNode* pos, DataType x);//ָ������
void SListErase(SListNode** ppHead, SListNode* pos);//ָ��ɾ��


void SLitsPrintTailToHead(SListNode* pHead);//��β��ͷ��ӡ
void SListPrintTailToHeadR(SListNode* pHead);//��β��ͷ��ӡ �ݹ�

void SListDelNonTailNode(SListNode* pos);//ɾ��һ����ͷ������ķ�β�ڵ㣨���ܱ�������
void SListInsertFrontNode(SListNode* pos, DataType x);// ����ͷ�������һ���ڵ�ǰ����һ���ڵ㣨���ܱ�������
SListNode* SListJosephCircle(SListNode* pHead, int k);//������ʵ��Լɪ��(JosephCircle) 
SListNode* SListReverse(SListNode* list);//����/��ת������ 
void SListBubbleSort(SListNode* list);//����������ð������&�������� ���� ;
SListNode* SListMerge(SListNode* list1, SListNode* list2);//�ϲ�������������,�ϲ�����Ȼ���� 
SListNode* SListFindMidNode(SListNode* list);// ���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������
SListNode* SListFindTailKNode(SListNode* list, size_t k); //���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������
// ����������� 
SListNode* SListIsCycle(SListNode* list);//�жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿������ 
int SListCycleLen(SListNode* list, SListNode*passNode);//�����������
int SListEntryNode(SListNode* list, SListNode* meetNode);
// �����ཻ���� 
int SListIsCrossNode1(SListNode* list1, SListNode* list2);//�ж����������Ƿ��ཻ�����ཻ���󽻵㡣���������������� 
SListNode* SListCrossNode1(SListNode* list1, SListNode* list2);

void UnionSet(SListNode* list1, SListNode* list2);//��������������������ͬ�����ݡ� 


