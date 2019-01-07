#define _CRT_SECURE_NO_WARNINGS 1
#include"Bstree.h"
BSTreeNode* BuyBSTreeNode(DataType x)
{
	BSTreeNode* newnode = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	assert(newnode);
	newnode->_left = NULL;
	newnode->_right = NULL;
	newnode->_data = x;
	return newnode;
}
int BSTreeInsert(BSTreeNode** tree, DataType x)
{
	BSTreeNode* cur = *tree;
	BSTreeNode* parent = cur;
	if (*tree == NULL)
	{
		*tree = BuyBSTreeNode(x);
	}
	else
	{

		while (cur)
		{
			if (cur->_data > x)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_data < x)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return -1;
			}
		}
		if (parent->_data>x)
		{
			parent->_left = BuyBSTreeNode(x);
		}
		else
		{
			parent->_right = BuyBSTreeNode(x);
		}
	}
	return 0;
}
void BSTreeInOrder(BSTreeNode* tree)
{
	if (tree == NULL)
	{
		return;
	}
	BSTreeInOrder(tree->_left);
	printf("%d ", tree->_data);
	BSTreeInOrder(tree->_right);
}
BSTreeNode* BSTreeFind(BSTreeNode* tree, DataType x)
{
	BSTreeNode* cur = tree;
	if (tree == NULL)
	{
		return NULL;
	}
	else
	{
		while (cur)
		{
			if (cur->_data > x)
			{
				cur = cur->_left;
			}
			else if (cur->_data < x)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
	}
	return NULL;
}
int BSTreeRemove(BSTreeNode** tree, DataType x)
{
	BSTreeNode* cur = *tree;
	BSTreeNode* parent = cur;

	while (cur)
	{
		if (cur->_data > x)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (cur->_data < x)
		{
			parent = cur;
			cur = cur->_right;
		}
		else//找到x
		{
			if (cur->_left == NULL)//左孩子为空
			{
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
			else if (cur->_right == NULL)//右孩子为空
			{
				if (parent->_left == cur)
					parent->_left = cur->_left;
				else
					parent->_right = cur->_left;
			}
			else//左右孩子都不为空
			{
				BSTreeNode* minright = cur;      //minright为右子树最小节点
				parent = cur;
				minright = minright->_right;
				while (minright->_left)
				{
					parent = minright;
					minright = minright->_left;
				}
				cur->_data = minright->_data;
				cur = minright;
				if (minright == parent->_left)   //注意，此时的minright是最左节点
					parent->_left = minright->_right;
				else                             //此时的minright为根节点的右子树的根节点，parent为根节点
					parent->_right = minright->_right;
			}
			free(cur);
			cur = NULL;
			return 0;
		}
	}
	return -1;
}
int BSTreeInsertR(BSTreeNode** tree, DataType x)
{
	if (*tree == NULL)
	{
		*tree = BuyBSTreeNode(x);
		return 0;
	}
	if ((*tree)->_data > x)
	{
		return BSTreeInsertR(&((*tree)->_left), x);
	}
	else if ((*tree)->_data < x)
	{
		return BSTreeInsertR(&((*tree)->_right), x);
	}
	else
		return -1;
}
BSTreeNode* BSTreeFindR(BSTreeNode* tree, DataType x)
{
	if (tree == NULL)
	{
		return NULL;
	}
	if (tree->_data > x)
	{
		return BSTreeFindR(tree->_left, x);
	}
	else if (tree->_data < x)
	{
		return BSTreeFindR(tree->_right, x);
	}
	else
		return tree;
}
int BSTreeRemoveR(BSTreeNode** tree, DataType x)
{
	if (*tree == NULL)
	{
		return -1;
	}
	if ((*tree)->_data > x)
	{
		return BSTreeRemoveR(&((*tree)->_left), x);
	}
	else if ((*tree)->_data < x)
	{
		return BSTreeRemoveR(&((*tree)->_right), x);
	}
	else
	{
		if ((*tree)->_left == NULL)
		{
			*tree = (*tree)->_right;
		}
		else if ((*tree)->_right == NULL)
		{
			*tree = (*tree)->_left;
		}
		else
		{
			BSTreeNode* minright = *tree;      //minright为右子树最小节点
			BSTreeNode* parent = *tree;
			minright = minright->_right;
			while (minright->_left)
			{
				parent = minright;
				minright = minright->_left;
			}
			(*tree)->_data = minright->_data;
			*tree = minright;
			if (minright == parent->_left)   //注意，此时的minright是最左节点
				parent->_left = minright->_right;
			else                             //此时的minright为根节点的右子树的根节点，parent为根节点
				parent->_right = minright->_right;
		}
		free(*tree);
		return 0;
	}
}
int main()
{
	TestBSTree();
	system("pause");
	return 0;
}
void TestBSTree() 
{ 
// BSTreeNode* tree = NULL; 
// BSTreeInsert(&tree, 4); 
// BSTreeInsert(&tree, 2); 
// BSTreeInsert(&tree, 1); 
// BSTreeInsert(&tree, 3); 
// BSTreeInsert(&tree, 2); 
// 
//BSTreeNode* node = BSTreeFindR(tree, 2); 
//printf("Find 2? %d\n", node->_data); 
 
 int a[] = {5,3,4,1,7,8,2,6,0,9}; 
 BSTreeNode* tree = NULL; 
 
 for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) 
 { 
 BSTreeInsertR(&tree, a[i]); 
 } 
 
 BSTreeInOrder(tree); 
 printf("\n"); 
 
 BSTreeRemoveR(&tree, 4); 
 BSTreeRemove(&tree, 8); 
 BSTreeRemove(&tree, 3); 
 BSTreeRemove(&tree, 7); 
 BSTreeRemove(&tree, 5); 

 BSTreeInOrder(tree); 
 printf("\n"); 
// 
// BSTreeRemove(&tree, 0); 
// BSTreeRemove(&tree, 1); 
// BSTreeRemove(&tree, 2); 
// BSTreeRemove(&tree, 3); 
// BSTreeRemove(&tree, 4); 
// BSTreeRemove(&tree, 5); 
// BSTreeRemove(&tree, 6); 
// BSTreeRemove(&tree, 7); 
// BSTreeRemove(&tree, 8); 
// BSTreeRemove(&tree, 9); 
// 
// BSTreeInOrder(tree); 
// printf("\n"); 
};
