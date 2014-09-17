#ifndef _COMPLEXLISTNODE_H_
#define _COMPLEXLISTNODE_H_

#include <stdlib.h>

typedef struct ComplexListNode {
	int data;
	struct ComplexListNode* pNext;
	struct ComplexListNode* pRandom;
} ComplexListNode;

void CloneNodes(struct ComplexListNode* pHead) {
	if (pHead == NULL)
		return;
		
	ComplexListNode* pNode = pHead;
	while (pNode != NULL) {
		ComplexListNode* pCloneNode = (ComplexListNode*)malloc(sizeof(ComplexListNode));
		pCloneNode->data = pNode->data;
		pCloneNode->pRandom = NULL;
		pCloneNode->pNext = pNode->pNext;
		
		pNode->pNext = pCloneNode;
		
		pNode = pCloneNode->pNext;
	}
}

void CloneRandomLink(struct ComplexListNode* pHead) {
	if (pHead == NULL)
		return;
		
	ComplexListNode* pNode = pHead;
	while (pNode != NULL) {
		ComplexListNode* pCloneNode = pNode->pNext;
		if (pNode->pRandom != NULL) {
			pCloneNode->pRandom = pNode->pRandom->pNext;
		}
		pNode = pCloneNode->pNext;
	}
}

ComplexListNode* ResetNodelink(struct ComplexListNode* pHead) {
	if (pHead == NULL)
		return NULL;
		
	ComplexListNode* pNode = pHead;
	ComplexListNode* pCloneNode = pHead->pNext;
	ComplexListNode* pCloneHead = pCloneNode;
	
	pNode->pNext = pCloneNode->pNext;
	pNode = pNode->pNext;
	
	while (pNode != NULL) {
		pNode->pNext = pCloneNode->pNext;
		pNode = pNode->pNext;
		pCloneNode->pNext = pNode->pNext;
	}
	
	return pCloneHead;
}

ComplexListNode* DeepClone(struct ComplexListNode* pHead) {
	CloneNodes(pHead);       printf("Clone Nodes done!\n");
	CloneRandomLink(pHead);  printf("Clone random link done!\n");
	return ResetNodelink(pHead);
}

#endif