#include "kovan.h"

/**
 * lsh_execute - creates new process and replaces child
 * with a new program
 * @argt: tokens details in array documents
 * @argn: details of arguments
 * @cikis_status: exit code that terminates process
 * Return: Always 1 (success)
 */
int lsh_execute(char **argt, char **argn, int *cikis_status)
{
	pid_t pid;
	int durum;
	char *yeni_argt;

	yeni_argt = verify_input(argt, argn);
	if (strcmp(yeni_argt, "Fizzle!") == 0)
		return (1);
	pid = fork();
	if (pid == 0) /* child process */
	{
		if (execve(yeni_argt, argt, environ) == -1)
		{
			perror("execve program crash");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0) /* verify if fork fails */
	{
		perror("Miscued Extention");
		free(yeni_argt);
		return (1);
	}
	else
	{
		waitpid(-1, &durum, 0);
		if (WIFEXITED(durum))
			*cikis_status = WEXITSTATUS(durum);
		if (argt[0][0] != '/' && argt[0][0] != '.')
			free(yeni_argt);
		return (1);
	}
	return (1);
}

/**
 * lsh_desdek_builtins - select from a set of builtin functions
 * @argt: tokens details in array documents
 * @argn: details of arguments
 * @girdi_stdin: application reads its input data
 * @cikis_status: exit code that terminates process
 * Return: Status to stay or terminate the main loop,
 * 1 or 0
 */
int lsh_desdek_builtins(char **argt, char *girdi_stdin,
			char **argn, int *cikis_status)
{
	int y = 0;

	secmek_builtins_t options[] = {
		{"exit", lsh_exit},
		{"env", lsh_env},
		{"cd", lsh_cd},
		{"setenv", lsh_setenv},
		{"unsetenv", lsh_unsetenv},
		{NULL, NULL}
	};

	while (options[y].isim_builtin)
	{
		if (strcmp(options[y].isim_builtin, argt[0]) == 0)
		{
		return ((int)((*options[y].islev_builtin)(argt, girdi_stdin, cikis_status)));
		}
		y++;
	}
	return (lsh_execute(argt, argn, cikis_status));
}

