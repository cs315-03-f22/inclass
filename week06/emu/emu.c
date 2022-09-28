#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "rv_emu.h"

int add_c(int, int);
int add_s(int, int);

int main(int argc, char **argv) {
    int val1 = atoi(argv[1]);
    int val2 = atoi(argv[2]);

    int c_result = add_c(val1, val2);
    printf("C: %d\n", c_result);

    int s_result = add_s(val1, val2);
    printf("Asm: %d\n", s_result);

    struct rv_state state;
    rv_init(&state, (uint32_t*) &add_s, (uint64_t) val1, (uint64_t) val2, 0, 0);
    
    int e_result = rv_emu(&state);
    printf("Emu: %d\n", e_result);

    return 0;
}
