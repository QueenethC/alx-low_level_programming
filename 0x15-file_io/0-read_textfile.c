#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- To read txt file print to STDOUT,
 * @filename: The text files being read
 * @letters: For numbr of leters to be read,
 * Return: w- The actual numbr of bytes read or printed
 *        and 0 when a function fail or filename is NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}
