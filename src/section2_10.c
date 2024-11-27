#include <stdio.h>

#include "section2_10.h"

int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x >>= 1) {
        if (x & 01) {
            b++;
        }
    }

    return b;
}

/* Exercice 2-9 */
int bitcount2(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= x~1) {
        ++b;
    }

    return b;
}