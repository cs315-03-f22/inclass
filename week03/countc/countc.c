#include <stdio.h>

int countc_c(char *, char);
int countc_s(char *, char);

int main(int argc, char **argv) {
	char *s = argv[1];
	char ch = argv[2][0];

	int c_result = countc_c(s, ch);
	printf("C: %d\n", c_result);

	int s_result = countc_s(s, ch);
	printf("Asm: %d\n", s_result);

	return 0;
}
