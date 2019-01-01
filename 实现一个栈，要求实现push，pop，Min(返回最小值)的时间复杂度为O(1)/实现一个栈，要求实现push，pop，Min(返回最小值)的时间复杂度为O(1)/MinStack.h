
#include<stdio.h>
#include<windows.h>
#include<malloc.h>
#include<assert.h>

typedef int DataType;

typedef struct Stack
{
	DataType* _array;
	DataType* _min;
	size_t _top; //ջ�� 
	size_t _end;
}Stack;

void MinStackPush(Stack *s,DataType x);
void MinStackPop(Stack *s);
DataType MinStack(Stack *s);