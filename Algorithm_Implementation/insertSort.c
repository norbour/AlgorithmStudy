#include <stdio.h>

void insert_sort(int array[], int length) {
	int i, j;
	
	for (i = 1; i < length; i++) {
		if (array[i] < array[i - 1]) {
			int temp = array[i];
		
			for (j = i - 1; temp < array[j] && j >= 0; j--)
				array[j + 1] = array[j];
		
			printf("array[%d] = %d ", j + 1, array[j + 1]);
			array[j + 1] = temp;			
			printf("%d\n", temp);
		}
	}
}

int main(int argc, char *argv[]) {
	int array[] = { 12, 57, 90, 8, 34, 67, 76, 24 };

	insert_sort(array, 8);

	for (int i = 0; i < 8; i++) {
		printf("%d ", array[i]);
	}
}