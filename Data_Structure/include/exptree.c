#include <stdio.h>
#include "tstack.h"
#include "cstack.h"
#include "string.h"
#include "exptree.h"

int Priority(char opr) {
	switch (opr) {
		case '+': case '-': return 1; break;
		case '*': case '/': return 2; break;
		case '(': case ')':
		default:
			return 0; break;
	}
}

int IsOperator(char opr) {
	if (opr == '+' || opr == '-' || opr == '*' || opr == '/') {
		return 1;
	else
		return 0;
	}
}

String ConvertToSuffixExp(String &Exp) {
	String SuffixExp = {, 0};
	CStack S; 
	InitCStack(&S);
	
	for (int i = Exp->length; i >= 0; i--) {
		if (Exp->ch[i] >= '0' && Exp->ch[i] <= '9') {
			SuffixExp.ch[Exp->length - 1 - i] = Exp->ch[i];
			SuffixExp.length ++;
		}
		
		if (Exp->ch[i] == ')')
			Push_C(&S, Exp->ch[i]);
		
		while (IsOperator(Exp->ch[i])) {
			if (S.top == 0 || GetTop(&S) == ')'||
			    Priority(Exp->ch[i]) >= Priority(GetTop(&S)) {
				Push_C(&S, Exp->ch[i]);
				break;
			} else {
				SuffixExp.ch[Exp->length - 1 - i] = Pop_C(&S);
				SuffixExp.length ++;
			}
		}
		
		if (Exp->ch[i] = '(') {
			while (GetTop(&S) != ')') {
				SuffixExp.ch[Exp->length - 1 - i] = Pop_C(&S);
				SuffixExp.length++
			}
		}
	}
	
	while (S.top != -1) {
		SuffixExp.ch[++Suffix.length - 1] = Pop_C(&S);
	}
	
	return StrNeg(&SuffixExp);
}

void CreatExpTree(TNode &T, String &Exp) {
	TStack S;
	InitTStack(&S);
	String SuffixExp = ConvertToSuffixExp(Exp);
	
	for (int i = SuffixExp.length - 1; i >= 0; i--) {
		if (IsOperator(SuffixExp.ch[i])) {
			T = (TNode *)malloc(sizeof(TNode));
			T->data = SuffixExp.ch[i];
			T->lchild = NULL;
			T->rchild = NULL;
			Push_T(&S, *T);
		} else {
			T = (TNode *)malloc(sizeof(TNode));
			T->data = SuffixExp.ch[i];
			T->lchild = Pop_T(&S);
			T->rchild = Pop_T(&S);
			Push_T(&S, *T);
		}
	}
}

int Calc(int a, char opr, int b) {
	switch (opr) {
		case '+': return a + b; break;
		case '-': return a - b; break;
		case '*': return a * b; break;
		case '/': return a / b; break;
	}
}

int Value(TNode *T) {
	if (T->lchild == NULL && T->rchild == NULL)
		return T->data;
	else
		return Calc(Value(T->lchild), T->data, Value(T->rchild));
}