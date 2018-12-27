
#include<stdio.h>
#include<windows.h>
#include<malloc.h>
#include<assert.h>

typedef int DataType;

typedef struct Stack
{
	DataType* _array;
	size_t _top; //ջ�� 
	size_t _end;
}Stack;

// ջ��ʵ�ֽӿ� 
void StackInit(Stack* s);
void StackPush(Stack* s, DataType x);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
size_t StackSize(Stack* s);
int StackEmpty(Stack* s);
