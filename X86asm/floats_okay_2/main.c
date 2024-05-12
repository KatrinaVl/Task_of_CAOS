#include <stdio.h>

float okay(float x, float y, float z);

int main()
{
    printf("%f\n", okay(16.0, 3.0, 10.0));
    printf("%f\n", okay(0.0, 3.0, 10.0));
    return 0;
}