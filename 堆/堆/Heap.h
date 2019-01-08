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

void HeapInit(Heap* hp, HeapDateType* a, size_t n);//初始化
void HeapMake(Heap* hp);//创建堆
void HeapPush(Heap* hp, HeapDateType x);//堆的插入
void HeapPop(Heap* hp);//堆的删除
size_t HeapEmpty(Heap* hp);
size_t Heapsize(Heap* hp);
HeapDateType HeapTop(Heap* hp);
void HeapSort(Heap* hp);//堆排序
void HeapAdjustDown(Heap* hp, int root);
void HeapAdjustUp(Heap* hp, int child);