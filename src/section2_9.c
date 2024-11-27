#include <stdio.h>

#include "section2_9.h"

unsigned getbitskr(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

/* Exercise 2-6 */
unsigned setbitskr(unsigned x, int p, int n, unsigned y)
{
    return x & ~(~(~0 << n) << (p + 1 - n)) | (y & ~(~0 << n)) << (p + 1 - n);
}

/* Exercise 2-7 */
unsigned invertkr(unsigned x, int p, int n)
{
    return x ^ ~((~0 << n) << (p + 1 - n)) ;
}

/* Exercise 2-8 */
unsigned rightrotkr(unsigned x, int n)
{
    while (n-- > 0) {
        rbit = (x & 1) << (wordlength() - 1);
        x = x >> 1;
        x = x | rbit;
    }

    return x;
}

int wordlength(void)
{
    int i;
    unsigned v = (unsigned) ~0;

    for (i = 1; (v = v >> 1) > 0; i++) {
        ;
    }

    return i;
}