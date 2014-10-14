#include <stdio.h>
#include <stdlib.h>

void PrintArray(int* data, int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}

void MergeSortCore(int* array, int* copy, int start, int end) {
	if (start == end) {
		copy[start] = array[start];
		return;
	}
	
	int step = (end - start) / 2;
	
	MergeSortCore(copy, array, start, start + step);
	MergeSortCore(copy, array, start + step + 1, end);
	
	int i = start + step;
	int j = end;
	int indexCopy = end;
	
	while (i >= start && j >= start + step + 1) {
		if (copy[i] > copy[j]) {
			array[indexCopy--] = copy[i--];
		}
		else {
			array[indexCopy--] = copy[j--];
		}
	}
	
	for (; i >= start; --i) {
		array[indexCopy--] = copy[i];
	}
	
	for (; j >= start + step + 1; --j) {
		array[indexCopy--] = copy[j];
	}
	
	return;
}

void MergeSort(int* array, int length) {
	if (array == NULL || length <= 0) {
		return;
	}
	
	int* copy = (int *)malloc(sizeof(int) * length);
	
	for (int i = 0; i < length; i++) {
		copy[i] = array[i];
	}
	
	MergeSortCore(array, copy, 0, length - 1);
}

int main(int argc, char *argv[]) {
	int data[] = { 10, 7, 56, 8, 11, 34, 23, 5 };
	MergeSort(data, 8);
	PrintArray(data, 8);
}