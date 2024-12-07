#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <string.h>

#include "section4_3.h"

#define BUFSIZE 100
#define MAXOP 100 /* max size of operand or operator */
#define NAME 'n' /* signal that a name was found */
#define NUMBER '0' /* signal that a number was found */
#define MAXLINE 100
#define MAXVAL 100 /* maximum depth of val stack */

/* reverse Polish calculator */
int revpolishcalc(void)
{
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';

	if (!isdigit(c) && c != '.')
		return c; /* not a number */
	
	i = 0;
	
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	
	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	
	s[i] = '\0';
	
	if (c != EOF)
		ungetch(c);
	
	return NUMBER;
}

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

/* Exercise 4-3 */
int revpolishcalc2(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop2(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0) {
				push(fmod(pop(), op2));
			}
			else {
				printf("error: zero divisor\n");
			}
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

int getop2(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && c != '.' && c != '-')
		return c; /* not a number */

	if (c == '-') {
		if (isdigit(c = getch()) || c == '.') {
			s[++i] = c;
		}
		else {
			if (c != EOF) {
				ungetch(c);
			}
			return '-';
		}
	}

	if (isdigit(c)) {
		while (isdigit(s[i++] = c = getch())) {
			;
		}
	}

	if (c == '.') {
		while (isdigit(s[i++] = c = getch())) {
			;
		}
	}

	s[i] = '\0';

	if (c != EOF) {
		ungetch(c);
	}

	return NUMBER;
}

/* Exercise 4-4 */

int revpolishcalc3(void)
{
	int type;
	double op1, op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '?': /* print top element of the stack */
			op2 = pop();
			printf("\t%.8g\n", pop());
			push(op2);
			break;
		case 'c': /* clear the stack */
			clear();
			break;
		case 'd': /* duplicate top element of the stack */
			op2 = pop();
			push(op2);
			push(op2);
			break;
		case 's': /* swap the top two elements */
			op1 = pop();
			op2 = pop();
			push(op1);
			push(op2);
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

void clear(void)
{
	sp = 0;
}

/* Exercice 4-5 */

int revpolishcalc4(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop3(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case NAME:
			mathfnc(s);
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

/* check string s for supported math functions */
void mathfnc(char s[])
{
	double op2;

	if (strcmp(s, "sin") == 0) {
		push(sin(pop()));
	}
	else if (strcmp(s, "cos") == 0) {
		push(cos(pop()));
	}
	else if (strcmp(s, "exp") == 0) {
		push(exp(pop()));
	}
	else if (strcmp(s, "pow") == 0) {
		op2 = pop();
		push(pow(pop(), op2));
	}
	else {
		printf("error : %s not supported\n", s);
	}
}

/* get next operator, numeric operand or math function */
int getop3(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';
	i = 0;

	if (islower(c)) {
		while (islower(s[i++] = c = getch())) {
			;
		}

		s[i] = '\0';

		if (c != EOF) {
			ungetch(c);
		}

		if (strlen(s) > 1) {
			return NAME;
		}
		else {
			return c;
		}
	}

	if (!isdigit(c) && c != '.')
		return c; /* not a number */

	if (isdigit(c)) { /* collect integer part */
		while (isdigit(s[++i] = c = getch())) {
			;
		}
	}

	if (c == '.') { /* collect fraction part */
		while (isdigit(s[++i] = c = getch())) {
			;
		}
	}

	s[i] = '\0';

	if (c != EOF) {
		ungetch(c);
	}

	return NUMBER;
}

/* Exercise 4-6 */

int revpolishcalc5(void)
{
	int i, type, var = 0;
	double op2, v;
	char s[MAXOP];
	double variable[26];

	for (i = 0; i <26; i++) {
		variable[i] = 0.0;
	}

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '=':
			pop();
			if (var >= 'A' && var <= 'Z') {
				variable[var - 'A'] = pop();
			}
			else {
				printf("error: no variable name\n");
			}
			break;
		case '\n':
			v = pop();
			printf("\t%.8g\n", v());
			break;
		default:
			if (type >= 'A' && type <= 'Z') {
				push(variable[type - 'A']);
			}
			else if (type == 'v') {
				push(v);
			}
			else {
				printf("error: unknown command %s\n", s);
			}
			break;
		}

		var = type;
	}
	return 0;
}

/* Exercise 4-7 */

/* push string back onto the input */
void ungets(char s[])
{
	int len = strlen(s);

	while (len > 0) {
		ungetch(s[--len]);
	}
}

/* Exercise 4-8 */

char buf2 = 0;

int getch2(void)
{
	int c;

	if (buf2 != 0) {
		c = buf2;
	}
	else {
		c = getchar();
	}

	buf2 = 0;

	return c;
}

void ungetch2(int c)
{
	if (buf2 != 0) {
		printf("ungetch2: too many characters\n");
	}
	else {
		buf2 = c;
	}
}

/* Exercise 4-9 */

int buf3[BUFSIZE];

int getch3(void)
{
	return (bufp > 0) ? buf3[--bufp] : getchar();
}

void ungetch3(int c)
{
	if (bufp >= BUFSIZE) {
		printf("ungetch3: too many characters\n");
	}
	else {
		buf3[bufp++] = c;
	}
}

/* Exercise 4-10 */

int li = 0;
char line[MAXLINE];

int getop4(char s[])
{
	int c, i;

	if (line[li] == '\0') {
		if (getline(line, MAXLINE) == 0) {
			return EOF;
		}
		else {
			li = 0;
		}
	}

	while ((s[0] = c = line[li++]) == ' ' || c == '\t') {
		;
	}

	s[1] = 0;

	if (!isdigit(c) && c != '.') {
		return c;
	}

	i = 0;

	if (isdigit(c)) {
		while (isdigit(s[++i] = c = line[li++])) {
			;
		}
	}

	if (c == '.') {
		while (isdigit(s[++i] = c = line[li++])) {
			;
		}
	}

	s[i] = '\0';
	li--;

	return NUMBER;
}
