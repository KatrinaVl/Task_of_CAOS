#include <stdint.h>
#include <stdio.h>

int64_t fibbonachi_root(uint64_t x) {
    if (x == 0) {
        return -1;
    }
    uint64_t a = 0;
    uint64_t b = 1;
    uint64_t c = 1;
    int64_t cnt = 0;
    while (c <= x) {
        a = b;
        b = c;
        c = a + b;
        ++cnt;
    }
    return cnt;
}

int main(void) {
    int64_t a;
    while (scanf("%llx", &a) == 1) {
        int64_t res = fibbonachi_root(a);
        printf("%llx ", res);
    }
    printf("\n");
    return 0;
}