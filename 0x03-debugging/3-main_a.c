#include <stdio.h>

/* function prototypes */
int convert_day(int month, int day);
void print_remaining_days(int month, int day, int year);

/* main function */
int main(void)
{
	int month, day, year;

	printf("Enter a date in the format mm/dd/yyyy: ");
	scanf("%d/%d/%d", &month, &day, &year);

	day = convert_day(month, day);
	print_remaining_days(month, day, year);

	return (0);
}
