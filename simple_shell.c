#include "main.h"

/**
 * main - Main Start Point for the program.
 * @void: Parameter of the program.
 *
 * Return: Zero if successfull
 */

int main(void)
{
	array argv;
	int i, j;

	i = 0;
	while (i == 0)
	{
		printf(":) ");
		argv = get_command();
		j = compare(argv);
		switch (j)
		{
		case 0:
			execute(argv);
			free_array(&argv);
			break;
		case 1:
			exit(0);
		case 2:
			ptrenv();
			break;
		case 3:
			directory(argv.strings[1]);
			break;
		}
	}
	free_array(&argv);
	return (0);
}