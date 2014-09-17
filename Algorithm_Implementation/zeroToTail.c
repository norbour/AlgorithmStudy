#include <stdio.h>

void swap(int array[], int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void ZeroToTail(int array[], int len) {
	int flag = 1;
	
	for (int i = len - 1; i >= 1 && flag; i--) {
		flag = 0;
		
		for (int j = i - 1; j >= 0; j--) {
			if (array[j] == 0) {
				swap(array, i ,j);
				flag = 1;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int array[] = { 1, 0, 3, 0, 5, 0, 56, 0, 0 };
	ZeroToTail(array, 9);
	
	for (int i = 0; i < 9; i++) {
		printf("%d ", array[i]);
	}
}