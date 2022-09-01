#include <stdio.h>
#include <stdlib.h>

int loop_c(int);
int loop_s(int);

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("usage: loop N\n");
		return -1;
	}

	int n = atoi(argv[1]);

	int c_result = loop_c(n);
	int s_result = loop_s(n);

	printf("C: %d\nAsm: %d\n", c_result, s_result);

	return 0;
}
