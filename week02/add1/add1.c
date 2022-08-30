#include <stdio.h>
#include <stdlib.h>

int add1_c(int);
int add1_s(int);

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("usage: add1 N\n");
		return -1;
	}

	int val = atoi(argv[1]);

	int c_result = add1_c(val);

	int s_result = add1_s(val);

	printf("C: %d\nAsm: %d\n", c_result, s_result);

	return 0;
}
