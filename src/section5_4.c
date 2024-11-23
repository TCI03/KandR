/* 5.4 Address arithmetic */

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

/* return pointer to n characters */
char *alloc(int n) {
	/* it fits */
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n; /* old p */
	}
	/* not enough room */
	else {
		return 0;
	}
}

/* free storage pointed to by p */
void afree(char *p) {
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
		allocp = p;
	}
}

int strlenkr(char *s) {
	int n;

	for (n = 0; *s != '\0'; s++) {
		n++;
	}

	return n;
}