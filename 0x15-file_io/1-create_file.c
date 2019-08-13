#include <unistd.h>
#include <fcntl.h>

/**
 * create_file - create a file and write a string to it
 * @filename: name
 * @text_content: string
 * Return: 1 = good, -1 = bad
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t length;
	ssize_t written;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd < 0)
		return (-1);

	if (text_content)
	{
		for (length = 0; text_content[length]; length++)
			;
		written = write(fd, text_content, length);
		if (written != length)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
