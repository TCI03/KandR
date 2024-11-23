/* External variables and scope */
#include <stdio.h>
#include "section1_10.h"

#define MAXLINE 1000
#define TABINC 8

int max;
char line[MAXLINE];
char longest[MAXLINE];

int longestilspe(void)
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = getlspe()) > 0) {
        if (len > max) {
            max = len;
            copyspe();
        }
    }

    if (max > 0) {
        printf("%s", longest);
    }

    return 0;
}

int getlspe(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

void copyspe(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0') {
        ++i;
    }
}

/* Exercise 1-20 */
void detab(void)
{
    int c, nb, pos;

    nb = 0;
    pos = 1;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            nb = TABINC - (pos - 1) % TABINC;
            while (nb > 0) {
                putchar(' ');
                ++pos;
                --nb;
            }
        }
        else if (c == '\n') {
            putchar(c);
            pos = 1;
        }
        else {
            putchar(c);
            ++pos;
        }
    }
}