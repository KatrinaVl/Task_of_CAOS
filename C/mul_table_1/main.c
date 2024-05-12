#include <stdint.h>
#include <stdio.h>

int main(void) {
    int a;
    int b;
    int n;
    int check = scanf("%d%d%d", &a, &b, &n);
    if (check != 3) {
        return 1;
    }
    printf("%*s ", n, "");
    for (int64_t i = a; i < b; ++i) {
        printf("%*lld ", n, i);
    }
    printf("\n");
    for (int64_t i = a; i < b; ++i) {
        printf("%*lld ", n, i);
        for (int64_t j = a; j < b; ++j) {
            printf("%*lld ", n, i * j);
        }
        printf("\n");
    }
    return 0;
}