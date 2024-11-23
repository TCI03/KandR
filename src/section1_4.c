/* Section 1.4: Symbolic Constants */
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void fahrcelsc(void) {
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
		printf("%d\t%f\n", fahr, (5.0 / 9.0) * (fahr - 32));

	}
}