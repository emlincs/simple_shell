#include "kovan.h"

/**
 * lsh_tokenlestirme - separates keyed data string into parameters (tokens)
 * @girdi: application reads its input data in (main function)
 * Return: Pointer to the set of arguments (tokens)
 */
char **lsh_tokenlestirme(char *girdi)
{
	char **jetons = NULL, *jeton = NULL;
	int tampon = BUFSIZE, yeniBuff = 0, konum = 0;
	char **backup_jetons = NULL;
	const char *ileti = "memory limit glitch, use: \"setenv [KEY] [VALUE]\"\n";

	jetons = malloc(tampon * sizeof(char *));
	if (jetons == NULL)
	{
		write(STDERR_FILENO, ileti, strlen(ileti));
		exit(EXIT_FAILURE);
	}
	jeton = strtok(girdi, DELIM);
	while (jeton != NULL)
	{
		jetons[konum] = jeton;
		konum++;
		if (konum >= tampon)
		{
			yeniBuff = BUFSIZE * 2;
			backup_jetons = jetons;
			jetons = lsh_realloc(jetons, tampon, yeniBuff * sizeof(char *));
			if (jetons == NULL)
			{
				free(backup_jetons);
				free(jetons);
				write(STDERR_FILENO, ileti, strlen(ileti));
				exit(EXIT_FAILURE);
			}
		}
		jeton = strtok(NULL, DELIM);
	}
	jetons[konum] = NULL;
	return (jetons);
}

/**
 * tokenlestirme_path - separates the environment variable PATH into parameters
 * @girdi: pointer to the PATH environment variable
 * Return: pointer to the set of arguments (tokens)
 */
char **tokenlestirme_path(char *girdi)
{
	int tampon = BUFSIZE, yeniBuff = 0, konum = 0;
	char **jetons = NULL, *jeton = NULL;
	char **backup_jetons = NULL;
	const char *ileti = "memory limit glitch, use: \"setenv [KEY] [VALUE]\"\n";

	jetons = malloc(tampon * sizeof(char *));
	if (jetons == NULL)
	{
		write(STDERR_FILENO, ileti, strlen(ileti));
		exit(EXIT_FAILURE);
	}
	jeton = strtok(girdi, ":");
	while (jeton != NULL)
	{
		jetons[konum] = jeton;
		konum++;
		if (konum >= tampon)
		{
			yeniBuff = BUFSIZE * 2;
			backup_jetons = jetons;
			jetons = lsh_realloc(jetons, tampon, yeniBuff * sizeof(char *));
			if (jetons == NULL)
			{
				free(backup_jetons);
				free(jetons);
				write(STDERR_FILENO, ileti, strlen(ileti));
				exit(EXIT_FAILURE);
			}
		}
		jeton = strtok(NULL, ":");
	}
	jetons[konum] = NULL;
	return (jetons);
}
