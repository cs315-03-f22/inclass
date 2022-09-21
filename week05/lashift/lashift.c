#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t ashift_c(uint32_t, uint32_t);
int32_t ashift_s(uint32_t, uint32_t);

int main(int argc, char **argv) {
    uint32_t val = atoi(argv[1]);
    uint32_t shamt = atoi(argv[2]);

    int32_t c_result;
    int32_t s_result;

    c_result = ashift_c(val, shamt);
    s_result = ashift_s(val, shamt);

    printf("C: %x\n", c_result);
    printf("Asm: %x\n", s_result);
}
