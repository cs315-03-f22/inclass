#include <stdio.h>

int countc_c(char *arr, char ch);
int countc_s(char *arr, char ch);

int main(int argc, char **argv) {
	char *s = argv[1];
	char c = argv[2][0];

	int c_result = countc_c(s, c);
	printf("C: %d\n", c_result);

	int s_result = countc_s(s, c);
	printf("Asm: %d\n", s_result);

	return 0;
}
