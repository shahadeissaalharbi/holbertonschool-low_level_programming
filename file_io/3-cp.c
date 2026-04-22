#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * open_files - opens source and destination files
 * @file_from: source file name
 * @file_to: destination file name
 * @fd_from: pointer to source file descriptor
 * @fd_to: pointer to destination file descriptor
 */
void open_files(char *file_from, char *file_to, int *fd_from, int *fd_to)
{
	*fd_from = open(file_from, O_RDONLY);
	if (*fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	*fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (*fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}
}

/**
 * copy_content - copies content from one fd to another
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @file_to: destination file name
 * @file_from: source file name
 */
void copy_content(int fd_from, int fd_to, char *file_to, char *file_from)
{
	char buf[1024];
	ssize_t r, w;

	while ((r = read(fd_from, buf, 1024)) > 0)
	{
		w = write(fd_to, buf, r);
		if (w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
	}
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
}

/**
 * main - copies content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	open_files(argv[1], argv[2], &fd_from, &fd_to);
	copy_content(fd_from, fd_to, argv[2], argv[1]);
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
	return (0);
}
