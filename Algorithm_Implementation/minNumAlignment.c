#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_LEN 10

int compare(int a, int b) {
	char *a_str = (char *)malloc(sizeof(char) * MAX_NUM_LEN + 1);
	char *b_str = (char *)malloc(sizeof(char) * MAX_NUM_LEN + 1);
	sprintf(a_str, "%d", a);
	sprintf(b_str, "%d", b);
	
	char *combine_str_ab = (char *)malloc(sizeof(char) * MAX_NUM_LEN * 2 + 1);
	char *combine_str_ba = (char *)malloc(sizeof(char) * MAX_NUM_LEN * 2 + 1);
	
	strcpy(combine_str_ab, a_str); strcat(combine_str_ab, b_str);
	strcpy(combine_str_ba, b_str); strcat(combine_str_ba, a_str);
	
	return strcmp(combine_str_ab, combine_str_ba);
}

void SelectSort(int *array, int length) {
	int i, j, min;
	
	for (i = 0; i < length - 1; i++) {
		min = i;
		
		for (j = i + 1; j <= length - 1; j++) {
			if (compare(array[min], array[j]) > 0)
				min = j;
		}
		
		if (min != i) {
			int temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
	}
}

void PrintMinNumAlignment(int *array, int length) {
	SelectSort(array, length);
	
	for (int i = 0; i < length; i++) {
		printf("%d", array[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	int array[] = { 21, 9, 13, 40, 6, 300 };
	PrintMinNumAlignment(array, 6);
}