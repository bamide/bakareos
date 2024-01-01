#include "main.h"

char *_strtok(char *str, const char *delim)
{
	static char *saved_ptr = NULL;
	char *token;

	if (str == NULL)
	{
		str = saved_ptr;
	}

	while (*str != '\0' && _strchr(delim, *str) != NULL)
	{
		str++;
	}

	if (*str == '\0')
	{
		saved_ptr = NULL;
		return (NULL);
	}

	token = str;
	while (*str != '\0' && _strchr(delim, *str) == NULL)
	{
		str++;
	}

	if (*str != '\0')
	{
		*str = '\0';
		saved_ptr = str + 1;
	}
	else
	{
		saved_ptr = str;
	}

	return (token);
}
