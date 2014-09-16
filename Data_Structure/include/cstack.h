#ifndef _CSTACK_H_
#define _CSTACK_H_

#include <stdio.h>

#define STACK_SIZE 100

typedef struct {
	char elem[STACK_SIZE];
	int top;
} CStack;

extern void InitCStack(CStack &S);

extern void Push_C(CStack &S, char e);

extern char Pop_C(CStack &S);

extern char GetTop(CStack &S);

extern int CStackLength(CStack &S);

#endif