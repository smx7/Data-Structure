#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
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
DataType StackTop(Stack* s)
{
	assert(s);
	return s->_array[s->_top-1];
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
int main()
{
	Stack s;
	DataType top = 0;
	size_t sz = 0;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	Stackprint(&s);
	StackPop(&s);
	Stackprint(&s);
	top = StackTop(&s);
	sz = StackSize(&s);
	printf("%d\n%u\n", top, sz);
	StackEmpty(&s);
	Stackprint(&s);
	system("pause");
	return 0;
}
