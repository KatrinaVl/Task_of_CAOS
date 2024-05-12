#include <stdio.h>

enum {
    FOR_0 = (1 << 7) + (1 << 6),
    FOR_OKET = (1 << 7),
    FOR_2_OKET = (1 << 7) + (1 << 6) + (1 << 5),
    FOR_RIGHT_2_OKET = (1 << 7) + (1 << 6),
    FOR_OSTATOK_1 = 31,
    FOR_OSTATOK_2 = 63,
    KIRILICA_BEGIN = 0x0400,
    KIRILICA_END = 0x04FF,
    SHIFT = 0x40
};

int main() {
    int c = getchar();
    int cp = 0;
    int kir = 0;

    while (c != EOF) {
        if ((c & FOR_0) != FOR_OKET) {
            ++cp;
        }
        if ((c & FOR_2_OKET) == FOR_RIGHT_2_OKET) {
            int ocket = getchar();
            int first = (c & FOR_OSTATOK_1);
            int second = (ocket & FOR_OSTATOK_2);
            int k = first * SHIFT + second;
            if (k >= KIRILICA_BEGIN && k <= KIRILICA_END) {
                ++kir;
            }
        }
        c = getchar();
    }

    printf("%d %d\n", cp, kir);
    return 0;
}