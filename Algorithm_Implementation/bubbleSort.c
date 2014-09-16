#include <stdio.h>
#include "../Data_Structure/include/sqlist.h"

#define TURE 1
#define FALSE 0

void BubbleSort(SqList *L) {
	int i, j;
	int flag = TURE;
	
	for (i = 1; i < L->length && flag; i++) {
		for (j = L->length - 1; j >= i; j--) {
			flag = FALSE;
			
			if (L->r[j] > L->r[j+1]) {
				swap(L, j, j+1);
				flag = TURE;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	SqList L = { { 0, 12, 57, 90, 8, 34, 10, 42, 99, 64, 56, 73, 27 }, 12 };
	SqList *ptrL = &L;
	
	BubbleSort(ptrL);
	
	for (int i = 1; i <= ptrL->length; i++) {
		printf("%d ", ptrL->r[i]);
	}
	
	return 0;
}