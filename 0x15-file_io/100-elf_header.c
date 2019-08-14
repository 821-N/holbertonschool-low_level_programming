#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef EV_CURRENT
#define EV_CURRENT 1
#endif

/**
 * get_header - open and get header of ELF file
 * @filename: name of file to load
 * @magic: array to store magic data
 */
void get_header(char *filename, unsigned char *magic)
{
	int fd = open(filename, O_RDONLY);
	ssize_t length;

	if (fd < 0)
	{
		write(STDERR_FILENO, "Could not open file\n", 20);
		exit(98);
	}

	length = read(fd, magic, 0x18 + 8);
	if (length < 0)
	{
		write(STDERR_FILENO, "Could not read from file\n", 25);
		goto fail;
	}
	if (length != 0x18 + 8)
	{
		write(STDERR_FILENO, "File too short\n", 15);
		goto fail;
	}

	if (magic[0] != 0x7F || magic[1] != 'E' || magic[2] != 'L' || magic[3] != 'F')
	{
		write(STDERR_FILENO, "Not an ELF file\n", 16);
		goto fail;
	}
	close(fd);
	return;
fail:
	close(fd);
	exit(98);
}

/**
 * print_type - print ELF type
 * @type: type
 */
void print_type(int type)
{
	printf("  Type:                              ");
	if (type == 0)
		printf("NONE (none)");
	else if (type == 1)
		printf("REL (Relocatable file)");
	else if (type == 2)
		printf("EXEC (Executable file)");
	else if (type == 3)
		printf("DYN (Shared object file)");
	else if (type == 4)
		printf("CORE (Core file)");
	else if (type >= 0xFE00)
		printf("OS Specific: (%x)", type);
	else
		printf("<unknown>: %x", type);
	printf("\n");
}

/**
 * print_stuff - print endian, version, os, abi
 * @endian: endian
 * @version: version
 * @os: os
 * @abi: abi
 * Return: 0 = LE, 1 = BE
 */
int print_stuff(int endian, int version, int os, int abi)
{
	char *os_names[] = {
		"UNIX - System V", "UNIX - HP-UX", "UNIX - NetBSD", "UNIX - GNU"
	};

	printf("  Data:                              ");
	int be = 0;

	if (endian == 0)
		printf("none\n");
	else if (endian == 1)
		printf("2's complement, little endian\n");
	else if (endian == 2)
	{
		printf("2's complement, big endian\n");
		be = 1;
	}
	else
		printf("<unknown: %x>\n", endian);

	printf("  Version:                           ");
	if (version < EV_CURRENT)
		printf("%d", version);
	else if (version == EV_CURRENT)
		printf("%d (current)", version);
	/* could improve optimization if EV_CURRENT passed to printf */
	else
		printf("%d <unknown: %%lx>", version);
	printf("\n");
	/* OS/ABI */
	printf("  OS/ABI:                            ");
	if (os < 4)
		printf("%s", os_names[os]);
	else
		printf("<unknown: %x>", os);
	printf("\n");
	/* ABI version */
	printf("  ABI Version:                       ");
	printf("%x\n", abi);
	return (be);
}

/**
 * print_class - get/print 32 or 64 bit option
 * @class: class
 * Return: number of chars in pointer
 */
int print_class(int class)
{
	printf("  Class:                             ");
	if (class == 0)
		printf("none\n");
	else if (class == 1)
		printf("ELF32\n");
	else if (class == 2)
	{
		printf("ELF64\n");
		return (8);
	}
	else
		printf("<unknown: %x>\n", class);
	return (4);
}

/**
 * main - main
 * @argc: argc
 * @argv: argv
 * Return: exit code
 */
int main(int argc, char **argv)
{
	unsigned char magic[0x18 + 8];
	int i;
	int be = 0;
	int epsize = 4;
	size_t entry = 0;

	if (argc != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header filename\n", 27);
		return (98);
	}
	get_header(argv[1], magic);
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < 16; i++)
		printf("%02x ", magic[i]);
	printf("\n");
	epsize = print_class(magic[4]); /* Class (32 or 64 bit) */
	be = print_stuff(magic[5], magic[6], magic[7], magic[8]);
	/* Type */
	if (be)
		print_type(magic[0x11] | magic[0x10] << 8);
	else
		print_type(magic[0x10] | magic[0x11] << 8);
	/* Entry Point Address */
	if (be)
		for (i = 0; i < epsize; i++)
			entry = entry << 8 | magic[0x18 + i];
	else
		for (i = epsize - 1; i >= 0; i--)
			entry = entry << 8 | magic[0x18 + i];
	printf("  Entry point address:               0x%lx\n", entry);
}
