.global len_s

/* len_s calculates the length of a C string
	a0 is the string
*/

len_s:
	li t0, 0		# t0 is the count

loop:
	lb t1, 0(a0)	# t1 = *a0
	beq t1, zero, done
	addi a0, a0, 1	# move a0 to point to the next char
	addi t0, t0, 1	# increment count
	j loop

done:
	mv a0, t0		# set up count ret val
	ret
