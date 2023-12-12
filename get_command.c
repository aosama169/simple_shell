#include "main.h"
/**
 * get_command - Function to retrieve command.
 * @void: Parameter of the program.
 *
 * Return: Array.
 */
array get_command(void)
{
	array arr;
	size_t n;
	int command, i, j;
	char *cmd = NULL, *cmd_cpy = NULL, *token = NULL, *delim = " \n";

	arr.count = 0;
	command = getline(&cmd, &n, stdin);
	if (command == -1)
		exit(1);

	cmd_cpy = strdup(cmd);
	for (token = strtok(cmd, delim); token; arr.count++)
		token = strtok(NULL, delim);

	arr.strings = malloc(sizeof(char *) * (arr.count + 1));
	if (arr.strings == NULL)
	{
		free(cmd);
		free(cmd_cpy);
		perror("error");
		exit(1);
	}
	token = strtok(cmd_cpy, delim);
	for (i = 0; token && i < arr.count; i++)
	{
		arr.strings[i] = strdup(token);
		if (arr.strings[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(arr.strings[j]);
			free(arr.strings);
			free(cmd);
			free(cmd_cpy);
		}
		token = strtok(NULL, delim);
	}
	arr.strings[i] = NULL;
	free(cmd);
	free(cmd_cpy);
	return (arr);
}
