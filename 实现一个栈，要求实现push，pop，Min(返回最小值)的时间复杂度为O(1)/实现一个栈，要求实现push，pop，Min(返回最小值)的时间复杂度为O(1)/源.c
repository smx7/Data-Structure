#define _CRT_SECURE_NO_WARNINGS 1
#include"MinStack.h"
void StackInit(Stack* s)
{
	s->_array = (DataType*)malloc(10 * sizeof(DataType));
	s->_min = (DataType*)malloc(10 * sizeof(DataType));
	if (s->_array&&s->_min)
	{
		s->_end = 0;
		s->_top = 0;
	}
}
void MinStackPush(Stack *s, DataType x)
{
	assert(s);
	if (s->_top == 0)
	{
		s->_array[s->_top] = x;
		s->_min[s->_top] = x;
		s->_top++;
	}
	else
	{
		if (x > s->_array[s->_top - 1])
		{
			s->_array[s->_top] = x;
			s->_min[s->_top] = s->_min[s->_top - 1];
			s->_top++;
		}
		else
		{
			s->_array[s->_top] = x;
			s->_min[s->_top] = x;
			s->_top++;
		}
	}
}
void StackPrint(Stack *s)
{
	assert(s);
	size_t size = s->_top - s->_end;
	int i = 0;
	for (i = 0; i < (int)size; i++)
	{
		printf("%d ", s->_array[i]);
	}
	printf("\n");
	for (i = 0; i < (int)size; i++)
	{
		printf("%d ", s->_min[i]);
	}
	printf("\n");
}
void MinStackPop(Stack *s)
{
		s->_top--;
}
DataType MinStack(Stack *s)
{
	return s->_min[s->_top-1];
}
int main()
{
	Stack s;
	DataType m = 0;
	StackInit(&s);
	MinStackPush(&s, 2);
	MinStackPush(&s, 1);
	MinStackPush(&s, 1);
	MinStackPush(&s, 4);
	MinStackPush(&s, 5);
	//MinStackPop(&s);
	StackPrint(&s);
	m = MinStack(&s);
	printf("%d\n", m);
	system("pause");
	return 0;
}
