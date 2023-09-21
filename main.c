#include "shell.h"


	char *shell_name = NULL;
	char *line = NULL;
	char **commands = NULL;
	int status = 0;


/**
 * main - the chairman shell code itself
 * @argc: number of arguments (computers must really be tired of counting)
 * @argv: program arguments to be parsed
 *
 * applies all the functionality of the functions in utils section and guides
 * implements EOF (End-of-Line)
 * Prints error when they fail
 * Return: 0 when there's success (should it have been 1 when successful rather? Ah well... lol)
 */


int main(int argc __attribute__((unused)), char **argv)
{
	size_t n = 0;
	int i, type_command = 0;
	char **current_command = NULL;

	shell_name = argv[0];
	signal(SIGINT, ctrl_c_handler);
	while (1)
	{
		non_interactive();
		print(" ($) ", STDOUT_FILENO);
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(status);
		}
			commands = tokenizer(line, ";");
			remove_comment(line);
			remove_newline(line);

		for (i = 0; commands[i] != NULL; i++)
		{
			current_command = tokenizer(commands[i], " ");
			if (current_command[0] == NULL)
			{
				free(current_command);
				break;
			}
			type_command = parse_command(current_command[0]);

			/* start 'em engines if you please   */
			initializer(current_command, type_command);
			free(current_command);
		}
		free(commands);
	}
	free(line);

	return (status);
}

