#pragma once 
#include<stdio.h>
#include<windows.h>
#include<malloc.h>
#include<assert.h>

typedef int DataType;

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;

	DataType _data;
}BSTreeNode;

/////////////////////////////////////////////////////// 
// �ǵݹ� 
BSTreeNode* BuyBSTreeNode(DataType x);
int BSTreeInsert(BSTreeNode** tree, DataType x);
BSTreeNode* BSTreeFind(BSTreeNode* tree, DataType x);
int BSTreeRemove(BSTreeNode** tree, DataType x);
void BSTreeDestory(BSTreeNode* tree);

/////////////////////////////////////////////////////// 
// �ݹ� 
int BSTreeInsertR(BSTreeNode** tree, DataType x);
BSTreeNode* BSTreeFindR(BSTreeNode* tree, DataType x);
int BSTreeRemoveR(BSTreeNode** tree, DataType x);
void TestBSTree();

 

