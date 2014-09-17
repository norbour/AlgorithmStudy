#include <stdio.h>
#include <stdlib.h>
#include "../Data_Structure/include/complexListNode.h"

int main(int argc, char *argv[]) {
	ComplexListNode* pHead = (ComplexListNode *)malloc(sizeof(ComplexListNode));
	pHead->data = 8;
	pHead->pNext = NULL;
	pHead->pRandom = pHead;
	
	ComplexListNode* pCloneHead = DeepClone(pHead);
	
	printf("%d\n", pCloneHead->data);
	printf("%d\n ", pCloneHead->pRandom->data);
	
	//pHead->pNext = pHead->pNext->pRandom;
	//printf("haha\n");
}