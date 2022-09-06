#include <stdio.h>
#include <stdlib.h>

int sum_array_c(int*, int);
int sum_array_s(int*, int);

int main(int argc, char **argv) {
	int arr[64] = {0,};
	int len = 0;
	
	for (int i = 1; i < argc; i++) {
		int val = atoi(argv[i]);
		arr[len] = val;
		len++;
	}

	int c_sum = sum_array_c(arr, len);
	int s_sum = sum_array_s(arr, len);

	printf("C: %d\nAsm: %d\n", c_sum, s_sum);
	
	return 0;
}
