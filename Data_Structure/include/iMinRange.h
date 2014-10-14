#ifndef IMINRANGE_H
#define IMINRANGE_H

struct ArrayData {
	int array;
	int data;
} ArrayData;

extern void Assign_by_data(struct ArrayData* _arrayData, int array, int data);

extern void Assign_by_struct(struct ArrayData* _desArrayData, const struct ArrayData* _srcArrayData);

extern void HeapAdjust(struct ArrayData _arrayData[], int s, int m);

extern void HeapSort(struct ArrayData _arrayData[], int n);

#endif