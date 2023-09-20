#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/**
 * environ - array of pointers to environment variables
 * signal - set a signal handler function
 */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/**
 * checker - checks if a command is a built-in or an external command
 * @cmd: array of command arguments
 * @buf: buffer for user input
 * Return: 1 if built-in, 0 if external command
 */
int checker(char **cmd, char *buf);

/**
 * prompt_user - display the shell prompt for user input
 */
void prompt_user(void);

/**
 * handle_signal - handles signals received by the shell
 * @m: signal number
 */
void handle_signal(int m);

/**
 * tokenizer - tokenizes a string into an array of tokens
 * @line: input string to tokenize
 * Return: pointer to an array of tokens
 */
char **tokenizer(char *line);

/**
 * test_path - checks if a command is in one of the directories in PATH
 * @path: array of directory paths in PATH
 * @command: command to search for
 * Return: full path to the command if found, NULL otherwise
 */
char *test_path(char **path, char *command);

/**
 * path_append - appends a command to a directory path
 * @path: directory path
 * @command: command to append
 * Return: new string with appended path and command
 */
char *path_append(char *path, char *command);

/**
 * handle_builtin - handles built-in commands
 * @command: array of command arguments
 * @line: input line
 * Return: 1 if built-in command was executed, 0 otherwise
 */
int handle_builtin(char **command, char *line);

/**
 * exit_cmd - handles the 'exit' built-in command
 * @command: array of command arguments
 * @line: input line
 */
void exitc(char **command, char *line);

/**
 * print_env - prints the environment variables
 */
void print_env(void);

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if strings are equal, positive/negative value if not
 */
int _strcmp(char *s1, char *s2);

/**
 * _strlen - calculates the length of a string
 * @s: input string
 * Return: length of the string
 */
int _strlen(char *s);

/**
 * _strncmp - compares two strings up to a specified number of characters
 * @s1: first string
 * @s2: second string
 * @n: number of characters to compare
 * Return: 0 if strings are equal up to n, positive/negative value if not
 */
int _strncmp(char *s1, char *s2, int n);

/**
 * _strdup - duplicates a string
 * @s: input string
 * Return: pointer to the duplicated string
 */
char *_strdup(char *s);

/**
 * _strchr - locates the first occurrence of a character in a string
 * @s: input string
 * @c: character to locate
 * Return: pointer to the first occurrence of the character, NULL if not found
 */
char *_strchr(char *s, char c);

/**
 * execution - executes an external command
 * @cp: command path
 * @cmd: array of command arguments
 */
void execution(char *cp, char **cmd);

/**
 * find_path - finds the PATH environment variable and returns its value
 * Return: pointer to the PATH value, NULL if not found
 */
char *find_path(void);

/**
 * free_buffers - frees memory allocated for an array of strings
 * @buf: array of strings
 */
void free_buffers(char **buf);

/**
 * struct builtin - struct for built-in commands
 * @env: environment command
 * @exit: exit command
 */
struct builtin
{
	char *env;
	char *exit;
} builtin;

/**
 * struct info - struct for shell information
 * @final_exit: exit status of the shell
 * @ln_count: line count
 */
struct info
{
	int final_exit;
	int ln_count;
} info;

/**
 * struct flags - struct for shell flags
 * @interactive: flag indicating if the shell is in interactive mode
 */
struct flags
{
	bool interactive;
} flags;

#endif /* SHELL_H */
