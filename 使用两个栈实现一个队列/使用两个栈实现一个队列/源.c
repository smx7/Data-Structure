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
int StackEmpty(Stack* s)
{
	if (s->_top - s->_end==0)
	{
		return 1;
	}
	else
		return 0;
}
void EnQueue(Stack *s1, Stack *s2, DataType x)
{
	StackPush(s1, x); 
}
void DeQueue(Stack *s1, Stack *s2)
{
	if (StackEmpty(s2)==1)
	{
		while (StackEmpty(s1)==0)
		{
			StackPush(s2, s1->_array[s1->_top - 1]);
			StackPop(s1);
		}
	}
	StackPop(s2);
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
	Stack s1, s2;
	StackInit(&s1);
	StackInit(&s2);
	EnQueue(&s1, &s2, 1);
	EnQueue(&s1, &s2, 2);
	EnQueue(&s1, &s2, 3);
	EnQueue(&s1, &s2, 4);
	EnQueue(&s1, &s2, 5);
	Stackprint(&s1);
	//DeQueue(&s1, &s2);
	//DeQueue(&s1, &s2);
	//Stackprint(&s2);

	system("pause");
	return 0;
}