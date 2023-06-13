#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * close_file - To close file descriptors,
 * @fd: the file descriptor to close,
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - To allocate 1024 bytes for the buffer,
 * @file: The name of file buffer that storing chars is for,
 *
 * Return: the pnter for the new buffer allocated.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * main - to copy all the contents of a file to another file,
 * @argc: The total number of arguments supplied for the program,
 * @argv: The arrays of pointers for the arguments,
 *
 * Return: 0 as success
 *
 * Description: If the total argument count is incorrect - exit code 97.
 * If the file_from does not exit or cannot be read - exit code 98.
 * If the file_to cannot be created or written to - exit code 99.
 * If the file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
