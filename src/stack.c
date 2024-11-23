#include <stdio.h>
#include "calc.h"

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0;
double val[MAXVAL];

/* pop and return top value from stack */
double pop(void) {
	if (sp > 0) {
		return val[--sp];
	}

	else {
		printf("ERROR stack empty !\n");
		return 0.0;
	}
}

/* push f onto value stack */
void push(double f) {
	if (sp < MAXVAL) {
		val[sp++] = f;
	}

	else {
		printf("ERROR stack full can't push %g\n", f);
	}
}