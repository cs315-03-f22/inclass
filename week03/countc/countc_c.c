#include <stdbool.h>

bool findc_c(char *s, char ch) {
	bool found = false;
	while (*s != '\0') {
		if (*s == ch) {
			found = true;
		}
		s++;
	}
	return found;
}

int countc_c(char *s, char ch) {
	int count = 0;
	while (*s != '\0') {
		bool found = findc_c(s, ch);
		if (found) {
			count++;
		}
		s++;
	}
	return count;
}
