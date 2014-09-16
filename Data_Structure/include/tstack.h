#ifndef _TSTACK_H_
#define _TSTACK_H_

#include "exptree.h"

#define STACK_SIZE 100

typedef struct {
	TNode elem[STACK_SIZE];
	int top;
} TStack;

extern void InitTStack(TStack &S);

extern void Push_T(TStack &S, TNode T);

extern TNode Pop_T(TStack &S);

#endif