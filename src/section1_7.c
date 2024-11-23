/* Section 1.7 : Functions */
#include <stdio.h>
#include <stdlib.h>

int power(int base, int n) {
    int i, p;

    p = 1;

    for(i = 1; i <= n; ++i) {
        p = p * base;
    }

    return p;
}

void testpower(void) {
    int i;

    for (i = 0; i < 10; ++i) {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }
}

float celsius(float fahr) {
    return (5.0/9.0) * (fahr - 32.0);
}

void fahrcelrw(void) {
    float fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, celsius(fahr));
        fahr = fahr + step;
    }
}

