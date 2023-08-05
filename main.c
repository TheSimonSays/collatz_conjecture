#include <stdio.h>
#include <stdbool.h>

#define CACHE_SIZE 1000000


int cache[CACHE_SIZE] = {0};

typedef struct {
    int value;
    int steps;
} CollatzInfo;

void printCollatzInfo(const CollatzInfo *info) {
    printf("%d (steps: %d)\n", info->value, info->steps);
}

unsigned int collatz(int n) {
    return (n & 1) ? (3 * n + 1) : (n >> 1);
}


unsigned int cacheCollatz(int n) {
    if (n < CACHE_SIZE && cache[n] != 0) {
        return cache[n];
    }

    int result = collatz(n);

    if (n < CACHE_SIZE) {
        cache[n] = result;
    }

    return result;
}

int main() {
    int num = 100;

    CollatzInfo sequence[1000];

    int count = 0;

    while (num != 1) {
        sequence[count].value = num;
        sequence[count].steps = cacheCollatz(num);
        count++;
        num = sequence[count - 1].steps;
    }

    printf("Sequence:\n");
    for (int i = 0; i < count; i++) {
        printCollatzInfo(&sequence[i]);
    }

    return 0;
}
