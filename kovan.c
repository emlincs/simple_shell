#include "kovan.h"

/**
* main - primary application that perpetually reads CLI input data and runs
* @argn: details of arguments
* Return: Always 0 on success
*/

int main(int argm __attribute__((unused)),
		char *argn[] __attribute__((unused)))
{
	char **argt = NULL;
	char *girdi_stdin = NULL;
	int durum_return = 1, cikis_status = 0;
	size_t boyut = 0;
	ssize_t glrkimet = 0;

	while (durum_return && glrkimet != EOF)
	{
		boyut = 0;
		durum_return = isatty(STDIN_FILENO);
		if (durum_return)
			write(STDOUT_FILENO, "$ ", 2); /* print prompt */
		glrkimet = getline(&girdi_stdin, &boyut, stdin);/* get input from stdin */
		if (glrkimet == -1)
		{
			free(girdi_stdin);
			break;
		}
		if (verify_sade_spaces(girdi_stdin))
		{
			free(girdi_stdin);
			continue;
		}
		argt = lsh_tokenlestirme(girdi_stdin);
		if (*argt[0] == '\0') /* if we get only spaces, tabs and line breaks */
			continue;
		durum_return = lsh_yapmak_builtins(argt, girdi_stdin,
		argn, &cikis_status);
		free(girdi_stdin);
		free(argt);
	}
	return (0);
}

