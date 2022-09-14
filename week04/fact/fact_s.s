.global fact_s

/* calculate the factorial of a given number
	a0 is the number
 */
fact_s:
	addi sp, sp, -16	# prologue
	sd ra, (sp)			# preserve ra

	li t1, 1 			# base case?
	ble a0, t1, done

	sd a0, 8(sp)		# preserve n
	addi a0, a0, -1		# set up n - 1
	# put something in t2
	# preserve t2
	call fact_s			# recurse
	mv t1, a0			# t1 = ret val
	ld a0, 8(sp)		# restore n
	mul a0, a0, t1		# n * retval
	# restore t2
	# refer to what we put in t2

done:
	ld ra, (sp)			# restore ra
	addi sp, sp, 16		# dealloc stack 
	ret
