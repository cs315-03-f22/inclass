.global nomask_s

/* nomask_s selects bits from a number without masking
    a0 = number
    a1 = start
    a2 = end
*/
nomask_s:
    sub t0, a2, a1      # t0 is len
    addi t0, t0, 1

    li t1, 32           # t2 = 32
    sub t2, t1, a2      # t2 = 32 - end
    #addi t2, t2, -1     # t2 = 32 - end -1

    sll a0, a0, t2      # a0 = num << t2
    sub t2, t1, t0      # t2 = 32 - len
    srl a0, a0, t2      # a0 = sh_up >> t2
    ret
