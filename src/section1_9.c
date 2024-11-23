#include <stdio.h>
#include <stdlib.h>
#include "section1_9.h"

#define MAXLINE 1000
#define LONGLINE 80

int longestil(void)
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getl(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("%s", longest);
    }

    return 0;
}

int getl(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;

    i = 0;

    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}

/* Exercice 1-16 */

int longestil2(void) 
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getl2(line, MAXLINE)) > 0) {
        printf("%d, %s", len, line);
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("%s", longest);
    }

    return 0;
}

int getl2(char s[], int lim) 
{
    int c, i, j;

    j = 0;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 2) {
            s[j] = c;
            ++j;
        }
        
    }

    if (c == '\n') {
        s[j] = c;
        ++j;
        ++i;
    }

    s[i] = '\0';
    return i;
}

/* Exercice 1-17 */

int longestil3(void) 
{
    int len;
    char line[MAXLINE];

    while ((len = getl2(line, MAXLINE)) > 0) {
        if (len > LONGLINE) {
            printf("%s", line);
        }
    }

    return 0;
}

/* Exercice 1-18 */

int removebtbl(void)
{
    char line[MAXLINE];

    while (getl2(line, MAXLINE) > 0) {
        if (removel(line) > 0) {
            printf("%s", line);
        }
    }

    return 0;
}

int removel(char s[])
{
    int i;

    i = 0;

    while (s[i] != '\n') {
        ++i;
    }

    --i;

    while (i > 0 && (s[i] == ' ' || s[i] == '\t')) {
        --i;
    }

    if (i > 0) {
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }

    return i;
}

/* Exercice 1-19 */

void reversekr(void)
{
    char line[MAXLINE];

    while (getl(line, MAXLINE) > 0) {
        reversel(line);
        printf("%s", line);
    }
}

void reversel(char s[]) 
{
    int i, j;
    char temp;

    i = 0;
    while (s[i] != '\0') {
        ++i;
    }

    --i;

    if (s[i] == '\n') {
        --i;
    }

    j = 0;
    while (j < i) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        --i;
        ++j;
    }
}

