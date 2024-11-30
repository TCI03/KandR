#include <stdio.h>

#include "section4_1.h"

#define MAXLINE 1000 /* maximum input line length */

/* find all lines matching pattern */
int findpattern(void)
{
	char pattern[] = "ould"; /* pattern to search for */
	char line[MAXLINE];
	int found = 0;
	
	while (getlinekr(line, MAXLINE) > 0) {
		if (strindexkr(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	}

	return found;
}

/* getline: get line into s, return length */
int getlinekr(char s[], int lim)
{
	int c, i;
	i = 0;

	while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}

	s[i] = '\0';

	return i;
}

/* strindex: return index of t in s, -1 if none */
int strindexkr(char s[], char t[])
{
	int i, j, k;
	
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++) {
			;
		}

		if (k > 0 && t[k] == '\0') {
			return i;
		}
	}

	return -1;
}

/* Exercise 4-1 */
/* strindex: return index of t in s, -1 if none */
int strindex2(char s[], char t[])
{
	int i, j, k, pos;
	
	pos = -1;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
			;
		}

		if (k > 0 && t[k] == '\0') {
			pos = i;
		}
	}

	return pos;
}