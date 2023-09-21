#ifndef SHELL_H
#define SHELL_H

#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>


/*our lovely constants*/
#define PATH_COMMAND 3
#define INVALID_COMMAND -1
#define INTERNAL_COMMAND 2
#define EXTERNAL_COMMAND 1


#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 *struct map - depicts a command to a function (if not the command can’t be found)
 *
 *@command_name: title of the command
 *@func: the function that enforces(if not nothing works)
 */

typedef struct map
{
	char *command_name;
	void (*func)(char **command);
} function_map;

extern char **commands;
extern char *shell_name;
extern char *line;
extern int status;
extern char **environ;


/*guide functions*/
void remove_newline(char *);
void _strcpy(char *, char *);
void print(char *, int);
int _strlen(char *);
char **tokenizer(char *, char *);


/*guide_2*/
char *_strchr(char *, char);
char *_strcat(char *, char *);
int _strspn(char *, char *);
int _strcmp(char *, char *);
int _strcspn(char *, char *);


/*guide_3*/
void ctrl_c_handler(int);
void remove_comment(char *);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strtok_r(char *, char *, char **);
int _atoi(char *);


/*utils (utility functions)*/
char *check_path(char *);
char *_getenv(char *);
void execute_command(char **, int);
void (*get_func(char *))(char **);
int parse_command(char *);


/*builtin functions*/
void quit(char **);
void env(char **);

/*main*/
extern void initializer(char **current_command, int type_command);
extern void non_interactive(void);


#endif /*SHELL_H*/


