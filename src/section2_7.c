#include <stdio.h>

#include "section2_7.h"

#define YES 1
#define NO 0

/* atoi: convert s to integer */
int atoi(char s[])
{
	int i, n;
	
	n = 0;
	
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
		n = 10 * n + (s[i] - '0');
	}

	return n;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
	if (c >= 'A' && c <= 'Z') {
		return c + 'a' - 'A';
	}
	else {
		return c;
	}
}

/* Exercise 2-3 */
int htoi(char s[])
{
	int hexdigit, i, inhex, n;

	i = 0;

	if (s[i] == 0) {
		++i;
		if (s[i] == 'x' || s[i] == 'X') {
			++i;
		}
	}

	n = 0;
	inhex = YES;
	for ( ; inhex == YES; ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			hexdigit = s[i] - '0';
		}
		else if (s[i] >= 'a' && s[i] <= 'f') {
			hexdigit = s[i] - 'a' + 10;
		}
		else if (s[i] >= 'A' && s[i] <= 'F') {
			hexdigit = s[i] - 'A' + 10;
		}
		else {
			inhex = NO;
		}

		if (inhex == YES) {
			n = 16 * n + hexdigit;
		}
	}

	return n;
}

/* squeeze: delete all c from s */
void squeezekr(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++) {
		if (s[i] != c) {
			s[j++] = s[i];
		}
	}

	s[j] = '\0';
}
