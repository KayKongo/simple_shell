#include "shell.h"

/**
 * the boot up/initializer of the shell - Begin executing commands.
 * @current_command: The command to execute.
 * @type_command: The type of command to be executed.
 *
 * This function initiates the execution of a command, handling both
 * external and internal commands. For external commands, it forks a new
 * process and calls execute_command. For internal commands, it directly
 * calls execute_command.
 *
 * Return: void.
 */
void initializer(char **current_command, int type_command)
{
    pid_t PID;

    if (type_command == EXTERNAL_COMMAND || type_command == PATH_COMMAND)
    {
        PID = fork();
        if (PID == 0)
            execute_command(current_command, type_command);
        else
        {
            waitpid(PID, &status, 0);
            status >>= 8;
        }
    }
    else
        execute_command(current_command, type_command);
}
