#define _CRT_SECURE_NO_WARNINGS 1
#include"Dstack.h"
void StackInit(Stack* s)
{
	s->_array = (DataType*)malloc(MAX * sizeof(DataType));
	if (s->_array)
	{
		s->_top1 = 0;
		s->_top2 = MAX - 1;
	}
}
int isfull(Stack *s)
{
	if (s->_top1 <= s->_top2)
		return 0;
	else
		return 1;
}
void StackPush(Stack* s, DataType x,int n)
{
	assert(s);
	if (isfull(s))
	{
		printf("full!\n");
		return;
	}
	if (n)
	{
		s->_array[s->_top1] = x;
		s->_top1++;
	}
	else
	{
		s->_array[s->_top2] = x;
		s->_top2--;
	}
}
int isEmpty(Stack*s, int n)
{
	if (n)
	{
		if (s->_top1 == 0)
			return 1;
		else
			return 0;
	}
	else
	{
		if (s->_top2 == MAX - 1)
			return 1;
		else
			return 0;
	}
}
void StackPop(Stack* s,int n)
{
	if (isEmpty(s, n))
	{
		printf("empty!\n");
		return;
	}
	if (n)
	{
		s->_top1--;
	}
	else
	{
		s->_top2++;
	}
}
void Stackprint(Stack *s, int n)
{
	int i = 0;
	if (n)
	{
		for (i = 0; i <(int) s->_top1; i++)
		{
			printf("%d ", s->_array[i]);
		}
		printf("\n");
	}
	else
	{
		for (i = MAX - 1; i>(int)s->_top2; i--)
		{
			printf("%d ", s->_array[i]);
		}
		printf("\n");
	}
}
int main()
{
	Stack s;
	int i = 0;
	StackInit(&s);
	for (int i = 0; i < 5; i++)
	{
		StackPush(&s, i, 1);
		StackPush(&s, 9 - i, 0);
	}
	StackPush(&s, 5, 1);
	Stackprint(&s, 1);
	Stackprint(&s, 0);

	StackPop(&s, 1);
	StackPop(&s, 0);
	StackPop(&s, 1);
	StackPop(&s, 0);
	Stackprint(&s, 1);
	Stackprint(&s, 0);

	system("pause");
	return 0;
}

