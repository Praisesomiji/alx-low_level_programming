#include "main.h"
#include <elf.h>

#define EI_NIDENT 16

/**
 * Elf32_Ehdr - Elf header structure
 * @e_ident: marks the file as an object file
 * @e_type: identifies the object file type
 * @e_machine: specifies required architecture for an individual file
 * @e_version: identifies the object file version
 * @e_entry: gives virtual address to which the system transfers control
 * @e_phoff: holds the program header table’s file offset in bytes
 * @e_shoff: holds the section header table’s file offset in bytes
 * @e_flags:  holds processor-specific flags associated with the file
 * @e_ehsize: holds the ELF header’s size in bytes
 * @e_phentsize: holds the size in bytes of one entry in the file’s program header table
 * @e_phnum:  holds the number of entries in the program header table
 * @e_shentsize: holds a section header’s size in bytes
 * @e_shnum: holds the number of entries in the section header table
 */
typedef struct{
	unsigned char e_ident[EI_NIDENT];
	Elf32_Half e_type;
	Elf32_Half e_machine;
	Elf32_Word e_version;
	Elf32_Addr e_entry;
	Elf32_Off e_phoff;
	Elf32_Off e_shoff;
	Elf32_Word e_flags;
	Elf32_Half e_ehsize;
	Elf32_Half e_phentsize;
	Elf32_Half e_phnum;
	Elf32_Half e_shentsize;
	Elf32_Half e_shnum;
	Elf32_Half e_shstrndx;
} Elf32_Ehdr;

/**
 * Elf64_Ehdr - Elf Header Structure
 * Description: For 64 its machine
 */
typedef struct {
	unsigned char e_ident[EI_NIDENT];
	Elf64_Half e_type;
	Elf64_Half e_machine;
	Elf64_Word e_version;
	Elf64_Addr e_entry;
	Elf64_Off e_phoff;
	Elf64_Off e_shoff;
	Elf64_Word e_flags;
	Elf64_Half e_ehsize;
	Elf64_Half e_phentsize;
	Elf64_Half e_phnum;
	Elf64_Half e_shentsize;
	Elf64_Half e_shnum;
	Elf64_Half e_shstrndx;
} Elf64_Ehdr;

typedef struct {
	unsigned char e_ident[EI_NIDENT];
	uint16_t      e_type;
	uint16_t      e_machine;
	uint32_t      e_version;
	ElfN_Addr     e_entry;
	ElfN_Off      e_phoff;
	ElfN_Off      e_shoff;
	uint32_t      e_flags;
	uint16_t      e_ehsize;
	uint16_t      e_phentsize;
	uint16_t      e_phnum;
	uint16_t      e_shentsize;
	uint16_t      e_shnum;
	uint16_t      e_shstrndx;
} ElfN_Ehdr;

/* ELF Identification Indexes */
#define EI_MAG0 0	/* File identification */
#define EI_MAG1 1	/* File identification */
#define EI_MAG2 2	/* File identification */
#define EI_MAG3 3	/* File identification */
#define EI_CLASS 4	/* File class */
#define EI_DATA 5	/* Data encoding */
#define EI_VERSION 6	/* FIle version */
#define EI_OSABI 7	/* Operating system/ABI identification */
#define EI_ABIVERSION 8	/* ABI version */
#define EI_PAD 9	/* Start of padding bytes */
#define EI_NIDENT 16	/* Size of e_ident[] */

/* These indexes access bytes that hold the values described below */

/* ELF Identification Values */
/* Magic */
#define ELFMAG0 0X7F	/* e_ident[EI_MAG0] */
#define ELFMAG1 'E'	/* e_ident[EI_MAG1] */
#define ELFMAG2 'L'	/* e_ident[EI_MAG2] */
#define ELFMAG3 'F'	/* e_ident[EI_MAG3] */

/* Class e_ident[EI_CLASS] */
#define ELFCLASSNONE 0	/* Invalid class */
#define ELFCLASS32 1	/* 32-bit objects */
#define ELFCLASS64 2	/* 64-bit objects */

/* Data e_ident[EI_DATA] */
#define ELFDATANONE 0	/* Invalid data encoding */
#define ELFDATA2LSB 1	/* 2's complement, little endian */
#define ELFDATA2MSB 2	/* 2's complement, big endian */

/* OS/ABI e_ident[EI_OSABI] */
#define ELFOSABI_SYSV 0	/* UNIX System V */
#define ELFOSABI_HPUX 1	/* HP-UX */
#define ELFOSABI_NETBSD 2	/* NetBSD */
#define ELFOSABI_LINUX 3	/* Linux */
#define ELFOSABI_SOLARIS 6	/* Solaris */
#define ELFOSABI_AIX 7	/* AIX */
#define ELFOSABI_IRIX 8	/* IRIX */
#define ELFOSABI_FREEBSD 9	/* FreeBSD */
#define ELFOSABI_TRU64 10	/* TRU64 UNIX */
#define ELFOSABI_MODESTO 11	/* Novell Modesto */
#define ELFOSABI_OPENBSD 12	/* Open BSD */
#define ELFOSABI_OPENVMS 13	/* Open VMS */
#define ELFOSABI_NSK 14	/* Hewlett-Packard Non-Stop Kernel */

/* ELF Type e_type */
#define ET_NONE 0	/* No file type */
#define ET_REL 1	/* Relocatable file */
#define ET_EXEC 2	/* Executable file */
#define ET_DYN 3	/* Shared object file */
#define ET_CORE 4	/* Core file */
#define ET_LOOS 0xfe00	/* Operating system-specific */
#define ET_HIOS 0xfeff	/* Operating system-specific */
#define ET_LOPROC 0xff00	/* Processor-specific */
#define ET_HIPROC 0xffff	/* Processor-specific */

/* ELF Version e_version */
#define EV_NONE 0	/* Invalid version */
#define EV_CURRENT 1	/* Current version */

ELFOSABI_NONE        Same as ELFOSABI_SYSV
                          ELFOSABI_SYSV        UNIX System V ABI
                          ELFOSABI_HPUX        HP-UX ABI
                          ELFOSABI_NETBSD      NetBSD ABI
                          ELFOSABI_LINUX       Linux ABI
                          ELFOSABI_SOLARIS     Solaris ABI
                          ELFOSABI_IRIX        IRIX ABI
                          ELFOSABI_FREEBSD     FreeBSD ABI
                          ELFOSABI_TRU64       TRU64 UNIX ABI
                          ELFOSABI_ARM         ARM architecture ABI
                          ELFOSABI_STANDALONE  Stand-alone  (embedded)
                                               ABI/**
 * display_elfinfo - displays info in the header of an ELF file
 */

/**
 * main - displays the information contained in the ELF header at the start of an ELF file
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: Success(0).
 */
int main(int ac, char **av)
{

}

