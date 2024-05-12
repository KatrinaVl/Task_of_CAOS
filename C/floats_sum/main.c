#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    if (fabsf(*(float *)a) > fabsf(*(float *)b)) {
        return 1;
    }
    if (fabsf(*(float *)a) < fabsf(*(float *)b)) {
        return -1;
    }
    return 0;
}

int main() {
    int64_t count = 0;
    int er = scanf("%lld", &count);
    if (er != 1) {
        return 1;
    }
    float arr[count];
    for (int64_t i = 0; i < count; ++i) {
        int e = scanf("%f", &arr[i]);
        if (e != 1) {
            return 1;
        }
    }
    qsort(arr, count, sizeof(float), (int (*)(const void *, const void *))comp);
    float sum = 0.0;
    for (int64_t i = 0; i < count; ++i) {
        sum += arr[i];
    }
    printf("%0.15g\n", sum);
    return 0;
}