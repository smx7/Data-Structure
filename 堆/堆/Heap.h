#include<stdio.h>
#include<windows.h>
#include<malloc.h>
#include<assert.h>
typedef int HeapDateType;

typedef struct Heap
{
	HeapDateType* _a;
	size_t _size;
	size_t _capacity;
}Heap;

void HeapInit(Heap* hp, HeapDateType* a, size_t n);//��ʼ��
void HeapMake(Heap* hp);//������
void HeapPush(Heap* hp, HeapDateType x);//�ѵĲ���
void HeapPop(Heap* hp);//�ѵ�ɾ��
size_t HeapEmpty(Heap* hp);
size_t Heapsize(Heap* hp);
HeapDateType HeapTop(Heap* hp);
void HeapSort(Heap* hp);//������
void HeapAdjustDown(Heap* hp, int root);
void HeapAdjustUp(Heap* hp, int child);