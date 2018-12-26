#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

void SeqPrint(SeqList* pSeq)
{
	assert(pSeq);
	DataType i = 0;
	for (i = 0; i < (int)pSeq->_size; i++)
	{
		printf("%d ", pSeq->_a[i]);
	}
	printf("\n");

}
void SeqInit(SeqList* pSeq)
{
	assert(pSeq);
	pSeq->_capacity = 10;
	pSeq->_a = (DataType*)malloc(pSeq->_capacity*sizeof(DataType));
	if (pSeq->_a)
	{
		pSeq->_size = 0;
		//memset(pSeq->_a, 1, pSeq->_capacity*sizeof(DataType));
	}
}
void SeqDestory(SeqList* pSeq)
{
	free(pSeq->_a);
	pSeq->_a = NULL;//将指针指向NULL，否则指针让然存在指向开辟的空间，但没有使用权，为野指针
	pSeq->_capacity = 0;
	pSeq->_size = 0;
}
void SeqPushBack(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	if (pSeq->_size == pSeq->_capacity)
	{
		return;
	}
	pSeq->_a[pSeq->_size++] = x;
}
void SeqPopBack(SeqList* pSeq)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		return;
	}
	pSeq->_size--;
}
void SeqPushFront(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	if (pSeq->_size == pSeq->_capacity)
	{
		DataType* newpSeq = (DataType*)realloc(pSeq->_a, pSeq->_capacity * 2 * sizeof(DataType));
		if (newpSeq)
		{
			pSeq->_a = newpSeq;
			pSeq->_capacity = pSeq->_capacity * 2;
		}
	}
	int i = 0;
	for (i = (int)pSeq->_size; i >= 0; i--)
	{
		pSeq->_a[i] = pSeq->_a[i - 1];
	}
	pSeq->_a[0] = x;
	pSeq->_size++;
}
void SeqPopFront(SeqList* pSeq)
{
	assert(pSeq);
	int i = 0;
	if (pSeq->_size == 0)
	{
		return;
	}
	for (i = 0; i <(int)pSeq->_size - 1; i++)
	{
		pSeq->_a[i] = pSeq->_a[i + 1];
	}
	pSeq->_size--;
}
void SeqInsert(SeqList* pSeq, size_t pos, DataType x)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->_size == pSeq->_capacity)
	{
		DataType* newpSeq = (DataType*)realloc(pSeq->_a, pSeq->_capacity * 2 * sizeof(DataType));
		if (newpSeq)
		{
			pSeq->_a = newpSeq;
			pSeq->_capacity = pSeq->_capacity * 2;
		}
	}
	if (pos>pSeq->_size)
	{
		return;
	}
	//else if (pos==1)
	//{
	//	for (i = (int)pSeq->_size; i >= 0; i--)
	//	{
	//		pSeq->_a[i] = pSeq->_a[i - 1];
	//	}
	//	pSeq->_a[0] = x;
	//	pSeq->_size++;
	//}
	else
	{
		for (i = (int)(pSeq->_size); i >= (int)pos; i--)
		{
			pSeq->_a[i] = pSeq->_a[i - 1];
		}
		pSeq->_a[pos - 1] = x;
		pSeq->_size++;
	}
}
void SeqErase(SeqList* pSeq, size_t pos)
{
	assert(pSeq);
	int i = 0;
	if (pSeq->_size == 0)
	{
		return;
	}
	else if (pos > pSeq->_size)
	{
		return;
	}
	else
	{
		for (i = (int)pos-1; i <(int)pSeq->_size - 1; i++)
		{
			pSeq->_a[i] = pSeq->_a[i + 1];
		}
		pSeq->_size--;
	}
}
int SeqFind(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	int i = 0;
	if (pSeq->_size == 0)
	{
		return -1;
	}
	for (i = 0; i < (int)pSeq->_size; i++)
	{
		if (pSeq->_a[i] == x)
		{
			return i;
		}
	}
}
void SeqAt(SeqList* pSeq, size_t pos, DataType x)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		return;
	}
	if ((pos > pSeq->_size)||(pos<0))
	{
		return;
	}
	pSeq->_a[pos - 1] = x;
}
void BubbleSort(SeqList* pSeq)
{
	assert(pSeq);
	int i = 0;
	int j = 0;
	DataType temp = 0;
	if (pSeq->_size == 0)
	{
		return;
	}
	for (i = 0; i < (int)pSeq->_size - 1; i++)
	{
		for (j = 0; j < (int)pSeq->_size - 1 - i; j++)
		{
			if (pSeq->_a[j]>pSeq->_a[j + 1])
			{
				temp = pSeq->_a[j];
				pSeq->_a[j] = pSeq->_a[j + 1];
				pSeq->_a[j + 1] = temp;
			}
		}
	}
}
void SelectSort(SeqList* pSeq)
{
	assert(pSeq);
	size_t min = 0;
	size_t max = 0;
	size_t left = 0;
	size_t right = pSeq->_size - 1;
	while (left<right)
	{
		for (size_t i = left; i <= right; i++)
		{
			if (pSeq->_a[min]>pSeq->_a[i])
			{
				min = i;
			}
			if (pSeq->_a[max] < pSeq->_a[i])
			{
				max = i;
			}
		}
		DataType x = pSeq->_a[min];
		pSeq->_a[min] = pSeq->_a[left];
		pSeq->_a[left] = x;
		if (max == left)
		{
			max = min;
		}
		x = pSeq->_a[max];
		pSeq->_a[max] = pSeq->_a[right];
		pSeq->_a[right] = x;
		left++;
		right--;
	}
}
int BinarySearch(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	int mid = 0;
	int left = 0;
	int right = (int)pSeq->_size - 1;
	if (pSeq->_size == 0)
	{
		return -1;
	}
	BubbleSort(pSeq);
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (x > pSeq->_a[mid])
		{
			left = mid + 1;
		}
		else if (x < pSeq->_a[mid])
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;

}
void RemoveAll(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	int i = 0;
	int j = 0;
	for (i = 0; i < (int)pSeq->_size;)
	{
		if (pSeq->_a[i] == x)
		{
			for (j = i; j < (int)pSeq->_size; j++)
			{
				pSeq->_a[j] = pSeq->_a[j + 1];
			}
			pSeq->_size--;
		}
		else
			i++;
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}
void test()
{
	SeqList pSeq;
	SeqInit(&pSeq);
	SeqPushBack(&pSeq, 1);
	SeqPushBack(&pSeq, 2);
	SeqPushBack(&pSeq, 3);
	SeqPushBack(&pSeq, 4);
	SeqPushBack(&pSeq, 5);
	SeqPopBack(&pSeq);
	SeqPushFront(&pSeq, 10);
	SeqPopFront(&pSeq);
	SeqInsert(&pSeq, 1, 10);
	SeqErase(&pSeq, 3);
	SeqPrint(&pSeq);
	printf("%d\n", SeqFind(&pSeq, 10));
	SeqAt(&pSeq, 3, 4);
	
	SelectSort(&pSeq);
	BubbleSort(&pSeq);
	SeqPrint(&pSeq);
	printf("%d\n", BinarySearch(&pSeq, 10));
	RemoveAll(&pSeq, 4);
	SeqPrint(&pSeq);
	SeqDestory(&pSeq);
	SeqPrint(&pSeq);

}