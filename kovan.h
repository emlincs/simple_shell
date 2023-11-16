#ifndef KOVAN_H
#define KOVAN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>


#define BUFSIZE 256
#define DELIM " \t\n"

/**
 * struct secmek_builtin - directly executable commands in shell structure
 * @isim_builtin: name of directly executable command
 * @islev_builtin: pointer to directly executable command functions
 */
typedef struct secmek_builtin
{
	char *isim_builtin;
	int (*islev_builtin)(char **, char *, int *);
} secmek_builtins_t;

/* builtin functions */
int lsh_cd(char *argt[], char *girdi_stdin, int *cikis_status);
int lsh_setenv(char *argt[],  char *girdi_stdin, int *cikis_status);
int lsh_env(char **argt, char *girdi_stdin, int *cikis_status);
int lsh_unsetenv(char **argt,  char *girdi_stdin, int *cikis_status);
int lsh_exit(char **argt, char *girdi_stdin, int *cikis_status);

/* execute commands */
int lsh_yapmak(char *argt[], char *argn[], int *cikis_status);
int lsh_yapmak_builtins(char *argt[], char *girdi_stdin,
		char *argn[], int *cikis_status);
/* supporting functions*/
void *lsh_realloc(void *gosterge, unsigned int old_byt, unsigned int new_byt);
char *dize_concat(char *dize1, char *dize2);

/* global variable to access the environment list */
extern char **environ;

/* verify inputs */
char *verify_input(char *argt[], char *argn[] __attribute__((unused)));
int verify_sade_spaces(char *girdi);

/* tokenizers */
char **lsh_tokenlestirme(char *girdi);
char **tokenlestirme_path(char *girdi);

#endif

