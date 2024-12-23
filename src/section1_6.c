/* Section 1-6: Arrays */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXHIST 15
#define MAXWORD 11
#define MAXCHAR 128
#define IN 1
#define OUT 0

/* Exercise 1-13 */
void histo2(void) {
	int c, i, nc, state;
	int len;
	int maxvalue;
	int ovflow;
	int wl[MAXWORD];
	
	state = OUT;
	nc = 0;
	ovflow = 0;
	
	for (i = 0; i < MAXWORD; ++i) {
		wl[i] = 0;
	}
	
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if (nc > 0) {
				if (nc < MAXWORD) {
					++wl[nc];
				}
				else {
					++ovflow;
				}
			nc = 0;
			}
		}
		else if (state == OUT) {
			state = IN;
			nc = 1;	
		}
		else {
			++nc;
		}
	}
	
	maxvalue = 0;
	
	for (i = 1; i < MAXWORD; ++i) {
		if (wl[i] > maxvalue) {
			maxvalue = wl[i];
		}
	}
	
	for (i = 1; i < MAXWORD; ++i) {
		printf("%5d - %5d : ", i, wl[i]);
		if (wl[i] > 0) {
			if ((len = wl[i] * MAXHIST / maxvalue) <= 0) {
				len = 1;
			}
		}
		else {
			len = 0;
		}
		while (len > 0) {
			putchar('*');
			--len;
		}
		putchar('\n');
	}

	if (ovflow > 0) {
		printf("There are %d words >= %d\n", ovflow, MAXWORD);
	}

}

void histovert2(void) {
	int c, i, j, nc, state;
	int maxvalue;
	int ovflow;
	int wl[MAXWORD];

		state = OUT;
	nc = 0;
	ovflow = 0;
	
	for (i = 0; i < MAXWORD; ++i) {
		wl[i] = 0;
	}
	
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if (nc > 0) {
				if (nc < MAXWORD) {
					++wl[nc];
				}
				else {
					++ovflow;
				}
			nc = 0;
			}
		}
		else if (state == OUT) {
			state = IN;
			nc = 1;	
		}
		else {
			++nc;
		}
	}
	
	maxvalue = 0;
	
	for (i = 1; i < MAXWORD; ++i) {
		if (wl[i] > maxvalue) {
			maxvalue = wl[i];
		}
	}

	for (i = MAXHIST; i > 0; --i) {
		for (j = 1; j < MAXWORD; ++j) {
			if (wl[j] * MAXHIST / maxvalue >= i) {
				printf(" * ");
			}
			else {
				printf("   ");
			}
		}
		putchar('\n');
	}

	for (i = 1; i < MAXWORD; ++i) {
		printf("%2d ", i);
	}

	putchar('\n');

	for (i = 1; i < MAXWORD; ++i) {
		printf("%2d ", wl[i]);
	}

	putchar('\n');

	if (ovflow > 0) {
		printf("There are %d words >= %d\n", ovflow, MAXWORD);
	}
}

/* Exercise 1-14 */
void histofreq(void) {
	int c, i;
	int len;
	int maxvalue;
	int cc[MAXCHAR];

	for (i = 0; i < MAXCHAR; ++i) {
		cc[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c < MAXCHAR) {
			++cc[c];
		}
	}

	maxvalue = 0;

	for (i = 1; i < MAXCHAR; ++i) {
		if (cc[i] > maxvalue) {
			maxvalue = cc[i];
		}
	}

	for (i = 1; i < MAXCHAR; ++i) {
		if (isprint(i)) {
			printf("%5d - %c - %5d : ", i, i, cc[i]);
		}
		else {
			printf("%5d -  - %5d : ", i, cc[i]);
		}
		if (cc[i] > 0) {
			if ((len = cc[i] * MAXHIST / maxvalue) <= 0) {
				len = 1;
			}
		}
		else {
			len = 0;
		}
		while (len > 0) {
			putchar('*');
			--len;
		}
		putchar('\n');
	}
}