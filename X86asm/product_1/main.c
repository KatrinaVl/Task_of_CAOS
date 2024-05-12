#include <stdio.h>
#include <stdlib.h>

void product(int n, const float *x, const float *y, float *result);

void check(int n, const float *x, const float *y, float *result){
    *result = 0;
    int s = 1;
    for (int i = 0; i < n; ++i){
        *result += (*(x + i)) * (*(y + i)) * s;
        s *= -1;
    }
}

int main()
{
    srand(7);
    int n;
    scanf("%d\n", &n);
    float x[2] = { 1.5, 3.5 };
    float y[2] = { -3.5, -1.0 };
    // int mod = 213;
    // float x[5];
    // for(int i = 0; i < n; ++i){
    //     x[i] = (float)(rand() % mod) / 11.0;
    // }
    // float y[5];
    // for(int i = 0; i < n; ++i){
    //     y[i] = (float)(rand() % mod) / 11.0;
    // }
    float result;
    float drty;
    product(n, x, y, &result);
    check(n, x, y, &drty);
    printf("%f\n", result);
    printf("%f\n", drty);
    return 0;
}