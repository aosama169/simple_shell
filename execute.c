#include "main.h"
/**
 * execute - A Function to execute commands
 * @myarr: Array of commands to be executed
 *
 * Return: Zero.
 */
int execute(array myarr)
{
	char *exe[100], cat[200] = "/bin/", exe_path[200];
	int counter, runCount;
	pid_t myPid;

	if (strstr(myarr.strings[0], cat) != NULL)
		exe[0] = myarr.strings[0];

	else
	{
		strcpy(exe_path, cat);
		strcat(exe_path, myarr.strings[0]);
		exe[0] = strdup(exe_path);
	}
	for (counter = 1; myarr.strings[counter] != NULL; counter++)
		exe[counter] = myarr.strings[counter];

	exe[counter] = NULL;
	myPid = fork();
	if (myPid == -1)
		perror("Can not create a Process\n");

	if (myPid  == 0)
	{
		runCount = execve(exe[0], exe, NULL);
		if (runCount == -1)
		{
			perror(")");
			free(exe[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
	if (strcmp(exe[0], cat) == 0)
		free(exe[0]);

	exe[0] = NULL;
	return (0);
}
