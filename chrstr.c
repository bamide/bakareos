#include "main.h"

char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (char *)s;
		++s;
	}

	if (c == '\0')
		return (char *)s;
	return (NULL);
}
