.global arradd_s

/* arradd_s takes an array and a length and
	adds 1 to each element of the array
	a0 = arr
	a1 = len
*/
arradd_s:
	li t0, 0		# init loop index register
loop:
	beq t0, a1, done
	lw t1, (a0)		# t1 = *a0
	addi t1, t1, 1	# increment array elem
	sw t1, (a0)		# *a0 = t1
	addi t0, t0, 1	# increment loop index
	addi a0, a0, 4	# walk arr to next 4 byte elem
	j loop
done:
	ret
