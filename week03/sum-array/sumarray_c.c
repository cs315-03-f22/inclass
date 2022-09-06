#if 0

int sum_array_c(int *arr, int len) {
	int sum = 0;
	void *arrv = arr; // cast to void* so I can to ptr arithmetic
	for (int i = 0; i < len; i++) {
		int val = * (int*) arrv; // cast to int* to get the 4 byte int
		arrv += sizeof(int); // ptr arithmetic: +4
		sum += val;
	}
	return sum;
}

#else

int sum_array_c(int *arr, int len) {
	int sum = 0;
	void *arrv = arr; // cast to void* so I can to ptr arithmetic
	for (int i = 0; i < len; i++) {
		int offset = i * sizeof(int); // calculate offset of i'th elem in arr
		int val = * (int*) (arrv + offset); // deref arr + offset (arr[i]) to get value
		sum += val;
	}
	return sum;
}

#endif
