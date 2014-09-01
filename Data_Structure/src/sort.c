#include <stdio.h>
#include "../include/sort.h"

void swap(SqList *L, int i, int j) {
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

// ********************************** 堆排序 ************************************
void HeapAdjust(SqList *L, int s, int m) {
	int temp, j;
	temp = L->r[s];
	for (j = 2 * s; j <= m; j *= 2 ) {
		if (j < m && L->r[j] < L->r[j + 1])
			++j;
		if (temp >= L->r[j])
			break;
		
		L->r[s] = L->r[j];
		s = j;
	}
	
	L->r[s] = temp;
}

void HeapSort(SqList *L) {
	for (int i = L->length / 2; i > 0; i++)
		HeapAdjust(L, i, L->length);
	
	for (int i = L->length; i > 1; i--) {
		swap(L, 1, i);
		HeapAdjust(L, 1, i - 1);
	}
}

// ********************************** 归并排序 ***********************************
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

void MSort(int SR[], int TR1[], int s, int t) { // 将SR[s..t]归并为TR1[s..t]
	int m;
	int TR2[MAXSIZE + 1];
	
	if (s == t)
		TR1[s] = SR[s];
	else {
		m = (s + t) / 2;
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m + 1, t);
		Merge(TR2, TR1, s, m, t);
	}
}

void MergeSort(SqList *L) {  // 对顺序表L做归并排序，应用递归
	MSort(L->r, L->r, 1, L->length);
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
		MergePass(L->r, TR, k, L->Length);
		k = 2 * k;
		MergePass(TR, l->r, k, L->length);
		k = 2 * k;
	}
}