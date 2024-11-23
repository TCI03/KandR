/* External variables and scope */
#include <stdio.h>
#include "section1_10.h"

#define MAXCOL 10
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

/* Exercise 1-21 */
void repblanks(void)
{
    int c, nb, nt, pos;

    nb = 0;
    nt = 0;

    for (pos = 1; (c = getchar()) != EOF; ++pos) {
        if (c == ' ') {
            if (pos && TABINC != 0) {
                ++nb;
            }
            else {
                nb = 0;
                ++nt;
            }
        }
        else {
            for ( ; nt > 0; --nt) {
                putchar('\t');
            }

            if (c == '\t') {
                nb = 0;
            }
            else {
                for ( ; nb > 0; --nb) {
                    putchar(' ');
                }
            }
            putchar(c);
            if (c == '\n') {
                pos = 0;
            }
            else if (c == '\t') {
                pos = pos + (TABINC - (pos - 1) % TABINC) - 1;
            }
        }
    }
}

/* Exercise 1-22 */

char line4[MAXCOL];

void foldlil(void)
{
    int c, pos;

    while ((c = getchar()) != EOF) {
        line4[pos] = c;
        if (c == '\t') {
            pos = exptab(pos);
        }
        else if (c == '\n') {
            printl(pos);
            pos = 0;
        }
        else if (++pos >= MAXCOL) {
            pos = findblnk(pos);
            printl(pos);
            pos = newpos(pos);
        }
    }
}

void printl(int pos)
{
    int i;

    for (i = 0; i < pos; ++i) {
        putchar(line[i]);
    }

    if (pos > 0) {
        putchar('\n');
    }
}

int exptab(int pos)
{
    line[pos] = ' ';
    for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos) {
        line[pos] = ' ';
    }

    if (pos < MAXCOL) {
        return pos;
    }
    else {
        printl(pos);
        return 0;
    }
}

int findblnk(int pos)
{
    while (pos > 0 && line[pos] != ' ') {
        --pos;
    }

    if (pos == 0) {
        return MAXCOL;
    }
    else {
        return pos+1;
    }
}

int newpos(int pos)
{
    int i, j;

    if (pos <= 0 || pos >= MAXCOL) {
        return 0;
    }
    else {
        i = 0;
        for (j = pos; j < MAXCOL; ++j) {
            line[i] = line[j];
            ++i;
        }

        return i;
    }
}

/* Exercise 1-23 */

int removecom(void)
{
    int c;

    while ((c = getchar()) != EOF) {
        rcomment(c);
    }

    return 0;
}

void rcomment(int c)
{
    int d;

    if (c == '/') {
        if ((d = getchar()) == '#') {
            in_comment();
        }
        else if (d == '/') {
            putchar(c);
            rcomment(d);
        }
        else {
            putchar(c);
            putchar(d);
        }
    }
    else if (c == '\'' || c == '"') {
        echo_quote(c);
    }
    else {
        putchar(c);
    }
}

void in_comment(void)
{
    int c, d;

    c = getchar();
    d = getchar();

    while (c != '#' || d != '/') {
        c = d;
        d = getchar();
    }
}

void echo_quote(int c)
{
    int d;

    putchar(c);
    while ((d = getchar()) != c) {
        putchar(d);
        if (d == '\\') {
            putchar(getchar());
        }
    }

    putchar(d);
}

/* Exercise 1-24 */

int brace, brack, paren;

void checksyntax(void)
{
    int c;

    extern int brace, brack, paren;
    while ((c = getchar()) != EOF) {
        if (c == '/') {
            if ((c = getchar()) == '#') {
                in_comment();
            }
            else {
                search(c);
            }
        }
        else if (c == '\'' || c == '"') {
            in_quote(c);
        }
        else {
            search(c);
        }

        if (brace < 0) {
            printf("Unbalanced braces\n");
            brace = 0;
        }
        else if (brack < 0) {
            printf("Unbalanced brackets\n");
            brack = 0;
        }
        else if (paren < 0) {
            printf("Unbalanced parentheses\n");
            paren = 0;
        }

        if (brace > 0) {
            printf("Unbalanced braces\n");
        }
        else if (brack > 0) {
            printf("Unbalanced brackets\n");
        }
        else if (paren > 0) {
            printf("Unbalanced parentheses\n");
        }
    }
}

void search(int c)
{
    extern int brace, brack, paren;

    if (c == '{') {
        ++brace;
    }
    else if (c == '}') {
        --brace;
    }
    if (c == '[') {
        ++brack;
    }
    else if (c == ']') {
        --brack;
    }
    if (c == '(') {
        ++paren;
    }
    else if (c == ')') {
        --paren;
    }
}

void in_quote(int c)
{
    int d;

    while ((d = getchar()) != c) {
        if (d == '\\') {
            getchar();
        }
    }
}