#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: file path
 * @letters: number of characters to read
 *
 * Return: Number of characters read.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buff;
	ssize_t written;

	/* if filename is NULL return 0 */
	if (!filename)
		return (0);

	/* if the file can not be opened or read, return 0 */
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);

	buff = malloc(letters * sizeof(char));
	if (!buff)
		return (0);

	/* if write fails or doesnt write expected no of bytes, return 0 */
	written = write(STDOUT_FILENO, buff, read(fd, buff, letters));

	free(buff);
	close(fd);

	/* returns the actual number of letters it could read and print */
	return (written);
}
