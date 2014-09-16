#include <stdio.h>
#include "tstack.h"
#include "exptree.h"

void InitTStack(TStack &S) {
	S->elem = (char *)malloc(STACK_SIZE * sizeof(char));
	
	if (! S->elem) {
		printf("Overflow!\n");
		exit();
	}
	
	S->top = -1;
}

void Push_T(TStack &S, TNode T) {
	if (S->top == STACK_SIZE - 1) {
		printf("Stack Overflow!\n");
		exit();
	}
	
	S->elem[++S->top] = T;
}

TNode Pop_T(TStack &S) {
	if (S->top == -1) {
		printf("Stack empty!\n");
		exit();
	}
	
	return S->elem[S->top--];
}