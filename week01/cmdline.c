#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	for (int i = 0; i < argc; i++) {
		char *s = argv[i];

		printf("argv[%d] = %s\n", i, argv[i]);
		if (s[0] == '0' && s[1] == 'X') 
			printf("is a hex number\n");

		if (!strncmp(s, "-b", 2)) {
			int base = atoi(argv[i + 1]);
			printf("output base is %d\n", base);
		}
	}
	return 0;
}
