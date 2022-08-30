#include <stdbool.h>

bool ifelse_c(int val) {
	bool retval;
	
	if (val > 0) {
		retval = true;
	} else {
		retval = false;
	}
	return retval;
}
