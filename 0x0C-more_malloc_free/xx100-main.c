#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - check the code for
 *
 * Return: Always 0.
 */
int main(void)
{
    char *p;

    p = malloc(sizeof(char) * 30);
    printf("0. len of p is %ld\n", strlen(p));
    p = _realloc(p, sizeof(char) * 30, sizeof(char) * 120);
    if (p == NULL)
    {
	    printf("p is NULL!\n");
    }
    else
    {
    	printf("1. len of p is %ld\n", strlen(p));
    	free(p);
    }
    return (0);
}
