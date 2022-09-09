// Returns the index of ch in s, or -1 if not found
int findc_c(char *s, char ch) {
	int index = 0;
	while (*s != '\0') {
		if (*s == ch) {
			// early return if found
			return index; 
		}
		s++; // walk s
		index++; // walk found index
	}
	// if we reach this, not found
	return -1;
}

int countc_c(char *s, char ch) {
	int count = 0;
	while (*s != '\0') {
		int index = findc_c(s, ch);
		if (index == -1) {
			// not found, break loop
			break;
		} else {
			count++;
			 // walk s forward past the match
			s += index + 1;
		}
	}
	return count;
}
