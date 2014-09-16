#ifndef SQLIST_H
#define SQLIST_H

#define MAXSIZE 100

typedef struct {
	int r[MAXSIZE + 1];
	int length;
}SqList;

void swap(SqList *L, int i, int j) {
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

#endif