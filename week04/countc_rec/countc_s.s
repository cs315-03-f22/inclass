.global countc_s

/* countc_s recursively counts the instances of ch in str
	a0 = str
	a1 = ch
*/
countc_s:
	addi sp, sp, -16			# alloc stack space
	sd ra, (sp)

	li t0, 0					# t0 is ret val
	lb t1, (a0)					# t1 = *s
	beq t1, zero, done

	sd a0, 8(sp)				# preserve a0
	addi a0, a0, 1				# a0++
	call countc_s				# recurse
	mv t0, a0					# save ret val
	ld a0, 8(sp)				# restore a0 (s)

	lb t1, (a0)					# t1 = *a0
	bne t1, a1, done			# match?
	addi t0, t0, 1 				# new_count++
done:
	mv a0, t0					# set up ret val
	ld ra, (sp)					# restore ra
	addi sp, sp, 16				# dealloc stack space
	ret
