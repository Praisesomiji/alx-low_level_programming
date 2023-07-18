#include "main.h"

/**
 * create_file - creates a file
 * @filename: name of file to be created
 * @text_content: content to put in the new file
 *
 * Return: Success(1) or Failure(-1).
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int written;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC);
	if (fd < 0)
		return (-1);

	if (!text_content)
		return (1);

	written = write(fd, text_content, _strlen(text_content));
	if (written < 0)
		return (-1);

	return (1);
}

/**
 * _strlen - find the length of a string
 * @str: a string
 *
 * Return: The lenght of the string.
 */
size_t _strlen(char *str)
{
	int count;

	if (!str)
		return (0);

	count = 0;
	while (str[count])
		count++;

	return (count);
}
