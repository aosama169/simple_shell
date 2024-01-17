#include "main.h"

/**
 * free_array - Function to free memory of an array.
 * @myarray: Pointer to array to be freed.
 *
 * Return: Void.
 */

void free_array(array *myarray)
{
	int i;

	if (myarray == NULL)
		return;
	if (myarray->strings)
	{
		for (i = 0; i < myarray->count; i++)
		{
			free(myarray->strings[i]);
		}
		free(myarray->strings);
		myarray->strings = NULL;
	}
	myarray->count = 0;
}
