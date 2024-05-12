#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint32_t a;
    uint32_t b;
    int check = scanf("%u %u", &a, &b);
    if (check < 0) {
        return 1;
    }
    uint32_t res = (((int64_t)a + b) / 2);
    printf("%u\n", res);
    return 0;
}