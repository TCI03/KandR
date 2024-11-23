/*Section 1.2: Variables and arithmetic expressions */
#include <stdio.h>

void fahrcel(void) {
	int fahr, cel;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	while (fahr <= upper) {
		cel = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, cel);
		fahr = fahr + step;
	}
}

/* Float version */
void fahrcel2(void) {
	float fahr, cel;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	while (fahr <= upper) {
		cel = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f\t%6.1f\n", fahr, cel);
		fahr = fahr + step;
	}
}

/* Exercise 1-3 */
void fahrcel3(void) {
	float fahr, cel;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	printf("Fahr Celsius\n");
	while (fahr <= upper) {
		cel = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f  %6.1f\n", fahr, cel);
		fahr = fahr + step;
	}
}

/* Exercise 1-4 */
void celfahr(void) {
	float fahr, cel;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	cel = lower;

	printf("Celsius Fahr\n");
	while (cel <= upper) {
		fahr = 9.0 * cel / 5.0 + 32.0;
		printf("%3.0f  %6.1f\n", cel, fahr);
		cel = cel + step;
	}
}