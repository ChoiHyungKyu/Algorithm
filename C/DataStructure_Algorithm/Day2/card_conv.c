#include <stdio.h>

int card_convr(unsigned x, int n, char d[]) {
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;
	if (x == 0)
		d[digits++] = dchar[0];
	else
		while (x) {
			d[digits++] = dchar[x % n];
			x /= n;
		}
	return digits;
}

int main(void) {
	int i;
	unsigned no;
	int cd;
	int dno;
	char cno[512];
	int retry;
	puts("Convert to decimal");
	do {
		printf("Unsigned Integer value(for decimal): ");
		scanf_s("%u", &no);
		do {
			printf("What do you want to convert value?(2-36): ");
			scanf_s("%d", &cd);
		} while (cd < 2 || cd>36);
		dno = card_convr(no, cd, cno);
		printf("[%d-mode] ", cd);
		for (i = dno - 1; i >= 0; i--)
			printf("%c", cno[i]);
		printf("\nRetry? (1-yes, 0-no): ");
		scanf_s("%d", &retry);
	} while (retry == 1);
	return 0;
}