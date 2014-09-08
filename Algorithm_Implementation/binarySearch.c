#include <stdio.h>
#include "../Data_Structure/include/sqlist.h"

int binary_search(const SqList *L, int key) {
	int low = 1;
	int mid;
	int high = L->length;
	
	while(low <= high) {
		mid = (low + high) / 2;
		
		if(L->r[mid] > key)
			high = mid - 1;
		else if(L->r[mid] < key)
			low = mid + 1;
		else
			return mid;
	}
	
	return 0;
}

int main(int argc, char *argv[]) {
	SqList L = { { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }, 12 };
	SqList *ptrL = &L;
	
	printf("%d\n", binary_search(ptrL, 0));
}