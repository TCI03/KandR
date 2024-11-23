/*Section 1.3: The for statement */
#include <stdio.h>

void fahrcelfor(void) {
	int fahr;
		
	for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
		printf("%d\t%f\n", fahr, (5.0 / 9.0) * (fahr - 32));

	}
}

void fahrcelrev(void) {
	int fahr;

	for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
		printf("%d\t%f\n", fahr, (5.0 / 9.0) * (fahr - 32));

	}
}