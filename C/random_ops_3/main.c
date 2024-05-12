#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

enum { A = 1103515245 };

enum { C = 12345 };

enum { MOD = 1 << 31 };

typedef struct RandomGenerator RandomGenerator;
typedef struct RandomOperations RandomOperations;

typedef struct RandomGenerator {
    uint32_t curr_num;
    RandomOperations *ops;
} RandomGenerator;

static uint32_t next(RandomGenerator *ops) {
    ops->curr_num = (A * ops->curr_num + C) % MOD;
    return ops->curr_num;
}

static void destroy(RandomGenerator *o) {
    free(o->ops);
    free(o);
}

typedef struct RandomOperations {
    void (*destroy)(RandomGenerator *ops);
    uint32_t (*next)(RandomGenerator *ops);
} RandomOperations;

RandomGenerator *random_create(int seed) {
    RandomGenerator *it = calloc(1, sizeof(*it));
    it->ops = calloc(1, sizeof(*(it->ops)));
    it->ops->destroy = destroy;
    it->ops->next = next;
    it->curr_num = seed;
    return it;
}
