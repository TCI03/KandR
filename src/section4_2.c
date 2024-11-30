#include <ctype.h>
#include <stdio.h>

#include "section4_1.h"
#include "section4_2.h"

#define MAXLINE 100

/* atof: convert string s to double */
double atof1(char s[])
{
	double val, power;
	int i, sign;
	
	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}

	return sign * val / power;
}

/* rudimentary calculator */
int rudcalc(void)
{
	double sum;
	char line[MAXLINE];

	sum = 0;
	
	while (getlinekr(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof1(line));

	return 0;
}

/* atoi: convert string s to integer using atof */
int atoikr(char s[])
{
	return (int) atof1(s);
}

/* Exercise4-2 */
double atof2(char s[])
{
	double val, power;
	int exp, i, sign;

	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}

	val = sign * val / power;

	if (s[i] == 'e' || s[i] == 'E') {
		sign = (s[++i] == '-') ? -1 : 1;

		if (s[i] == '+' || s[i] == '-')
			i++;

		for (exp = 0; isdigit(s[i]); i++)
			exp = 10 * exp + (s[i] - '0');

		if (sign == 1) {
			while (exp-- > 0)
				val *= 10;
		}

		else {
			while (exp-- > 0)
				val /= 10;
		}
	}
	return val;

}