.global sum_array_s

/* sum_array_s adds up the 32 bit words in an array
	a0 is the array
	a1 is the length
*/
sum_array_s:
	li t0, 0				# init retval to 0
	li t1, 0				# init loop index to 0
loop:
	beq t1, a1, done		# done?
	lw t2, 0(a0)			# t2 = *a0
	add t0, t0, t2			# t0 = t0 + t2 OR t0 += t2
	addi t1, t1, 1			# t1++
	addi a0, a0, 4			# a0 += 4, next elem in array
	j loop

done:
	mv a0, t0				# set up return value in a0
	ret
