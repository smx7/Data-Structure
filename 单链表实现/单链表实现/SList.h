
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
