#include "main.h"

/**
 * directory - Function change s current directory to directory
 * specified in path.
 * @path: Path to directory.
 *
 * Return: If successful 0, else -1 if error.
 */
int directory(char *path)
{
	int changed;

	strcat(path, "/");
	changed = chdir(path);
	if (changed != 0)
		perror("(");
	return (0);
}
