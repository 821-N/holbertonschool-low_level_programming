#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/**
 * read_textfile - read and print contents of a file
 * @filename: name of file
 * @letters: maximum number of chars to read
 * Return: number of chars read.
 *  If an error occurs, returns 0
 * ehehehehe
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *data;
	int fd;
	ssize_t written;

	if (!filename)
		return (0);

	data = malloc(letters);
	if (!data)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		written = 0;
		goto free;
	}
	written = read(fd, data, letters);
	close(fd);

	if (written < 0)
	{
		written = 0;
		goto free;
	}

	if (write(STDOUT_FILENO, data, written) != written)
	{
		written = 0;
		goto free;
	}

free:
	free(data);
	return (written);
}
