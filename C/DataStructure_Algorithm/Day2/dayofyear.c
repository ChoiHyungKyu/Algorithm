#include <stdio.h>

int mdays[][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };

int isleap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int dayofyear(int y, int m, int d) {
	int i;
	int days = d;
	for (i = 1; i < m; i++)
		days += mdays[isleap(y)][i - 1];
	return days;
}

int main(void) {
	int year, month, day;
	int retry;
	do {
		printf("Y: "); scanf_s("%d", &year);
		printf("M: "); scanf_s("%d", &month);
		printf("D: "); scanf_s("%d", &day);
		printf("%d Year %dth days.\n", year, dayofyear(year, month, day));
		printf("Retry?(1:Yes, 2:No)>> "); scanf_s("%d", &retry);
	} while (retry == 1);
	return 0;
}