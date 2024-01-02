#include "main.h"

/**
 * main - Entry point
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
 char **token_array;
 char *line = NULL;
 char *token;
 int i, status;
 pid_t child_pid;
 ssize_t nread;
 size_t len = 0;

 (void)argc;
 (void)argv;

 while (1)
 {
  write(STDOUT_FILENO, "#MayBaksMshell$ ", 9);
  nread = getline(&line, &len, stdin);
  if (nread == -1)
  {
   perror("Error: Failed to read input");
   exit(EXIT_FAILURE);
  }

  if (nread == 1)
   continue;

  token_array = malloc(sizeof(char *) * MAX_TOKENS);
  if (token_array == NULL)
  {
   perror("Error: Failed to allocate memory");
   exit(EXIT_FAILURE);
  }

  token = strtok(line, DELIM);
  i = 0;
  while (token && i < MAX_TOKENS - 1)
  {
   token_array[i] = token;
   token = strtok(NULL, DELIM);
   i++;
  }
  token_array[i] = NULL;

  if (strcmp(token_array[0], "cd") == 0)
  {
   if (token_array[1] == NULL)
   {
    fprintf(stderr, "Error: Missing argument for cd\n");
   }
   else if (chdir(token_array[1]) != 0)
   {
    perror("Error: Failed to change directory");
   }
  }
  else if (strcmp(token_array[0], "exit") == 0)
  {
   break;
  }
  else
  {
   child_pid = fork();
   if (child_pid == -1)
   {
    perror("Error: Failed to create process");
    exit(EXIT_FAILURE);
   }
   else if (child_pid == 0)
   {
    if (execvp(token_array[0], token_array) == -1)
    {
     perror("Error: Failed to execute command");
     exit(EXIT_FAILURE);
    }
   }
   else
   {
    wait(&status);
   }
  }

  free(token_array);
 }

 free(line);
 return (0);
}

