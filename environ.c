#include "main.h"

/**
 * env_variable - reads envrionment varibles of the system and searches for the
 *		  PATH varialbe
 *
 * @env: array containing the environment variables
 *
 * Return: return the PATH environment variable if found
 *	   return NULL if PATH variable is empty or not found
*/

char *get_path(char **env)
{
	char *path, *path_dup;

	if (env == NULL)
		return (NULL);

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);

	path_dup = _strdup(path);

	return (path_dup);
}
