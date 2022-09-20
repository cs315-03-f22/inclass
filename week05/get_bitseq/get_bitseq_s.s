.global get_bitseq_s

/* get_bitseq_s takes start and end, masks off those bits
    a0 = num
    a1 = start
    a2 = end
*/
get_bitseq_s:
    sub t0, a2, a1      # calc end - start + 1
    addi t0, t0, 1      # t0 is len
    srl a0, a0, a1      # num >> start

    li t2, 32
    bne t0, t2, general_case
    li t1, 0xffffffff
    j mask
general_case:
    li t1, 1            # t1 = 1
    sll t1, t1, t0      # t1 = 1 << len
    addi t1, t1, -1     # t1 -= 1, makes mask

mask:
    and a0, a0, t1      # a0 = (num >> start) & mask
    ret
