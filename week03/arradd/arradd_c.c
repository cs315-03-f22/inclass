void arradd_c(int *arr, int len) {
	for (int i = 0; i < len; i++) {
		/* Do this like assembly language where we need to
			lw t0, (a0)
			addi t0, t0, 1
			sw t0, (a0)
		*/
		int elem = arr[i];
		elem++;
		arr[i] = elem;
	}
}
