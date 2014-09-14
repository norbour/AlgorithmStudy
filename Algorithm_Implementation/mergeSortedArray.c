// 有两个排序的数组A1和A2，假设A1末尾有足够多的空间容纳A2，
// 请实现一个函数，把A2中所有数字插入到A1中并保证所有的数字是排序的

#include <stdio.h>

void MergeSortedArray(int A1[], int num1, int len, int A2[], int num2) {
// num1是A1中有效数字个数，len是A1空间容量长度，num2是A2中有效数字个数
	if ( (num1 + num2) > len 
	    || A1 == NULL 
	    || A2 == NULL 
	    || num1 == 0
	    || num2 == 0 ) return;
	
	int indexOfA1 = num1 - 1;
	int indexOfA2 = num2 - 1;
	int indexOfNew = num1 + num2 - 1;
	
	while (indexOfA2 >= 0 && indexOfA1 < indexOfNew) {
		if (A1[indexOfA1] > A2[indexOfA2])
			A1[indexOfNew --] = A1[indexOfA1 --];
		else 
			A1[indexOfNew --] = A2[indexOfA2 --];
	}
}

int main(int argc, char *argv[]) {
	int A1[10] = { 1, 3, 5, 7, 9 };
	int A2[5] = { 2, 4, 6, 8, 10 };
	
	MergeSortedArray(A1, 5, 10, A2, 5);
	
	for (int i = 0; i < 10; i++)
		printf("A[%d] = %d\n", i, A1[i]);
}