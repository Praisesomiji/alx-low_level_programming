#include <elf.h>
#include "main.h"

#if defined(__x86_64__)
typedef Elf64_Ehdr Elf_Ehdr; /* 64-bit machine */
#else
typedef Elf32_Ehdr Elf_Ehdr; /* 32-bit machine */
#endif

void perror_exit(char *err_msg);
int pelf_magic(Elf_Ehdr *h);
int pelf_class(Elf_Ehdr *h);
int pelf_data(Elf_Ehdr *h);
int pelf_version(Elf_Ehdr *h);
int pelf_osabi(Elf_Ehdr *h);
int pelf_abiv(Elf_Ehdr *h);
int pelf_type(Elf_Ehdr *h);
int pelf_epad(Elf_Ehdr *h);

int main(int ac, char **av)
{
	int fd, sz;
	Elf_Ehdr *h;

	/* Check argument count */
	if (ac != 2)
		perror_exit("Usage: elf_header elf_file\n");

	/* Assign memory for header */
	sz = sizeof(*h);
	h = malloc(sz);
	if (!h)
		perror_exit("Error: Can't assign memory\n");

	/* Check argument count */
	if (ac != 2)
		perror_exit("Usage: elf_header elf_file\n");

	/* Open elf file */
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		perror_exit("Error: Can't open file\n");

	/* Read elf file */
	if (read(fd, h, sizeof(h)) < 0)
		perror_exit("Error: Can't read file\n");

	/* Print elf file header */
	if (pelf_magic(h) < 0 ||
			pelf_class(h) < 0 ||
			pelf_data(h) < 0 ||
			pelf_version(h) < 0 ||
			pelf_osabi(h) < 0 ||
			pelf_abiv(h) < 0 ||
			pelf_type(h) < 0 ||
			pelf_epad(h) < 0)
	{
		perror_exit("Error: Not a valid ELF file\n");
	}

	/* Close elf file */
	if (close(fd) < 0)
		perror_exit("Error: Can't close file\n");

	/* Free header */
	free(h);

	/* Return success */
	return (0);
}
/**
 * pelf_magic - print Magic from the header of an elf file
 * @h: pointer to elf file header
 *
 * Return: Success (0) OR Failure (-1).
 */
int pelf_magic(Elf_Ehdr *h)
{
	unsigned char *e_ident = h->e_ident;
	unsigned int count = 0;

	if (e_ident[EI_MAG0] != ELFMAG0 ||
			e_ident[EI_MAG1] != ELFMAG1 ||
			e_ident[EI_MAG2] != ELFMAG2 ||
			e_ident[EI_MAG3] != ELFMAG3)
		return (-1);

	printf("Magic:\t");

	for (count = 0; count < EI_NIDENT; count ++)
		printf("%02x ", e_ident[count]);

	printf("\n");

	return (0);
}
/**
 * pelf_class - print Class info from an elf file header
 * @h: pointer to elf file header
 *
 * Return: Success (0).
 */
int pelf_class(Elf_Ehdr *h)
{
	unsigned char *e_ident = h->e_ident;
	char *class;

	if (e_ident[EI_CLASS] == ELFCLASS32)
		class = "ELF32";

	else if (e_ident[EI_CLASS] == ELFCLASS64)
		class = "ELF64";

	else
		return (-1);

	printf("Class:\t\t\t\t%s\n", class);

	return (0);
}
/**
 * pelf_data - print Data info from an elf file header
 * @h: pointer to elf file header
 *
 * Return: Success (0).
 */
int pelf_data(Elf_Ehdr *h)
{
	unsigned char *e_ident = h->e_ident;
	char *data;

	if (e_ident[EI_DATA] == ELFDATA2LSB)
		data = "little endian";

	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		data = "big endian";

	else
		return (-1);

	printf("Data:\t\t\t\t2's complement, %s\n", data);

	return (0);
}
/**
 * pelf_version - print Version info from an elf file header
 * @h: pointer to elf file header
 *
 * Return: Success (0).
 */
int pelf_version(Elf_Ehdr *h)
{
	unsigned char *e_ident = h->e_ident;

	if (e_ident[EI_VERSION] != EV_CURRENT)
		return (-1);

	printf("Version:\t\t\t%d (current)\n", EV_CURRENT);

	return (0);
}
/**
 * pelf_osabi - print OS/ABI info from an elf file header
 * @h: pointer to elf file header
 *
 * Return: Success (0).
 */
int pelf_osabi(Elf_Ehdr *h)
{
	unsigned char *e_ident = h->e_ident;

        if (h && e_ident)
                return (0);
	return (0);
}
/**
 * pelf_abiv - print ABI Version info from an elf file header
 * @h: pointer to elf file header
 *
 * Return: Success (0).
 */
int pelf_abiv(Elf_Ehdr *h)
{
	unsigned char *e_ident = h->e_ident;

        if (h && e_ident)
                return (0);
	return (0);
}
/**
 * pelf_type - print Type info from an elf file header
 * @h: pointer to elf file header
 *
 * Return: Success (0).
 */
int pelf_type(Elf_Ehdr *h)
{
	unsigned char *e_ident = h->e_ident;

        if (h && e_ident)
                return (0);
	return (0);
}
/**
 * pelf_epad - print Entry Point Address info from an elf file header
 * @h: pointer to elf file header
 *
 * Return: Success (0).
 */
int pelf_epad(Elf_Ehdr *h)
{
	unsigned char *e_ident = h->e_ident;

        if (h && e_ident)
                return (0);
	return (0);
}	
/**
 * perror_exit - print error message and exit program
 * @err_msg: error message
 *
 * Return: Nothing.
 */
void perror_exit(char *err_msg)
{
	if (err_msg)
		write(STDERR_FILENO, err_msg, _strlen(err_msg) + 1);
	exit(98);
}
/**
 * _strlen - find the length of a string
 * @str: a string
 *
 * Return: Length of the string.
 */
size_t _strlen(char *str)
{
	unsigned int len = 0;

	if (str)
		while (str)
			len++;

	return (len);
}



