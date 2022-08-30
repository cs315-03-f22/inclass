# This function should be callable from other C/Asm source code
.global add1_s

/*
	add1_s takes its parameter in a0
	and returns the param + 1 in a0
*/
add1_s:
	addi a0, a0, 1		# add 1 to a0
	ret
