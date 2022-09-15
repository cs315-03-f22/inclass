.global fmi_rec_s

/*
	fmi_rec_s recursively finds the index of the
	max element in arr
	a0 = arr
	a1 = len
	a2 = cur idx
	a3 = cur max idx
 */
fmi_rec_s:
						# prologue
	addi sp, sp, -16	# alloc stack space
	sd ra, (sp)			# preserve ra
	
	mv t0, a3			# t0 is the new max
	bge a2, a1, done

	mv t1, a2			# t1 = offset of idx in arr
	slli t1, t1, 2		# t1 = t1 << 2 (or * 4)
	add t1, a0, t1		# t1 = a0 + (idx * 4)
	lw t1, (t1)			# t1 = arr[idx]

	mv t2, a3			# t2 = offset of max_idx in arr
	slli t2, t2, 2		# t2 = t2 << 2 (or * 4)
	add t2, a0, t2		# t2 = a0 + (max_idx * 4)
	lw t2, (t2)			# t2 = arr[max_idx]

	ble t1, t2, recurse
	mv t0, a2			# new max = idx

recurse:
	addi a2, a2, 1		# set up idx + 1
	mv a3, t0			# set up max_new
	sd a0, 8(sp)		# preserve arr
	jal fmi_rec_s		# recurse
	mv t0, a0			# save ret val in t0
	lw a0, 8(sp)		# restore a0
done:
	mv a0, t0			# set up ret val
	ld ra, (sp)			# restore ra
	addi sp, sp, 16		# dealloc stack space
	
	ret
