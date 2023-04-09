#include "shell.h"
/**
  * exec_line - launches and executes processes
  * @args: an argument
  * Return: Always 0
  */
void exec_line(char **args)
{
	int status;
	pid_t child_pid = fork();

	switch (child_pid)
	{
		case -1:
			perror("hshell");
			exit(1);
			break;
		case 0:
			execvp(args[0], args);
			perror("hshell");
			exit(1);
			break;
		default:
			status = 0;
			do {
				waitpid(child_pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
			break;
	}
}
