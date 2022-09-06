int len_c(char *s) {
	int count = 0;
	while (*s) {
		count++;
		s++;
	}
	return count;
}
