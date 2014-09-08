#include <stdio.h>
#include "../Data_Structure/include/sort.h"

void swap(SqList *L, int i, int j) {
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

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
	for (int i = L->length / 2; i > 0; i--)
		HeapAdjust(L, i, L->length);
	
	for (int i = L->length; i > 1; i--) {
		swap(L, 1, i);
		HeapAdjust(L, 1, i - 1);
	}
}

int main(int argc, char *argv[]) {
	SqList L = { { 0, 12, 57, 90, 8, 34, 10, 42, 99, 64, 56, 73, 27 }, 12 };
	SqList *ptrL = &L;
	
	HeapSort(ptrL);
	
	for (int i = 1; i <= ptrL->length; i++) {
		printf("%d ", ptrL->r[i]);
	}
	
	return 0;
}