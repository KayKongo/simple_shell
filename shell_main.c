
#include "shell.h"

/**
 * main - The main shell program
 * @argc: Number of arguments passed
 * @argv: Program arguments to be parsed
 *
 * Description:
 *   - Sets up the shell environment and execution loop
 *   - Handles signals like Ctrl+C
 *   - Parses and executes commands
 *
 * Return: 0 on success
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char **current_command = NULL;
	int i, type_command = 0;
	size_t n = 0;

	/* Register Ctrl+C handler */
	signal(SIGINT, ctrl_c_handler);
	shell_name = argv[0];

	while (1)
	{
		/* Check for interactive mode */
		non_interactive();
		print(" ($) ", STDOUT_FILENO);

		/* Read input line */
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(status);
		}
		
		remove_newline(line);
		remove_comment(line);
		commands = tokenizer(line, ";");

		for (i = 0; commands[i] != NULL; i++)
		{
			current_command = tokenizer(commands[i], " ");
			
			if (current_command[0] == NULL)
			{
				free(current_command);
				break;
			}
			
			type_command = parse_command(current_command[0]);

			/* Initialize and execute commands */
			initializer(current_command, type_command);
			free(current_command);
		}

		free(commands);
	}

	free(line);
	return (status);
}
