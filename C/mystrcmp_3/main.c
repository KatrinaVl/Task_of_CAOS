#include <stdint.h>
#include <stdio.h>

int mystrcmp(const char *str1, const char *str2) {
  unsigned char *s1 = (unsigned char *)str1;
  unsigned char *s2 = (unsigned char *)str2;
  for (; *s1 != 0 && *s2 != 0; s1++, s2++) {
    if (*s1 != *s2) {
      return *s1 - *s2;
    }
  }
  return *s1 - *s2;
}

int main(void) {
    const char* a = "hell11\0";
    const char* b = "hell1\0";
    printf("%d\n", mystrcmp(a, b));
}