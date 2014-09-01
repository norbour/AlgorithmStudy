#ifndef SORT_H
#define SORT_H

#define MAXSIZE 100

typedef struct {
	int r[MAXSIZE + 1];
	int length;
}SqList;

extern void swap(SqList *L, int i, int j);
extern void MergeSort(SqList *L);

#endif