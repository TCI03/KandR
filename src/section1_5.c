/* Section 1-5: Character input and output */
#include <stdio.h>
#include <stdlib.h>

#define MAXHIST 15
#define MAXWORD 11
#define IN 1
#define OUT 0

void gpchar(void) {
	int c;

	while ((c = getchar()) != EOF) {
		putchar(c);
	}
}

/* Exercise 1.6 */
void getcharval(void) {
	int c;

	while ((c = getchar()) != EOF) {
		printf("%d\n", c);
	}
	printf("EOF - %d\n", c);
}

/*Exercise 1.7 */
void eofvalue(void) {
	printf("EOF is %d\n", EOF);
}

void charcount(void) {
	long nc;

	nc = 0;

	while (getchar() != EOF) {
		++nc;
	}
	printf("%ld\n", nc);
}

void charcountfor(void) {
	double nc;

	for (nc = 0; getchar() != EOF; ++nc) {
		;
	}
	printf("%.0f\n", nc);
}

void countlines(void) {
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			++nl;
		}
	}
	printf("%d\n", nl);
}

void histo() {
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

void histovert(void) {
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
