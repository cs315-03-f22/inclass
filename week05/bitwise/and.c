#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    int r = a & b;
    printf("r: %d\n", r);

    return 0;
}
