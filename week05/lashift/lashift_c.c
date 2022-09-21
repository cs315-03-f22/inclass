#include <stdint.h>

int32_t ashift_c(uint32_t val, uint32_t amt) {
    // trick in C: only one >> operator
    // C compiler generates sra for signed number, or srl for unsigned
    int32_t retval = ((int32_t) val) >> amt;
    return retval;
}
