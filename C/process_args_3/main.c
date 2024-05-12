#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        char *p_end;
        // printf("%s\n", *(argv + i));
        long int c = strtol(argv[i], &p_end, 10);
        errno = 0;
        if (ERANGE == errno || c != (int32_t)c || *p_end != '\0' ||
            p_end == argv[i]) {
            printf("-1\n");
        } else {
            if (c == (int8_t)c) {
                printf("1\n");
            } else if (c == (int16_t)c) {
                printf("2\n");
            } else if (c == (int32_t)c) {
                printf("4\n");
            }
        }
    }
    return 0;
}