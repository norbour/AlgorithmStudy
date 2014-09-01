#ifndef SORT_H
#define SORT_H

#define MAXSIZE 100

typedef struct {
	int r[MAXSIZE + 1];
	int length;
}SqList;

extern void swap(SqList *L, int i, int j);
extern void MergeSort(SqList *L);            // 归并排序，递归实现
extern void MergeSort2(SqList *L);           // 归并排序，迭代实现
extern void HeapSort(SqList *L);             // 归并排序

void swap(SqList *L, int i, int j) {
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

#endif