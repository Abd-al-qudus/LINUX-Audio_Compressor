#include "main.h"

/**
 * process_handler - creates a new process with system()
 * system indirectly calls fork() and wait under the hood
 * on a typical unix/linux system
 * @cmd: command to run
 * Return: success or failure
 */

int process_handler(char *cmd)
{
    int res;

    res = system(cmd);
    if (res != 0)
    {
        fprintf(stderr, "Error: command execution failed\n");
        return (FAILURE);
    }
    return (SUCCESS);
}
