#include <stdint.h>
#include <stdio.h>

#include "rv_emu.h"

void rv_init(struct rv_state *state, uint32_t *func, 
            uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) {

    state->regs[RA] = 0;  // initialize ra register to 0

    state->regs[A0] = a0;
    state->regs[A1] = a1;
    state->regs[A2] = a2;
    state->regs[A3] = a3;

    state->pc = (uint64_t) func;
}

// Phil's approach: helper function for shift-and-mask
uint32_t get_bits(uint32_t iw, uint32_t start, uint32_t count) {
    uint32_t mask = (1 << count) - 1;
    return (iw >> start) & mask;
}

void emu_r_type(struct rv_state *state, uint32_t iw) {
    uint32_t rd = get_bits(iw, 7, 5); //(iw >> 7) & 0b11111;
    uint32_t rs1 = (iw >> 15) & 0b11111;
    uint32_t rs2 = (iw >> 20) & 0b11111;
    uint32_t func3 = (iw >> 12) & 0b111;
    uint32_t func7 = (iw >> 25) & 0x7F;

    switch (func3) {
        case 0b000:
            if (func7 == 0) //add
                state->regs[rd] = state->regs[rs1] + state->regs[rs2];
            break;
        default:
            printf("unsupported rtype func3\n");
    }

    state->pc += 4;
}

void emu_jalr(struct rv_state *state, uint32_t iw) {
    uint32_t rs1 = (iw >> 15) & 0x1f; // will be 1/ra

    state->pc = state->regs[rs1];  // pc = ra
}

// Greg's approach: make up a decode struct which uses the
// layout of RISC-V machine code to decode iw once
struct rv_decode {
    uint32_t rd;
    uint32_t rs1;
    //... 
};

void rv_one(struct rv_state *state, uint32_t iw) {
    uint32_t opcode = iw & 0b1111111;

    switch(opcode) {
        case 0b0110011:  // R-type instruction
            emu_r_type(state, iw);
            break;
        case 0b1100111:  // jalr
            emu_jalr(state, iw);
            break;
        default:
            printf("unsupported opcode\n");
    }
}

int rv_emu(struct rv_state *state) {
    while (state->pc != 0) {
        uint32_t *pc = (uint32_t*) state->pc;
        uint32_t iw = *pc;
        rv_one(state, iw);
    }
    return state->regs[A0];
} 
