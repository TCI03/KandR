#include <stdio.h>

#include "section3_5.h"
#include "section3_6.h"

#define abs(x) ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0) {
        n = -n;
    }
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reversekr2(s);
}

/* Exercice 3-4 */
void itoa2(int n, char s[])
{
    int i, sign;

    sign = n;
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reversekr2(s);
}

/* Exercise 3-5 */
void itob(int n, char s[], int b)
{
    int i, j, sign;

    if ((sign = n) < 0) {
        n = -n;
    }

    i = 0;
    do {
        j = n % b;
        s[i++] = (j <= 9) ? j+'0' : j+'a'-10;
    } while ((n /= b) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reversekr2(s);
}

/* Exercice 3-6 */
void itoa3(int n, char s[], int w)
{
    int i, sign;

    sign = n;
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    while (i < w) {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reversekr2(s);
}
