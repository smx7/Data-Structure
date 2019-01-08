#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"
void HeapInit(Heap* hp, HeapDateType* a, size_t n)
{
	int i = 0;
	hp->_capacity = 15;
	hp->_size = 0;
	hp->_a = (HeapDateType*)malloc(sizeof(HeapDateType)*hp->_capacity);
	if (hp->_a == NULL)
		return;
	for (i = 0; i < (int)n; i++)
	{
		hp->_a[i] = a[i];
		hp->_size++;
	}
}
void HeapPrint(Heap* hp)
{
	int i = 0;
	for (i = 0; i < (int)hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
void HeapMake(Heap* hp)
{
	int i;
	for (i = (hp->_size - 2) / 2; i >= 0; i--)
	{
		HeapAdjustDown(hp,i);
	}
}
void HeapAdjustDown(Heap* hp, int root)
{
	int parent = root;
	int child;
	child = 2 * parent + 1;
	while (child<(int)hp->_size)
	{
		if (child + 1 <(int) hp->_size&&hp->_a[child + 1] > hp->_a[child])
		{
			child++;
		}
		if (hp->_a[child] > hp->_a[parent])
		{
			HeapDateType tmp = hp->_a[child];
			hp->_a[child] = hp->_a[parent];
			hp->_a[parent] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapPush(Heap* hp, HeapDateType x)
{
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = (HeapDateType*)realloc(hp->_a, sizeof(HeapDateType)*hp->_capacity);
		assert(hp->_a);
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	int child = (int)hp->_size - 1;
	HeapAdjustUp(hp, child);
}
void HeapAdjustUp(Heap* hp, int child)
{
	int parent = (child - 1) / 2;
	while (parent >= 0)
	{
		if (hp->_a[child] > hp->_a[parent])
		{
			HeapDateType tmp = hp->_a[child];
			hp->_a[child] = hp->_a[parent];
			hp->_a[parent] = tmp;
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}
void HeapPop(Heap* hp)
{
	HeapDateType tmp = hp->_a[0];
	hp->_a[0] = hp->_a[hp->_size - 1];
	hp->_a[hp->_size - 1] = tmp;
	hp->_size--;
	HeapAdjustDown(hp, 0);
}
size_t HeapEmpty(Heap* hp)
{
	if (hp->_size == 0)
		return 1;
	else
		return 0;
}
size_t Heapsize(Heap* hp)
{
	return hp->_size;
}
HeapDateType HeapTop(Heap* hp)
{
	return hp->_a[hp->_size];
}
void HeapSort(Heap* hp)
{
	size_t n = hp->_size;
	while (Heapsize(hp) > 1)
	{
		HeapDateType tmp = hp->_a[0];
		hp->_a[0] = hp->_a[hp->_size - 1];
		hp->_a[hp->_size - 1] = tmp;
		hp->_size--;
		HeapAdjustDown(hp, 0);
	}
	hp->_size = n;
	HeapPrint(hp);
}
int main()
{
	Heap hp;
	HeapDateType a[]= { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	size_t n = sizeof(a) / sizeof(a[0]);

	HeapInit(&hp, a, n);
	HeapPrint(&hp);
	HeapMake(&hp);
	HeapPrint(&hp);
	HeapPush(&hp, 100);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapSort(&hp);
	system("pause");
	return 0;
}