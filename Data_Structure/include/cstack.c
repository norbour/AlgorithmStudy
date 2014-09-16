#include <stdio.h>
#include "cstack.h"

void InitCStack(CStack &S) {
	S->elem = (char *)malloc(STACK_SIZE * sizeof(char));
	
	if (! S->elem) {
		printf("Overflow!\n");
		exit();
	}
	
	S->top = -1;
}

void Push_C(CStack &S, char e) {
	if (S->top == STACK_SIZE - 1) {
		printf("Stack Overflow!\n");
		exit();
	}
	
	S->elem[++S->top] = e;
}

char Pop_T(CStack &S) {
	if (S->top == -1) {
		printf("Stack empty!\n");
		exit();
	}
	
	return S->elem[S->top--];
}

char GetTop(CStack &S) {
	if (S->top == -1) {
		printf("Stack empty!\n");
		exit();
	}
	
	return S->elem[S->top];
}

int CStackLength(CStack &S) {
	return top + 1;
}

