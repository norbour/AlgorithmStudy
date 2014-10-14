#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void HeapAdjust(int *data, int s, int m) { 
	// 从二叉树最右端的非叶子结点开始，调整构造小根堆
	int temp, j;
	temp = data[s];
	for (j = 2 * s + 1; j <= m; j = j * 2 + 1 ) {
		if (j < m && data[j] > data[j + 1])
			++j;
		if (temp <= data[j])
			break;
		
		data[s] = data[j];
		s = j;
	}
	
	data[s] = temp;
}

void PrintArray(int *array, int length) {
	// 顺序打印数组
	for (int i = 0; i < length; i++) {
		printf("%d ", array[i]);
	}
	
	printf("\n");
}

void PrintTopK(const int *data, int length, int k) {
	if (data == NULL || length <= 0 || length < k) {
		return;
	}
	
	int *topk = (int *)malloc(sizeof(int) * k);
	memcpy(topk, data, sizeof(int) * k);
	
	PrintArray(topk, k);
	
	for (int i = k / 2 - 1; i >= 0; i--) {
		HeapAdjust(topk, i, k - 1);
	}
	
	PrintArray(topk, k);
	
	for (int i = k; i < length; i++) {
		if (data[i] > topk[0]) {
			topk[0] = data[i];
			HeapAdjust(topk, 0, k - 1);
		}
	}
	
	PrintArray(topk, k);
}

int main(int argc, char *argv[]) {
	int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
	PrintTopK(data, 8, 7);
}