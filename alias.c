#include "main.h"

Alias *alias_list = NULL;

void write_output(const char *output) {
    write(STDOUT_FILENO, output, strlen(output));
}

void print_aliases() {
    Alias *current = alias_list;
    while (current != NULL) {
        write(STDOUT_FILENO, current->name, strlen(current->name));
        write(STDOUT_FILENO, "='", 2);
        write(STDOUT_FILENO, current->value, strlen(current->value));
        write(STDOUT_FILENO, "'\n", 2);
        current = current->next;
    }
}

Alias *find_alias(char *name) {
    Alias *current = alias_list;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void add_alias(char *name, char *value) {
    Alias *existing_alias = find_alias(name);
    if (existing_alias != NULL) {
        free(existing_alias->value);
        existing_alias->value = strdup(value);
    } else {
        Alias *new_alias = malloc(sizeof(Alias));
        if (new_alias == NULL) {
            perror("Error: Failed to allocate memory for alias");
            exit(EXIT_FAILURE);
        }
        new_alias->name = strdup(name);
        new_alias->value = strdup(value);
        new_alias->next = alias_list;
        alias_list = new_alias;
    }
}

void free_aliases() {
    Alias *current = alias_list;
    while (current != NULL) {
        Alias *next = current->next;
        free(current->name);
        free(current->value);
        free(current);
        current = next;
    }
}

