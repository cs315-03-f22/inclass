#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int64_t make_b_offset(uint32_t iw) {
    uint32_t bit12 = get_bit(iw, 31);
    uint32_t bits10_5 = get_bits(iw, 25, 6);

    uint32_t offset = 0;
    offset = offset | (bit12 << 12)
    offset = offset | (bits10_5 << 10)
    ...

    offset += 1
    offset = offset + 1
    
    int64_t signed_offset = sign_extend(offset);
    return signed_offset;
}

int emu_b_type(struct rv_state *state, uint32_t iw) {
    int64_t branch_offset = make_b_offset(iw);
    uint32_t f3 = get_bits(iw, 12, 3);
    uint32_t rs1 = get_bits(iw, 15, 5);
    uint32_t rs2 = get_bits(iw, 20, 5);
    switch (f3) {
        case 0b100:  //blt
            if (state->regs[rs1] < state->regs[rs2])
                taken = true;

    }
            
    if taken {
        state->pc += branch_offset;       
}
