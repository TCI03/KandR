#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <string.h>

#include "section4_3.h"

#define BUFSIZE 100
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
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
