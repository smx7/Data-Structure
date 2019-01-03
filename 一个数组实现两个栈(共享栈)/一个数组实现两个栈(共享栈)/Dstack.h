#include<stdio.h>
#include<windows.h>
#include<malloc.h>
#include<assert.h>
#define MAX 10

typedef int DataType;

typedef struct Stack
{
	DataType* _array;
	size_t _top1;
	size_t _top2;//Õ»¶¥ 
}Stack;
void StackInit(Stack* s);
int isfull(Stack *s);
void StackPush(Stack* s, DataType x,int n);
int isEmpty(Stack*s, int n);
void StackPop(Stack* s,int n);