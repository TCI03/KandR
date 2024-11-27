#include <stdio.h>
#include <ctype.h>

#include "section3_5.h"

int atoi2(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++) {
        ;
    }

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    for (n = 0; isdigit(s[i]); i++) {
        n = 10 * n +(s[i] - '0');
    }

    return sign * n;
}

void shellsortkr(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j-=gap) {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}

void reversekr(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* Exercise 3-3 */
void expandkr(char s1[], char s2[])
{
    char c;
    int i, j;

    i = j = 0;

    while((c = s1[i++]) != '\0') {
        if (s1[i] == '-' && s1[i+1] >= c) {
            i++;
            while (c < s1[i]) {
                s2[j++] = c++;
            }
        }
        else {
            s2[j++] = c;
        }
    }

    s2[j] = '\0';
}