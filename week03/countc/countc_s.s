.global countc_s
.global findc_s

/* findc_s returns the index of char in str, else -1 if not found
	a0 = string
	a1 = char
*/
findc_s:
	li t0, 0					# t0 is index of char in string
find_loop:
	lb t1, (a0)					# t1 = *a0
	beq t1, zero, not_found		# reached the null terminator
	bne t1, a1, find_next		# not found, go again
	j find_done
find_next:
	addi t0, t0, 1				# found index++
	addi a0, a0, 1 				# walk a0 to next
	j find_loop
not_found:
	li t0, -1 					# t0 = -1 for not found
find_done:
	mv a0, t0					# set up t0 as ret val
	ret

/* countc_s counts the occurrences of a character
	in the given string
	a0 = string
	a1 = char
*/
countc_s:
								# prologue
	addi sp, sp, -24			# alloc stack space
	sd ra, 0(sp)				# preserve ra
	
	li t0, 0					# init count
loop:
	lb t1, (a0)					# t1 = *a0
	beq t1, zero, done			# reached null terminator?

	sd a0, 8(sp)				# preserve a0
	sd t0, 16(sp)				# preserve t0
	jal findc_s	
	mv t2, a0					# t2 = retval (char index or -1)
	ld a0, 8(sp)				# restore a0
	ld t0, 16(sp)				# restore t0
	
	li t1, -1 					# init -1 for comparison below
	beq t2, t1, done			# not found, stop
	addi t0, t0, 1 				# found, count++
	addi t2, t2, 1 				# found index + 1
	add a0, a0, t2 				# s += (found index + 1) to walk past match
	j loop
done:
	mv a0, t0					# set up count retval
								# epilogue
	ld ra, 0(sp)				# restore ra
	addi sp, sp, 24				# dealloc space
	ret
