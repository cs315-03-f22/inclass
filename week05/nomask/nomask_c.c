#include <stdint.h>

uint32_t nomask_c(uint32_t val, uint32_t start, uint32_t end) {
    uint32_t shifted_up = val << (32 - end - 1);
    uint32_t len = end - start + 1;
    uint32_t shifted_down = shifted_up >> (32 - len);
    return shifted_down;
}
