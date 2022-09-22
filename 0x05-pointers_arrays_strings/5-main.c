#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char s[10] = "My School";
    char s1[21] = "0 1 2 3 4 5 6 7 8 9 ";
    char s2[32] = "0 1 2 3 4 5 6 7 8 9 A B C D E F";

    printf("%s\n%s\n%s\n", s, s1, s2);
    rev_string(s);
    rev_string(s1);
    rev_string(s2);
    printf("%s\n%s\n%s\n", s, s1, s2);
    return (0);
}
