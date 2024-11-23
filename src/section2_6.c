#include <stdio.h>
//#include <string.h>
#include <stdlib.h>

#include "section2_6.h"

int getlwoandor(char s[], int lim)
{
	enum loop { NO, YES};
	enum loop okloop = YES;

    int c, i;

    /*for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }*/

    while (okloop == YES) {
		if (i >= lim - 1) {
			okloop = NO;
		}
		else if ((c = getchar()) == '\n') {
			okloop = NO;
		}
		else if (c == EOF) {
			okloop = NO;
		}
		else {
			s[i] = c;
			++i;
		}
	}

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}