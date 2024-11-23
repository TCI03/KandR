/* Section 5.5: Character pointers and functions */

/* strcpy #1: copy t to s, array subscript version */
void strcpy1(char *s, char *t) {
	int i;

	i = 0;

	while ((s[i] = t[i]) != '\0') {
		i++;
	}
}

/* strcpy #2: copy t to s, pointer version 1 */
void strcpy2(char *s, char *t) {

	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}

void strcpy3(char *s, char *t) {

	while ((*s++ = *t++) != '\0') {
		;
	}
}

void strcpy4(char *s, char *t) {

	while (*s++ == *t++) {
		;
	}
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp1(char *s, char *t) {
	int i;

	for (i = 0; s[i] == t[i]; i++) {
		if (s[i] == '\0') {
			return 0;
		}
	}

	return s[i] - t[i];
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp2(char *s, char *t) {
	for ( ; *s == *t; s++, t++) {
		if (*s == '\0') {
			return 0;
		}
	}

	return *s - *t;
}