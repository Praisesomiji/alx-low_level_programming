#include <elf.h>
#include "main.h"

#if defined(__x86_64__)
typedef Elf64_Ehdr Elf_Ehdr; /* 64-bit machine */
#else
tcalculate the entry point of an ELF file:

"
entry_point = e_entry + shdr[PT_LOAD].p_vaddr
"

where:

e_entry is the entry point address from the ELF header
shdr[PT_LOAD] is the section header table entry for the PT_LOAD segment
p_vaddr is the virtual address of the PT_LOAD segmentypedef Elf32_Ehdr Elf_Ehdr; /* 32-bit machine */
#endif

void perror_exit(char *err_msg);
int is_elf(Elf_Ehdr *h);
int pelf_magic(Elf_Ehdr *h);
int pelf_class(Elf_Ehdr *h);
int pelf_data(Elf_Ehdr *h);
int pelf_version(Elf_Ehdr *h);
int pelf_osabi(Elf_Ehdr *h);
int pelf_abiv(Elf_Ehdr *h);
int pelf_type(Elf_Ehdr *h);
int pelf_entry(Elf_Ehdr *h);

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
	if (is_elf(h))
	{
		printf("Elf Header:\n");
		pelf_magic(h);
		pelf_class(h);
		pelf_data(h);
		pelf_version(h);
		pelf_osabi(h);
		pelf_abiv(h);
		pelf_type(h);
		pelf_entry(h);

		lseek(fd, h->e_ SEEK_SET);

	}
	else
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
 * is_elf - check if header is of an elf file
 * @h: pointer to elf file header
 *
 * Return: Boolean: True(1) OR False(0).
 */
int is_elf(Elf_Ehdr *h)
{
	unsigned char *e_ident = h->e_ident;

	if (e_ident[EI_MAG0] != ELFMAG0 ||
			e_ident[EI_MAG1] != ELFMAG1 ||
			e_ident[EI_MAG2] != ELFMAG2 ||
			e_ident[EI_MAG3] != ELFMAG3)
		return (0);
	return (1);
}
/**
 * pelf_magic - print Magic from the header of an elf file
 * @h: pointer to elf file header
 *
 * Return: Success (0).
 */
int pelf_magic(Elf_Ehdr *h)
{
 	unsigned int count = 0;

	printf(" Magic: ");

	for (count = 0; count < EI_NIDENT; count ++)
		printf("%02x ", h->e_ident[count]);

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
		class = "Invalid";

	printf(" Class:		%s\n", class);

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
		data = "Invalid";

	printf(" Data:		2's complement, %s\n", data);

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

	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" Version:	%d (current)\n", EV_CURRENT);
	else
		printf(" Version:	Invalid\n");

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
	char *osabi;

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			osabi = "System V";
			break;
		case ELFOSABI_HPUX:
			osabi = "HP-UX";
			break;
		case ELFOSABI_NETBSD:
			osabi = "NetBSD";
			break;
		case ELFOSABI_LINUX:
			osabi = "Linux";
			break;
		case ELFOSABI_SOLARIS:
			osabi = "Solaris";
			break;
		case ELFOSABI_AIX:
			osabi = "AIX";
			break;
		case ELFOSABI_IRIX:
			osabi = "IRIX";
			break;
		case ELFOSABI_FREEBSD:
			osabi = "FreeBSD";
			break;
		case ELFOSABI_TRU64:
			osabi = "TRU64 UNIX";
			break;
		case ELFOSABI_MODESTO:
			osabi = "Modesto";
			break;
		case ELFOSABI_OPENBSD:
			osabi = "Open BSD";
			break;
		default:
			printf(" OS/ABI:	<unknown: %d>", e_ident[EI_OSABI]);
			return (0);
	}

	printf(" OS/ABI:	UNIX - %s\n", osabi);

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

	printf(" ABI Version	%d\n", e_ident[EI_ABIVERSION]);

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
	unsigned int e_type = h->e_type;
	char *type;

	switch (e_type)
	{
		case ET_REL:
			type = "REL (Relocatable file)";
			break;
		case ET_NONE:
			type = "EXEC (Executable file)";
			break;
		case ET_EXEC:
			type = "EXEC (Executable file)";
			break;
		case ET_DYN:
			type = "DYN (Shared object file)";
			break;
		case ET_CORE:
			type = "Core file";
			break;
		case ET_LOPROC:
			type = "LOPROC (Processor-specific)";
			break;
		case ET_HIPROC:
			type = "HIPROC (Processor-specific)";
			break;
		default:
			type = "No file type";
	}

	printf(" Type:		%s\n", type);
	return (0);
}
/**
 * pelf_entry - print Entry Point Address info from an elf file header
 * @h: pointer to elf file header
 *
 * Return: Success (0).
 */
int pelf_entry(Elf_Ehdr *h)
{
	printf(" Entry point address:	0x%lx\n", h->e_entry);
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



