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
	size_t _size; // 有效数据个数 
	size_t _capacity; // 容量 
}SeqList;

void SeqPrint(SeqList* pSeq);//打印
void SeqInit(SeqList* pSeq);//初始化
void SeqDestory(SeqList* pSeq);//销毁

void SeqPushBack(SeqList* pSeq, DataType x);//尾插入
void SeqPopBack(SeqList* pSeq);//尾删除
void SeqPushFront(SeqList* pSeq, DataType x);//头插入
void SeqPopFront(SeqList* pSeq);//头删除

void SeqInsert(SeqList* pSeq, size_t pos, DataType x);//指定删除
void SeqErase(SeqList* pSeq, size_t pos);//指定插入

int SeqFind(SeqList* pSeq, DataType x);//查找
void SeqAt(SeqList* pSeq, size_t pos, DataType x);//替换

void BubbleSort(SeqList* pSeq);//冒泡排序
void SelectSort(SeqList* pSeq);//选择排序
int BinarySearch(SeqList* pSeq, DataType x);//二分查找
void RemoveAll(SeqList* pSeq, DataType x);//删除所有指定
void test();//