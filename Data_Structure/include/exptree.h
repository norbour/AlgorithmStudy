#ifndef _EXPTREE_H_
#define _EXPTREE_H_

#include "string.h"

typedef struct {
	union data {
		char opr;
		int opn;
	}
	
	struct TNode *lichid, *rchild;
} TNode;

typedef TNode *BiTree;

extern int Priority(char opr);

extern int IsOperator(char opr);

extern String ConvertToSuffixExp(String &Exp);

extern void CreatExpTree(TNode &T, String &Exp);

extern int Calc(int a, char opr, int b);

extern int Value(TNode *T);

#endif