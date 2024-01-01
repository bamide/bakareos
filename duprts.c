#include "main.h"

char *_strdup(const char* str)
{
	size_t len;
	char *dup;

	if (str == NULL)
		return NULL;

	len = strlen(str) + 1;
	dup = malloc(len);

	if (dup == NULL)
		return NULL;

	_memcpy(dup, str, len);

	return dup;
}
