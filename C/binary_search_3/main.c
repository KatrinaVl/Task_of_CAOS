#include <stdio.h>
#include <stdlib.h>

struct BSearchResult {
    size_t low;
    size_t high;
    int result;
};

struct BSearchResult
bsearch2(const void *key, const void *base, size_t nmemb, size_t size,
         int (*compar)(const void *p1, const void *p2, void *user),
         void *user) {
    struct BSearchResult res = {0};
    if (nmemb == 0) {
        return res;
    }
    int64_t l = -1;
    int64_t r = (int64_t)nmemb;
    while (l < r - 1) {
        int64_t m = (l + r) / 2;
        if (compar(base + m * size, key, user) < 0) {
            l = m;
        } else {
            if (compar(base + m * size, key, user) == 0) {
                res.result = 1;
            }
            r = m;
        }
    }
    res.low = r;
    l = -1;
    r = (int64_t)nmemb;
    while (l < r - 1) {
        int64_t m = (l + r) / 2;
        if (compar(base + m * size, key, user) <= 0) {
            l = m;
        } else {
            r = m;
        }
    }
    res.high = l + 1;

    return res;
}