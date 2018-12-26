#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<assert.h>
#include<string.h>

typedef int DataType;

typedef struct SeqList
{
	DataType* _a;
	size_t _size; // ��Ч���ݸ��� 
	size_t _capacity; // ���� 
}SeqList;

void SeqPrint(SeqList* pSeq);//��ӡ
void SeqInit(SeqList* pSeq);//��ʼ��
void SeqDestory(SeqList* pSeq);//����

void SeqPushBack(SeqList* pSeq, DataType x);//β����
void SeqPopBack(SeqList* pSeq);//βɾ��
void SeqPushFront(SeqList* pSeq, DataType x);//ͷ����
void SeqPopFront(SeqList* pSeq);//ͷɾ��

void SeqInsert(SeqList* pSeq, size_t pos, DataType x);//ָ��ɾ��
void SeqErase(SeqList* pSeq, size_t pos);//ָ������

int SeqFind(SeqList* pSeq, DataType x);//����
void SeqAt(SeqList* pSeq, size_t pos, DataType x);//�滻

void BubbleSort(SeqList* pSeq);//ð������
void SelectSort(SeqList* pSeq);//ѡ������
int BinarySearch(SeqList* pSeq, DataType x);//���ֲ���
void RemoveAll(SeqList* pSeq, DataType x);//ɾ������ָ��
void test();//