#include <stdio.h>
#include <stdlib.h>

void arradd_c(int *arr, int len);
void arradd_s(int *arr, int len);

void init_arr(int *arr, char **argv, int argc) {
	for (int i = 1; i < argc; i++) {
		arr[i - 1] = atoi(argv[i]);
	}
}

void print_arr(int *arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d \n", arr[i]);
	}
}

int main(int argc, char **argv) {
	int arr[128];
	int len = argc - 1;

	init_arr(arr, argv, argc);
	arradd_c(arr, len);
	print_arr(arr, len);
	
	init_arr(arr, argv, argc);
	arradd_s(arr, len);
	print_arr(arr, len);

	return 0;
}
