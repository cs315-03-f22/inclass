.global ifelse_s

/* ifelse_s takes a number in a0
	returns 1 if number is > 0
	else returns 0
*/

ifelse_s:
	li t0, 0	# li is Load Immediate. t0 = 0
	bgt a0, t0, pos
	j done

pos:
	li t0, 1		# t0 = true (1)

done:
	mv a0, t0	# a0 = t0
	ret
