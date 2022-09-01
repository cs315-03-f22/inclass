.global loop_s

/* loop_s takes the number of loop iterations in a0 
	returns the number of iterations it did
*/

loop_s:
	li t0, 0			# t0 = 0

loop:
	beq t0, a0, done	# if t0 == a0, jump to done
	addi t0, t0, 1		# t0 = t0 + 1
	j loop

done:
	mv a0, t0			# set up retval a0 = t0
	ret
