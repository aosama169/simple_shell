#include "main.h"

/**
 *ptrenv - prints list of environment in the current directory
 *
 *Return: always a zero
 */
int ptrenv(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (0);
}