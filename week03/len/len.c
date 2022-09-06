#include <stdio.h>

int len_c(char *s);
int len_s(char *s);

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("usage: len str\n");
		return -1;
	}

	char *s = argv[1];

	int c_result = len_c(s);
	int s_result = len_s(s);

	printf("C: %d\nAsm: %d\n", c_result, s_result);

	return 0;
}
