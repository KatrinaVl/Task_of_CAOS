#include <stdint.h>
#include <stdio.h>

void normalize_path(char *buf) {
    char *l = buf;
    char *r = buf;
    while (*r != '\0') {
        if (*r == '/') {
            *l = '/';
            ++l;
            while (*r == '/') {
                ++r;
            }
        } else {
            *l = *r;
            ++l;
            ++r;
        }
    }
    *l = '\0';
}

// int main(void) {
//     char buf[] = "/////a//////bgfcgf/////c///cgh///";
//     normalize_path(buf);
//     printf("%s\n", buf);
//     printf("\n");
//     return 0;
// }