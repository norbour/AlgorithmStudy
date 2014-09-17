#include <stdio.h>
#include <stdlib.h>

void swap(int array[], int i, int j) {
	int temp = array[j];
	array[j] = array[i];
	array[i] = temp;
}

int partition(int array[], int low, int high) {
	int pivotkey = array[low];
	
	while (low < high) {
		while (low < high && array[high] >= pivotkey) high--;
		swap(array, low, high);
		
		while (low < high && array[low] <= pivotkey) low++;
		swap(array, low, high);
	}
	
	return low;
}

void quick_sort(int array[], int low, int high) {
	int pivot;
	
	if (low < high) {
		pivot = partition(array, low, high);
		printf("%d\n", pivot);
		quick_sort(array, low, pivot - 1);
		quick_sort(array, pivot + 1, high);
	}
}

int main(int argc, char *argv[]) {
	int array[] = { 12, 57, 90, 8, 34, 10, 42, 99, 64, 56, 73, 27 };

	quick_sort(array, 0, 11);

	for (int i = 0; i < 12; i++) {
		printf("%d ", array[i]);
	}
}