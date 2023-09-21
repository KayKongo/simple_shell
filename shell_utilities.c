#include "shell.h"

/**
 * Authors: Joycelyn Arhin
 * 	      Prince Kongo
 *
 * Description:
 * This file contains extended functions used in main.c.
 */

/**
 * parse_command - Determines the type of the command.
 * @command: Command to be parsed.
 *
 * Return: Constant representing the type of the command:
 * - EXTERNAL_COMMAND (1) for commands like /bin/ls.
 * - INTERNAL_COMMAND (2) for commands like env, exit
 * - PATH_COMMAND (3) for commands found in the PATH like ls.
 * - INVALID_COMMAND (-1) for invalid commands.
 */
int parse_command(char *command)
{
    int i;
    char *internal_command[] = {"env", "exit", NULL};
    char *path = NULL;

    for (i = 0; command[i] != '\0'; i++)
    {
        if (command[i] == '/')
            return (EXTERNAL_COMMAND);
    }

    for (i = 0; internal_command[i] != NULL; i++)
    {
        if (_strcmp(command, internal_command[i]) == 0)
            return (INTERNAL_COMMAND);
    }

    /* Check if the command is found in the PATH */
    path = check_path(command);
    if (path != NULL)
    {
        free(path);
        return (PATH_COMMAND);
    }

    return (INVALID_COMMAND);
}

/**
 * execute_command - Executes a command based on its type.
 * @tokenized_command: Tokenized form of the command.
 * @command_type: Type of the command.
 *
 * Return: void.
 */
void execute_command(char **tokenized_command, int command_type)
{
    void (*func)(char **command);

    if (command_type == EXTERNAL_COMMAND)
    {
        if (execve(tokenized_command[0], tokenized_command, NULL) == -1)
        {
            perror(_getenv("PWD"));
            exit(2);
        }
    }
    if (command_type == PATH_COMMAND)
    {
        if (execve(check_path(tokenized_command[0]), tokenized_command, NULL) == -1)
        {
            perror(_getenv("PWD"));
            exit(2);
        }
    }
    if (command_type == INTERNAL_COMMAND)
    {
        func = get_func(tokenized_command[0]);
        func(tokenized_command);
    }
    if (command_type == INVALID_COMMAND)
    {
        print(shell_name, STDERR_FILENO);
        print(": 1: ", STDERR_FILENO);
        print(tokenized_command[0], STDERR_FILENO);
        print(": not found\n", STDERR_FILENO);
        status = 127;
    }
}

/**
 * check_path - Checks if a command is found in the PATH.
 * @command: Command to be checked.
 *
 * Return: Path leading to the command, or NULL if not.
 */
char *check_path(char *command)
{
    char **path_array = NULL;
    char *temp, *temp2, *path_cpy;
    char *path = _getenv("PATH");
    int i;

    if (path == NULL || _strlen(path) == 0)
        return (NULL);

    path_cpy = malloc(sizeof(*path_cpy) * (_strlen(path) + 1));
    _strcpy(path, path_cpy);
    path_array = tokenizer(path_cpy, ":");

    for (i = 0; path_array[i] != NULL; i++)
    {
        temp2 = _strcat(path_array[i], "/");
        temp = _strcat(temp2, command);
        if (access(temp, F_OK) == 0)
        {
            free(temp2);
            free(path_array);
            free(path_cpy);
            return (temp);
        }
        free(temp);
        free(temp2);
    }

    free(path_cpy);
    free(path_array);
    return (NULL);
}

/**
 * get_func - Retrieves a function based on the provided command and  mapping.
 * @command: String to check against the mapping.
 *
 * Return: Pointer to the proper function, or NULL if there is a failure.
 */
void (*get_func(char *command))(char **)
{
    int i;
    function_map mapping[] = {
        {"env", env}, {"exit", quit}
    };

    for (i = 0; i < 2; i++)
    {
        if (_strcmp(command, mapping[i].command_name) == 0)
            return (mapping[i].func);
    }

    return (NULL);
}

/**
 * _getenv - Gets the value of an environment variable.
 * @name: Name of the environment variable.
 *
 * Return: The value of the variable as a string.
 */
char *_getenv(char *name)
{
    char **my_environ;
    char *pair_ptr;
    char *name_cpy;

    for (my_environ = environ; *my_environ != NULL; my_environ++)
    {
        for (pair_ptr = *my_environ, name_cpy = name;
             *pair_ptr == *name_cpy; pair_ptr++, name_cpy++)
        {
            if (*pair_ptr == '=')
                break;
        }
        if ((*pair_ptr == '=') && (*name_cpy == '\0'))
            return (pair_ptr + 1);
    }

    return (NULL);
}

