#include <stdio.h>
#include <stdlib.h>
#include "../Data_Structure/include/sort.h"

void Merge(int SR[], int TR[], int i, int m, int n) { // 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n]
	int j, k, l;
	
	for (j = m + 1, k = i; i <= m && j <= n; k++) {
		if (SR[i] < SR[j])
			TR[k] = SR[i++];
		else 
			TR[k] = SR[j++];
	}
	
	if (i <= m) {
		for (l = 0; l <= m - i; l++) 
			TR[k + l] = SR[i + l];
	}
	if (j <= n) {
		for (l = 0; l <= n - j; l++)
			TR[k + l] = SR[j + l];
	}
}

void MergePass(int SR[], int TR[], int s, int n) { // 将SR[]中相邻长度为s的自序列两两归并到TR[]
	int i = 1;
	int j;
	while (i <= n - 2 * s + 1 ) {
		Merge(SR, TR, i, i + s - 1, i + 2 * s -1);
		i = i + 2 * s;
	}
	
	if (i < n - s + 1) 
		Merge(SR, TR, i, i + s - 1, n);
	else 
		for (j = i; j <= n; j++)
			TR[j] = SR[j];
}

void MergeSort2(SqList *L) { // 对顺序表L做归并排序，应用迭代
	int *TR = (int *)malloc(L->length * sizeof(int));
	int k = 1;
	while (k < L->length) {
		MergePass(L->r, TR, k, L->length);
		k = 2 * k;
		MergePass(TR, L->r, k, L->length);
		k = 2 * k;
	}
}

int main(int argc, char *argv[]) {
	SqList L = { { 0, 12, 57, 90, 8, 34, 10, 42, 99, 64, 56, 73, 27 }, 12 };
	SqList *ptrL = &L;
	
	MergeSort2(ptrL);
	
	for (int i = 1; i <= ptrL->length; i++) {
		printf("%d ", ptrL->r[i]);
	}
	
	return 0;
}