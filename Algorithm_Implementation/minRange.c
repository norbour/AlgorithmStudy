#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "../Data_Structure/include/iMinRange.h"

struct ArrayData {
	int array;
	int data;
} ArrayData;

void Assign_by_struct(struct ArrayData *_desArrayData, const struct ArrayData *_srcArrayData) {
	_desArrayData->array = _srcArrayData->array;
	_desArrayData->data = _srcArrayData->data;
};

void HeapAdjust(struct ArrayData _arrayData[], int s, int m) {
	struct ArrayData *temp = (struct ArrayData *)malloc(sizeof(struct ArrayData)); 		
	Assign_by_struct(temp, &_arrayData[s]);
	
	for (int j = 2 * s + 1; j <= m; j = j * 2 + 1) {
		if (j < m && _arrayData[j].data < _arrayData[j + 1].data) 
			++ j;
		if (temp->data >= _arrayData[j].data)
			break;
			
		Assign_by_struct(&_arrayData[s], &_arrayData[j]);
		
		s = j;
	}
	
	Assign_by_struct(&_arrayData[s], temp);
}

void swap(struct ArrayData *a, struct ArrayData *b) {
	struct ArrayData *temp = (struct ArrayData *)malloc(sizeof(struct ArrayData));
	Assign_by_struct(temp, a);
	Assign_by_struct(a, b);
	Assign_by_struct(b, temp);
}

void HeapSort(struct ArrayData _arrayData[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		HeapAdjust(_arrayData, i, n - 1);
	}
	
	for (int i = n - 1; i > 0; i--) {
		swap(&_arrayData[0], &_arrayData[i]);
		HeapAdjust(_arrayData, 0, i - 1);
	}
}

void MinRange(int arrays[3][5], int m, int n) {
	int *cur = (int *)malloc(sizeof(int) * m);	
	for (int i = 0; i < m; i++) {
		cur[i] = 1;
	}
	
	struct ArrayData *heap = (struct ArrayData *)malloc(sizeof(struct ArrayData) * m);
	for (int i = 0; i < m; i++) {
		heap[i].array = i;
		heap[i].data = arrays[i][0];
	}
	HeapSort(heap, 3);
	
	int ms = heap[0].data, me = heap[m - 1].data;
	int ts = 0, te = 0;
	
	while (1) {
		HeapSort(heap, 3);
		ts = heap[0].data;
		te = heap[m - 1].data;
		
		if (te - ts < me - ms) { 
			me = te;
			ms = ts; 
		}
		
		
		if (cur[heap[0].array] != n) {
			heap[0].data = arrays[heap[0].array][cur[heap[0].array]];
			cur[heap[0].array] += 1;
		}
		else {
			break;
		}
	}
	
	printf("[%d, %d]\n", ms, me);
}

int main(int argc, char *argv[]) {
	int arrays[][5] = {
		{ 4, 10, 15, 24, 26 },
		{ 0, 9, 12, 20, 35 },
		{ 5, 18, 22, 30, 50 }
	};
	
	MinRange(arrays, 3, 5);
}