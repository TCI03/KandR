#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "section4_10.h"

/* printd: print n in decimal */
void printd(int n)
{
	if (n < 0) {
		putchar('-');
		n = -n;
	}

	if (n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsortkr(int v[], int left, int right)
{
	int i, last;
	if (left >= right) /* do nothing if array contains */
		return; /* fewer than two elements */
	swap1(v, left, (left + right)/2); /* move partition elem */
	last = left; /* to v[0] */
	for (i = left + 1; i <= right; i++) /* partition */
		if (v[i] < v[left])
			swap1(v, ++last, i);
	swap1(v, left, last); /* restore partition elem */
	qsortkr(v, left, last-1);
	qsortkr(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap1(int v[], int i, int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* Exercise 4-12 */

void itoarec(int n, char s[])
{
	static int i;

	if (n / 10) {
		itoarec(n / 10, s);
	}
	else {
		i = 0;

		if (n < 0) {
			s[i++] = '-';
		}
	}

	s[i++] = abs(n) % 10 + '0';
	s[i] = '\0';
}

/*Exercise 4-13 */

void reverse(char s[])
{
	reverser(s, 0, strlen(s));
}

void reverser(char s[], int i, int len)
{
	int c, j;

	j = len - (i + 1);

	if (i < j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		reverser(s, ++i, len);
	}
}
