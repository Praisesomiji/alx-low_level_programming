#include "main.h"

int copy_file(char *file_from, char *file_to);

/**
 * main - copies the content of a file to another file
 * @ac: number of arguments
 * @av: pointer to array of arguments
 *
 * Return: Success (0) or Error Code.
 */
int main(int ac, char **av)
{
	int res;

	/* if the number of args is not acccurate, exit with code 97 */
	if (ac != 3)
	{
		dprintf(STDOUT_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	res = copy_file(av[1], av[2]);
	if (res == 98)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(res);
	}
	if (res == 99)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		exit(res);
	}
	if (res > 100)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", res - 100);
		exit(100);
	}

	return (0);
}
/**
 * copy_file - copies the content of a file to another
 * @file_from: source file
 * @file_to: destination file
 *
 * Return: Success(0) or Error Code (98+).
 */
int copy_file(char *file_from, char *file_to)
{
	int fd[2];
	char buff[1024];
	int copied, i;

	/* if file_from doesnt exist, exit with code 98 */
	fd[0] = open(file_from, O_RDONLY);
	if (fd[0] < 0)
		return (1);

	/* if you cant create, exit with code 99 */
	fd[1] = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd[1] < 0)
		return  (2);

	copied = 0;
	do {
		/* if you can not read file_from, exit with code 98 */
		copied = read(fd[0], buff, 1024);
		if (copied < 0)
			return (98);

		/* if write to file_to fails, exit with code 99 */
		if (write(fd[1], buff, copied) < 0)
			return (99);
	} while (copied);

	/* if you cant close a file descriptor, exit with code 100 */
	for (i = 0; i < 2; i++)
	{
		if (close(fd[i]) < 0)
			return (fd[i] + 100);
	}

	return (0);
}
