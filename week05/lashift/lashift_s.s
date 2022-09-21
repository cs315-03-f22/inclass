.global ashift_s

/* ashift_s does arithmetic shift right 
    a0 = value
    a1 = sh amt
*/
ashift_s:
    sra a0, a0, a1      # a0 = a0 >> a1. sra forces arithmetic
    ret
