#include <stdio.h>
#include <stdlib.h>

int wordend(int cur, char *str);
int wordstrt(int cur, char *str);
int *strglen(char *str);

/**
 * strtow - splits a string into words
 * @str: a string
 *
 * Return: a pointer to an array of strings.
 */
char **strtow(char *str)
{
	int length, wordcount;
	int start, end, charcount;
	int i, j, k;
	int *sizes;
	char **words;

	if (!str)
	{
		return (NULL);
	}

	sizes = strglen(str);
	length = sizes[0];
	wordcount = sizes[1];
	free(sizes);
	if (length == 0)
	{
		return (NULL);
	}

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
				for (; i >= 0; --i)
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
	while (str[nxt] == ' ')
	{
		nxt++;
		if (str[nxt] == '\n')
		{
			return (-1);
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
	int gapcount;
	int wrdcount;
	int *result;

	len = 0;
	gap = 0;
	gapcount = 0;
	wrdcount = 0;
	while (str[len] != '\0')
	{
		len++;
		if (str[len] == ' ')
		{
			gapcount++;
			if (gap == 0)
			{
				wrdcount++;
				gap = 1;
			}
		}
		else
		{
			gap = 0;
		}

	}
	result = malloc(sizeof(int) * 2);
	if (len == gapcount)
	{
		result[0] = 0;
	}
	else
	{
		result[0] = len;
	}
	result[1] = wrdcount;

	return (result);
}
