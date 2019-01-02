#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
void StackInit(Stack* s)
{
	s->_array = (DataType*)malloc(10 * sizeof(DataType));
	if (s->_array)
	{
		s->_end = 0;
		s->_top = 0;
	}
}
void StackPush(Stack* s, DataType x)
{
	assert(s);
	s->_array[s->_top] = x;
	s->_top++;
}
void StackPop(Stack* s)
{
	s->_top--;
}
size_t StackSize(Stack* s)
{
	assert(s);
	return (s->_top) - (s->_end);
}
int StackEmpty(Stack* s)
{
	if (s->_top - s->_end == 0)
	{
		return 1;
	}
	else
		return 0;
}
DataType StackTop(Stack* s)
{
	return s->_array[s->_top - 1];
}
void Stackprint(Stack*s)
{
	assert(s);
	int i = 0;
	size_t size = s->_top - s->_end;
	if (size == 0)
	{
		printf("Õ»Îª¿Õ");
	}
	for (i = 0; i < (int)size; i++)
	{
		printf("%d ", s->_array[i]);
	}
	printf("\n");
}
//int IsRightOrder(int arr1[], int arr2[], Stack*s, int sz)
//{
//	int *p = arr1;
//	int *q = arr2;
//	int i = 0;
//	//for (i = 0; i < sz; i++)
//	//{
//	//	if (*p == *q)
//	//	{
//	//		p++;
//	//		q++;
//	//	}
//	//	else
//	//	{
//	//		if (StackEmpty(s) == 1)
//	//		{
//	//			StackPush(s, *p);
//	//			p++;
//	//		}
//	//		else
//	//		{
//	//			while (*q != *p)
//	//			{
//	//				if (*q == s->_array[s->_top - 1])
//	//				{
//	//					StackPop(s);
//	//					q++;
//	//				}
//	//				else
//	//				{
//	//					StackPush(s, *p);
//	//					p++;
//	//				}
//
//	//			}
//	//		}
//	//	}
//	//}
//	for (i = 0; i < sz; i++)
//	{
//		if (*p == *q)
//		{
//			p++;
//			q++;
//		}
//		else
//		{
//			if (StackEmpty(s) == 1)
//			{
//				StackPush(s, *p);
//				p++;
//			}
//			else
//			{
//				while (*q != *p)
//				{
//					if (*q == s->_array[s->_top - 1])
//					{
//						StackPop(s);
//						q++;
//					}
//					else
//						break;
//				}
//				StackPush(s, *p);
//				p++;
//			}
//		}
//	}
//	while (StackEmpty(s) != 1)
//	{
//		if (*q != s->_array[s->_top - 1])
//		{
//			return 0;
//		}
//		q++;
//		StackPop(s);
//	}
//	return 1;
//}
int IsRightOrder(int arr1[], int arr2[], Stack*s, int sz)
{
	int *p = arr1;
	int *q = arr2;
	for (int i = 0; i < sz; i++)
	{
		if (*p == *q)
		{
			p++;
			q++;
		}
		else
		{
			if (StackEmpty(s) == 1)
			{
				StackPush(s, *p);
				p++;
			}
			else
			{
				while (*p != *q)
				{
					if (*q == StackTop(s))
					{
						StackPop(s);
						q++;
					}
					else
						break;
				}
				StackPush(s, *p);
				p++;
			}
		}
	}
	while (StackEmpty(s) != 1)
	{
		if (*q != StackTop(s))
		{
			return 0;
		}
		StackPop(s);
		q++;
	}
	return 1;
}
int main()
{
	Stack s;
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 4, 5, 3, 2, 1 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	int ret;
	StackInit(&s);
	ret = IsRightOrder(arr1, arr2, &s, sz);
	printf("%d\n", ret);
	system("pause");
	return 0;
}

