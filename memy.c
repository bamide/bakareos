#include "main.h"

void *_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char *dest_ptr;
	const unsigned char *src_ptr = (const unsigned char *)src;
	size_t i;

	if (dest == NULL || src == NULL)
		return NULL;

	dest_ptr = (unsigned char *)dest;

	for (i = 0; i < size; i++)
		dest_ptr[i] = src_ptr[i];

	return (dest);
}
