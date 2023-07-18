#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: file path
 * @size: number of characters to read
 *
 * Return: Number of characters read.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buff;
	int written;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);

	buff = malloc(letters * sizeof(char));
	if (!buff)
		return (0);

	written = write(STDOUT_FILENO, buff, read(fd, buff, letters));
	if (written < letters)
		return (0);

	return (written);
}
