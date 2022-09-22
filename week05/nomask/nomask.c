#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t nomask_c(uint32_t val, uint32_t start, uint32_t end);
uint32_t nomask_s(uint32_t val, uint32_t start, uint32_t end);

int main(int argc, char *argv[]) {
    uint32_t val = atoi(argv[1]);
    uint32_t start = atoi(argv[2]);
    uint32_t end = atoi(argv[3]);

    printf("C: %x\n", nomask_c(val, start, end));
    printf("Asm: %x\n", nomask_s(val, start, end));

    return 0;
}
