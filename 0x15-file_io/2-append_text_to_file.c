#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: file path
 * @text_content: text to append to file
 *
 * Return: Succcess(1) or Failure(-1).
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;

	if (!filename)
		return (-1);
	if (!text_content)
		return (1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd < 0)
		return (-1);

	if (write(fd, text_content, _strlen(text_content)) < 0)
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
	size_t count;

	if (!str)
		return (0);

	count = 0;
	while (str[count])
		count++;

	return (count);
}
