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


DListNode* BuyDListNode(DataType x);//�����µĽڵ�
DListNode* DListInit();//��ʼ��
void DListDestory(DListNode* head);//��������
void DListPrint(DListNode* head);//��ӡ����

void DListPushBack(DListNode* head, DataType x);//β��
void DListPushFront(DListNode* head, DataType x);//ͷ��
void DListPopBack(DListNode* head);//βɾ
void DListPopFront(DListNode* head);//ͷɾ

DListNode* DListFind(DListNode* head, DataType x);//Ѱ��ָ���������ص�ַ
void DListInsert(DListNode* pos, DataType x);//ָ��λ��֮ǰ����
void DListErase(DListNode* pos);//ָ��λ��ɾ��
