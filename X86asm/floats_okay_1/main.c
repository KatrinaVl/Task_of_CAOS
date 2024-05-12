#include <stdio.h>

void okay(double x, double y, double *r);

int main()
{
    double r;
    okay(4, 3, &r);

    printf("%f\n", r);
    return 0;
}