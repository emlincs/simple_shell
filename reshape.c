#include "kovan.h"

/**
* verify_input - confirms if the PATH exists
* @argt: tokens details in array documents
* @argn: details of arguments from input
* Return: pointer to an array of the tokenized PATH index
*/
char *verify_input(char **argt, char **argn)
{
	char *new_argt, *birinci, (*yirtmac_argument) = "/";
	char **jetons_path, hamil_env[1024];
	int y = 0;
	const char *ileti = "No such file or dir, use: \"setenv [KEY] [VALUE]\"\n";

	if (argt[0][0] == '/' || argt[0][0] == '.')
	{
		new_argt = argt[0];

		if ((access(new_argt, F_OK) == -1))
			{
			write(STDERR_FILENO, ileti, strlen(ileti));
			return ("Kaput");
		}
	}
	else
	{
		strcpy(hamil_env, getenv("PATH"));
		jetons_path = tokenlestirme_path(hamil_env);
		while (jetons_path[y])
		{
			birinci = dize_concat(yirtmac_argument, argt[0]);
			new_argt = dize_concat(jetons_path[y], birinci);
			if ((access(new_argt, F_OK) == -1))
			{
				free(new_argt);
				free(birinci);
			}
			else
			{
				free(jetons_path);
				free(birinci);
				return (new_argt);
			}
			y++;
		}
		free(jetons_path);
		write(STDERR_FILENO, ileti, strlen(ileti));
		return ("Kaput");
	}
	return (new_argt);
}

/**
* verify_sade_spaces - confirms if keyed data string is only spaces
* @girdi: application reads its input data
* Return: 0 if there are line breaks, tabs or spaces
*/
int verify_sade_spaces(char *girdi)
{
	int y = 0, flama = 1, uzunluk = 0;

	uzunluk = strlen(girdi);
	while (girdi[y] == ' ' || girdi[y] == '\n' || girdi[y] == '\t')
		y++;

	if (y != uzunluk)
		flama = 0;
	return (flama);
}
