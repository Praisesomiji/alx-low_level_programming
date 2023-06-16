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

    p = _realloc(NULL, sizeof(char) * 30, sizeof(char) * 0);
    if (p == NULL)
    {
	    printf("p is NULL!\n");
    }
    else
    {
    	printf("len of p is %ld\n", strlen(p));
    	free(p);
    }
    return (0);
}
