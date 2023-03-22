#include <stdio.h>
#include "main.h"

/**
* main - takes a date and prints how many days are left in the year, taking
* leap years into account
* 
* Return: 0 (success).
*/

/* Function to convert month and day to the day of the year */
int convert_day(int month, int day)
{
	/* function implementation */
}

/* Function to print remaining days in year */
void print_remaining_days(int month, int day, int year)
{
	/* function implementation */
}
int main(void)
{
	int month;
	int day;
	int year;
	
	day = convert_day(month, day);
	print_remaining_days(month, day, year);
	
	month = 02;
	day = 29;
	year = 2000;

	printf("Date: %02d/%02d/%04d\n", month, day, year);

	day = convert_day(month, day);

	print_remaining_days(month, day, year);

	return (0);
}
