#include <stdint.h>

#define NREGS 32
#define RA 1    // ra is x1
#define A0 10   // a0 is x10
#define A1 11
#define A2 12
#define A3 13

struct rv_state {
    uint64_t regs[NREGS];
    uint64_t pc;
};

void rv_init(struct rv_state *state, uint32_t *func, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3);
int rv_emu(struct rv_state *);
