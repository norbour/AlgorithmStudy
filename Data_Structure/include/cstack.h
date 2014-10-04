#ifndef _CSTACK_H_
#define _CSTACK_H_

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef struct {
	char *elem;
	int top;
} CStack;

void InitCStack(CStack *S) {
	S->elem = (char *)malloc(STACK_SIZE * sizeof(char));
	
	if (! S->elem) {
		printf("Overflow!\n");
		exit(1);
	}
	
	S->top = -1;
}

void Push_C(CStack *S, char e) {
	if (S->top == STACK_SIZE - 1) {
		printf("Stack Overflow!\n");
		exit(1);
	}
	
	S->elem[++S->top] = e;
}

char Pop_C(CStack *S) {
	if (S->top == -1) {
		printf("Stack empty!\n");
		exit(1);
	}
	
	return S->elem[S->top--];
}

char GetTop(CStack *S) {
	if (S->top == -1) {
		printf("Stack empty!\n");
		exit(1);
	}
	
	return S->elem[S->top];
}

int CStackLength(CStack *S) {
	return S->top + 1;
}

#endif