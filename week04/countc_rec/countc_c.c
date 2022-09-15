int countc_c(char *s, char c) {
	if (!*s)
		return 0;

	int new_count = countc_c(s + 1, c);
	if (*s == c)
		new_count++;
	return new_count;
}
