void Assign_by_data(struct ArrayData *_arrayData, int array, int data) {
	_arrayData->array = array;
	_arrayData->data = data;
};

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