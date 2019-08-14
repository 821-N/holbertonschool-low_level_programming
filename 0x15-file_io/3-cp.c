#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * copy_file - copy data from one file to another
 * @source_fd: source file descriptor, assumed to be valid
 * @sourcename: source file name (for error message)
 * @dest_fd: destination dile descriptor, assumed valid
 * @destname: destination filename
 */
void copy_file(int source_fd, char *sourcename, int dest_fd, char *destname)
{
	char buffer[1024];
	ssize_t amount;

	while (1)
	{
		amount = read(source_fd, buffer, sizeof(buffer));
		if (amount == 0)
			break;
		if (amount < 0)
		{
			close(source_fd);
			close(dest_fd);
			dprintf(STDERR_FILENO, "Error: can't read from file %s\n", sourcename);
			exit(98);
		}
		if (write(dest_fd, buffer, amount) < amount)
		{
			close(source_fd);
			close(dest_fd);
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", destname);
			exit(99);
		}
	}
}

/**
 * main - main
 * @argc: number of args
 * @argv: args
 * Return: exit code
 */
int main(int argc, char **argv)
{
	int source_fd, dest_fd;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	source_fd = open(argv[1], O_RDONLY, 0664);
	if (source_fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}
	dest_fd = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT);
	if (dest_fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(source_fd);
		return (99);
	}
	copy_file(source_fd, argv[1], dest_fd, argv[2]);
	if (close(source_fd))
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_fd);
		close(dest_fd);
		return (100);
	}
	if (close(dest_fd))
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_fd);
		return (100);
	}
	return (0);

}
