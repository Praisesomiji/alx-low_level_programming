/**
 * _strlen - returns the length of a string
 * @s: a string
 *
 * Return: always an integer
 */
int _strlen(char *s)
{
	int l = 0;

	while (*(s + l) != \0)
	{
		l++;
	}
	return l;
}
