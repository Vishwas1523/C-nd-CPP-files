#include <stdio.h>

#define ARRSIZE(arr) (sizeof(arr) / sizeof(arr[0]))

enum Fruit_t {
    APPLES,
    ORANGES,
    STRAWBERRIES = 8,
    MANGOES = 3
};

int main()
{
    static const int price_lookup[] = {
        [APPLES] = 6,
        [ORANGES] = 10,
        [MANGOES] = 77,
        [STRAWBERRIES] = 55
    };

    for (int i = 0; i < ARRSIZE(price_lookup); ++i) {
        printf("[%d] = %d\n", i, price_lookup[i]);
    }

    return 0;
}