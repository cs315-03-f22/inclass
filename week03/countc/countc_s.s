.global countc_s

/* findc_s returns true if c exists in s 
	else false
	a0 = s
	a1 = c
*/
findc_s:
	li a0, 0	# false
	ret

/* countc_s counts the occurrences of a character
	in the given string
	a0 = string
	a1 = char
*/
countc_s:
					# prologue
	addi sp, sp, -16	# alloc stack space
	sd ra, 0(sp)	# preserve ra
	
	li t0, 0		# init count
loop:
	lb t1, (a0)		# t1 = *a0
	beq t1, zero, done_count	# reached null terminator?

	sd a0, 8(sp)	# preserve a0
	jal findc_s	
	beq a0, zero, count_next
	addi t0, t0, 1 	# count++
count_next:
	ld a0, 8(sp)	# restore a0
	addi a0, a0, 1 	# s++
	j loop
done_count:
	mv a0, t0		# set up count as retval

					# epilogue
	ld ra, 0(sp)	# restore ra
	ret
