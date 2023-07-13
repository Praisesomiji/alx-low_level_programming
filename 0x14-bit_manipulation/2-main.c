#include <stdio.h>
#include <limits.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int n;
    unsigned int sz = sizeof(n);

    printf("wordlen_in_bytes: %u\n", sz); 

    n = get_bit(1024, 10);
    printf("%d\n", n);
    n = get_bit(98, 1);
    printf("%d\n", n);
    n = get_bit(1024, 0);
    printf("%d\n", n);
    n = get_bit(10, 4);
    printf("%d\n", n);
    n = get_bit(ULONG_MAX, sz * 8);
    printf("%d\n", n);
    return (0);
}
