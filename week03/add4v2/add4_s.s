.global add4_s

/* add2_s takes two integer params and adds them */
add2_s:
	add a0, a0, a1		# a0 = a0 + a1
	ret

/* add4_s takes four integer params and adds them 
	a0, a1, a2, a3
*/
add4_s:
						# prologue
	addi sp, sp, -32	# alloc stack space
	sd ra, 0(sp)		# preserve ra
	sd a2, 16(sp)		# preserve a2
	sd a3, 24(sp)		# preserve a3
	jal add2_s			# adds a0 and a1, result in a0
	sd a0, 8(sp)		# preserve first sum
	
	ld a2, 16(sp)		# restore a2
	ld a3, 24(sp)		# restore a3
	mv a0, a2			# set up params for second call to add2
	mv a1, a3
	
	jal add2_s			# adds third and fourth params, result in a0
	
	ld a1, 8(sp)		# restore first result into a1
	add a0, a0, a1		# add first sum and second sum together

						# epilogue
	ld ra, 0(sp)		# restore ra return address
	addi sp, sp, 32		# dealloc stack space

	ret
