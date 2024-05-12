#include <stdio.h>

enum { MAX_EXP = 255, MAX_GOOD_EXP = 254, SIZE_MANTISA = 23, SIZE_EXP = 8 };

union {
    float f;
    unsigned int u;
} uf;

typedef enum FPClass
    {
        FFP_ZERO,         // нули
        FFP_DENORMALIZED, // числа в денормализованной форме
        FFP_NORMALIZED,   // числа в нормализованной форме
        FFP_INF,          // бесконечности
        FFP_NAN           // NaN-ы
    } FPClass;

FPClass fpclassf(float value, int *psign) {
    uf.f = value;
    unsigned long mantisa = 0;
    int sign = 0;
    unsigned int exp = 0;
    unsigned long step = 1;
    for (int i = 0; i < SIZE_MANTISA; ++i) {
        mantisa += step * (uf.u % 2);
        uf.u = uf.u >> 1;
        step = step * 2;
    }
    step = 1;
    for (int i = 0; i < SIZE_EXP; ++i) {
        exp += step * (uf.u % 2);
        uf.u = uf.u >> 1;
        step = step * 2;
    }
    FPClass t = FFP_ZERO;
    if (exp == 0 && mantisa == 0) {
        t = FFP_ZERO;
        sign = uf.u % 2;
    } else if (exp == MAX_EXP && mantisa != 0) {
        t = FFP_NAN;
    } else if (exp == MAX_EXP && mantisa == 0) {
        t = FFP_INF;
        sign = uf.u % 2;
    } else if (exp == 0) {
        t = FFP_DENORMALIZED;
        sign = uf.u % 2;
    } else if (exp <= MAX_GOOD_EXP && exp >= 1) {
        t = FFP_NORMALIZED;
        sign = uf.u % 2;
    }
    *psign = sign;
    return t;
}
