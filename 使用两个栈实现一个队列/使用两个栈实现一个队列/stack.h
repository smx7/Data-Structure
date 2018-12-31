
#include<stdio.h>
#include<windows.h>
#include<malloc.h>
#include<assert.h>

typedef int DataType;

typedef struct Stack
{
	DataType* _array;
	size_t _top; //Õ»¶¥ 
	size_t _end;
}Stack;
void EnQueue(Stack *s1, Stack *s2, DataType x);
void DeQueue(Stack *s1, Stack *s2);