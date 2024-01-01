#include "main.h"

void execute_command(char **token_array);

void set_environment_variable(char **token_array)
{
    /* Check for missing arguments */
    if (token_array[1] == NULL || token_array[2] == NULL)
    {
        fprintf(stderr, "Error: Missing arguments for setenv\n");
    }
    /* Set environment variable */
    else if (setenv(token_array[1], token_array[2], 1) != 0)
    {
        perror("Error: Failed to set environment variable");
    }
}

void unset_environment_variable(char **token_array)
{
    /* Check for missing argument */
    if (token_array[1] == NULL)
    {
        fprintf(stderr, "Error: Missing argument for unsetenv\n");
    }
    /* Unset environment variable */
    else if (unsetenv(token_array[1]) != 0)
    {
        perror("Error: Failed to unset environment variable");
    }
}

void execute_command(char **token_array)
{
    int status;
    pid_t child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error: Failed to create process");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0)
    {
        /* Execute command */
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

