#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode {
	int             m_nValue;
	struct BinaryTreeNode *m_pLeft;
	struct BinaryTreeNode *m_pRight;
} BinaryTreeNode, *BiTree;

//extern void PreOrderTraverse(BiTree T);

//extern void MidOrderTraverse(BiTree T);

//extern void PostOrderTraverse(BiTree T);

//extern BinaryTreeNode* PreMidConstruct(int preOrder[], int midOrder[], int length);

void PreOrderTraverse(BiTree T) {
	if (T != NULL) {
		printf("%d ", T->m_nValue);
		PreOrderTraverse(T->m_pLeft);
		PreOrderTraverse(T->m_pRight);
	}
}

void MidOrderTraverse(BiTree T) {
	if (T != NULL) {
		MidOrderTraverse(T->m_pLeft);
		printf("%d ", T->m_nValue);
		MidOrderTraverse(T->m_pRight);
	}
}

void PostOrderTraverse(BiTree T) {
	if (T != NULL) {
		PostOrderTraverse(T->m_pLeft);
		PostOrderTraverse(T->m_pRight);
		printf("%d ", T->m_nValue);
	}
}

BinaryTreeNode* PreMidConstructCore(int* startPreOrder, int* endPreOrder,
                                    int* startMidOrder, int* endMidOrder) {
	int rootValue = startPreOrder[0];
	BinaryTreeNode* root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
	root->m_nValue = rootValue;
	root->m_pLeft = NULL;
	root->m_pRight = NULL;
	
	if (startPreOrder == endPreOrder) {
		if (startMidOrder == endMidOrder && *startPreOrder == *startMidOrder)
			return root;
		else {
			printf("Invalid input!\n");
			exit(1);
		}			
	}
	
	int* rootMidOrder = startMidOrder;
	while (rootMidOrder <= endMidOrder && *rootMidOrder != rootValue)
		++ rootMidOrder;
	if (rootMidOrder == endMidOrder && *rootMidOrder != rootValue) {
		printf("Invalid input!\n");
		exit(1);
	}
	
	int leftLength = rootMidOrder - startMidOrder;
	if (leftLength > 0) {
		root->m_pLeft = PreMidConstructCore(startPreOrder + 1, startPreOrder + leftLength,
		                                    startMidOrder, rootMidOrder - 1);
	}
	
	if (leftLength < endMidOrder - startMidOrder) {
		root->m_pRight = PreMidConstructCore(startPreOrder + leftLength + 1, endPreOrder,
		                                     rootMidOrder + 1, endMidOrder);
	}
	
	return root;
}

BinaryTreeNode* PreMidConstruct(int preOrder[], int midOrder[], int length) {
	if (preOrder == NULL || midOrder == NULL || length <= 0)
		return NULL;
	else
		return PreMidConstructCore(preOrder, preOrder + length - 1,
		                           midOrder, midOrder + length - 1);
}

#endif