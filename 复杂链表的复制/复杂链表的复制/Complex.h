#include<stdio.h>
#include<windows.h>
#include<malloc.h>
#include<assert.h>


typedef struct ComplexListNode
{
	int _data;
	struct ComplexListNode* _next;
	struct ComplexListNode* _random;
}ComplexListNode;

ComplexListNode* CopyComplexList(ComplexListNode* list);
ComplexListNode* BuyComplexNode(int x);
void printfComplexList(ComplexListNode* list);