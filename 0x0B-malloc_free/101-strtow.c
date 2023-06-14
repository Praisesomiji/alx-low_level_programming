#include <stdio.h>
#include <stdlib.h>

int wordend(int cur, char *str);
int wordstrt(int cur, char *str);
int *strglen(char *str);

/**
 * stetow - splits a string into words
 * @str: a string
 *
 * Return: a pointer to an array of strings.
 */
char **strtow(char *str)
{
	int length, wordcount;
	int start, end;
	int i, j, k;
	int *sizes;
	char *word;
	char **words;

	if (!str)
	{
		return (NULL);
	}

	sizes = strglen(str);
	wordcount = sizes[1];
	words = malloc(sizeof(char *) * wordcount + 1);
	if (words == NULL)
	{
		return (NULL);
	}

	for (i = 0, k = 0; i < wordcount && k < length; i++, k++)
	{
		start = wordstrt(k, str);
		end = wordend(start, str);
		charcount = end - start;
		if (charcount > 0)
		{
			words[i] = malloc(sizeof(char) * charcount + 1);
			if (words[i] == NULL)
			{
				for(; i >=0; --i)
				{
					free(words[i]);
				}
				free(words);
				return (NULL);
			}
			for (j = 0, k = start; j < charcount && k < end; j++, k++)
			{
				words[i][j] = str[k];
			}
		}
	}
	return (words);
}

/**
 * wordend - finds the end of a word
 * @cur: index of the char to start search
 * @str: a string
 *
 * Return: the index of the next space char.
 */
int wordend(int cur, char *str)
{
        int nxt;

        nxt = cur;
        while (str[nxt] != ' ' || str[nxt] != '\n')
        {
                nxt++;
        }
        return (nxt);
}

/**
 * wordstrt - finds the next nonspace char in a string
 * @cur: index of the char to start search
 * @str: a string
 *
 * Return: the index of the next nonspace char.
 */
int wordstrt(int cur, char *str)
{
	int nxt;

	nxt = cur;
	while (str[nxt] == " ")
	{
		nxt++;
		if (str[nxt] == '\n')
		{
			return (NULL);
		}
	}
	return (nxt);
}

/**
 * strglen - counts the number of chars in a string of words
 * @str: a string
 *
 * Return: the lenght of a string and number of relevant gaps.
 */
int *strglen(char *str)
{
        int len;
        int gap;
	int gcount;
	int *result;

        len = 0;
	gap = 0;
	gcount = 0;
        while (str[len] != '\0')
        {
		len++;
                if (str == " ")
                {
			if (gap == 0)
			{
				gcount++;
				gap = 1;
			}
        	}
		else
		{
			gap = 0;
		}

	result[0] = len;
	result[1] = gap;

        return (result);
}
