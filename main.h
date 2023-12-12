#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stringArray - Struct made up of an array of strings
 * @strings: The strings in array.
 * @count: size of array.
 *
 * Description: Structure of combination of a characters and strings
 */

typedef struct stringArray
{
	char **strings;
	int count;
} array;
extern char **environ;
array get_command(void);
void free_array(array *myarray);
int execute(array myarr);
int main(void);
int ptrenv(void);
ssize_t _getline(char **linptr, ssize_t *n, FILE *stream);
char *_strtok(char *str, const char *delim);
int compare(array com);
int directory(char *path);
char *_concat(char *dest, const char *src);
const char *_locate(const char *haystack, const char *needle);
char *copystring(const char *str);

#endif