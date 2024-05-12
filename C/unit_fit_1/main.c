#include <stdio.h>

enum { MAX_SIZE_MANTISA = (1 << 24) };

int isfloat(unsigned int t) {
    while (t % 2 == 0 && t != 0) {
        t /= 2;
    }
    if (t > MAX_SIZE_MANTISA) {
        return 0;
    }
    return 1;
}

int main() {
    unsigned int t = 0;
    int res = 0;
    while (scanf("%u", &t) == 1) {
        res = isfloat(t);
        printf("%u\n", res);
    }
    return 0;
}