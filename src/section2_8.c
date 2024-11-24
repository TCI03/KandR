#include <stdio.h>

#include "section2_8.h"

/* strcat: concatenate t to end of s; s must be big enough */
void strcatkr(char s[], char t[])
{
	int i, j;

	i = j = 0;

	while (s[i] != '\0') { /* find end of s */
		i++;
	}
	
	while ((s[i++] = t[j++]) != '\0') { /* copy t */
		;
	}
}

void squeezealt(char s1[], char s2[])
{
	int i, j, k;

	for (i = k = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++) {
			;
		}

		if (s2[j] == '\0') {
			s1[k++] = s1[i];
		}
	}

	s1[k] = '\0';
}

int anykr(char s1[], char s2[])
{
	int i, j;

	for (i = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0'; j++) {
			if (s1[i] == s2[j]) {
				return i;
			}
		}
	}

	return -1;
}