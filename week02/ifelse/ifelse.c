#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool ifelse_c(int);
bool ifelse_s(int);

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("usage: ifelse N\n");
		return -1;
	}

	int val = atoi(argv[1]);

	bool c_result = ifelse_c(val);

	bool s_result = ifelse_s(val);

	printf("C: %d\nAsm: %d\n", c_result, s_result);

	return 0;
}
