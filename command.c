#include "main.h"

/*
 * handleCommandLineArguments - Print command-line arguments to standard output.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 */
void handleCommandLineArguments(int argc, char *argv[]) {
    int i; /* Declare the loop variable at the beginning */

    if (argc > 1) {
        write(STDOUT_FILENO, "Command-line arguments:\n", 24);

        for (i = 1; i < argc; i++) {
            char buffer[256];
            int length = sprintf(buffer, "Argument %d: %s\n", i, argv[i]);
            write(STDOUT_FILENO, buffer, length);
        }
    }
}

