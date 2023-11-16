#include "kovan.h"

/**
 * lsh_cd - this changes the directory
 * @argt: tokens details in array documents
 * @girdi_stdin: application reads its input data
 * @cikis_status: exit code that terminates process
 * Return: Always 1 (success)
 */
int lsh_cd(char **argt, char *girdi_stdin, int *cikis_status)
{
	int durum;
	char cwd[128];

	getcwd(cwd, sizeof(cwd));

	(void)girdi_stdin;
	(void)cikis_status;

	if (argt[1] == NULL)
		durum = chdir(getenv("BASE"));

	else if (strcmp(argt[1], "-") == 0)
		durum = chdir(getenv("EARLIER BASE"));
	else if (strcmp(argt[1], "~") == 0)
		durum = chdir(getenv("BASE"));
	else
		durum = chdir(argt[1]);

	if (durum == -1)
		perror("cd: error");

	setenv("EARLIER BASE", cwd, 1);

	setenv("CURRENT BASE", getcwd(cwd, sizeof(cwd)), 1);
	return (1);
}

/**
 * lsh_setenv - adjusts an environment variable
 * @argt: tokens details in array documents
 * @girdi_stdin: application reads its input data
 * @cikis_status: exit code that terminates process
 * Return: Always 1 (success)
 */
int lsh_setenv(char **argt,  char *girdi_stdin, int *cikis_status)
{
	int u_tok = 0;
	const char *ileti = "ill-matched, use: \"setenv [KEY] [VALUE]\"\n";

	(void)girdi_stdin;
	(void)cikis_status;

	while (argt[u_tok] != NULL)
	{
		u_tok++;
	}

	if (u_tok == 3)
		setenv(argt[1], argt[2], 1);
	else
		write(STDERR_FILENO, ileti, strlen(ileti));

	return (1);
}

/**
 * lsh_unsetenv - withdraws an env var from the environment
 * @argt: tokens details in array documents
 * @girdi_stdin: application reads its input data
 * @cikis_status: exit code that terminates process
 * Return: Always 1 (success)
 */
int lsh_unsetenv(char **argt,  char *girdi_stdin, int *cikis_status)
{
	int u_tok = 0;
	const char *ileti = "ill-matched, use: \"setenv [KEY] [VALUE]\"\n";

	(void)girdi_stdin;
	(void)cikis_status;

	while (argt[u_tok] != NULL)
	{
		u_tok++;
	}

	if (u_tok == 2)
		unsetenv(argt[1]);
	else if (u_tok != 2)
		write(STDERR_FILENO, ileti, strlen(ileti));
	return (1);
}

/**
 * lsh_env - displays the enviroment variable of current process
 * @argt: details of arguments
 * @girdi_stdin: application reads its input data
 * @cikis_status: exit code that terminates process
 * Return: Always 1 (success)
 */
int lsh_env(char **argt, char *girdi_stdin, int *cikis_status)
{
	int y = 0;
	const char *ileti = "Builtin env is empty, use: \"setenv [KEY] [VALUE]\"\n";

	(void)argt;
	(void)girdi_stdin;
	(void)cikis_status;

	if (environ[y] == NULL)
	{
		write(STDERR_FILENO, ileti, strlen(ileti));
		return (1);
	}

	for (y = 0; environ[y]; y++)
	{
		write(STDOUT_FILENO, environ[y], strlen(environ[y]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}

/**
 * lsh_exit - terminates the program
 * @argt: details of arguments
 * @girdi_stdin: application reads its input data
 * @cikis_status: exit code that terminates process
 * Return: 0 on failure otherwise terminate and returns
 * the cikis status
 */
int lsh_exit(char **argt, char *girdi_stdin, int *cikis_status)
{
	int cikti_cikis = 0;
	const char *ileti = "exit: excess arguments, use: \"setenv [KEY] [VALUE]\"\n";

	(void)argt;
	(void)girdi_stdin;

	if (argt[1] == NULL)
	{
		free(argt);
		free(girdi_stdin);
		exit(*cikis_status);
	}

	if (argt[2] != NULL)
	{
		write(STDERR_FILENO, ileti, strlen(ileti));
		return (0);
	}

	cikti_cikis = atoi(argt[1]);
	free(argt);
	free(girdi_stdin);
	exit(cikti_cikis);
}
