#include <stdio.h>
#include "../Data_Structure/include/sqlist.h"

void SelectSort(SqList *L) {
	int i, j, min;
	
	for (i = 1; i < L->length; i++) {
		min = i;
		
		for (j = i + 1; j <= L->length; j++) {
			if (L->r[min] > L->r[j]) 
				min = j;
		}
		
		if (min != i)
			swap(L, min, i);
	}
}

int main(int argc, char *argv[]) {
	SqList L = { { 0, 12, 57, 90, 8, 34, 10, 42, 99, 64, 56, 73, 27 }, 12 };
	SqList *ptrL = &L;
	
	SelectSort(ptrL);
	
	for (int i = 1; i <= ptrL->length; i++) {
		printf("%d ", ptrL->r[i]);
	}
	
	return 0;
}