#include "kovan.h"

/**
 * dize_concat - joins two character strings end-to-end
 * @dize1: character string 1
 * @dize2: character string 2
 * Return: pointer variable to the concatenated string
 */
char *dize_concat(char *dize1, char *dize2)
{
	char *diz;
	unsigned int y;
	unsigned int v;
	unsigned int h;

	if (dize1 == NULL)
		dize1 = "";

	if (dize2 == NULL)
		dize2 = "";

	for (y = 0; dize1[y] != '\0'; y++)
		continue;

	for (v = 0; dize2[v] != '\0'; v++)
		continue;

	v = v + 1;
	diz = malloc((y + v) * sizeof(char));
	if (diz == NULL)
		return (0);
	for (h = 0; h < (y + v) ; h++)
	{
		if (h < y)
			diz[h] = dize1[h];
		if (h >= y)
			diz[h] = dize2[h - y];
	}
	return (diz);
}

/**
 * lsh_realloc - it resizes a memory block
 * @gosterge: indexed access to elements(pointer)
 * @old_byt: earlier size
 * @new_byt: current size
 * Return: pointer to the assigned memory
 */

void *lsh_realloc(void *gosterge, unsigned int old_byt, unsigned int new_byt)
{
	char *diz;
	char *gosterge1;
	unsigned int y;

	gosterge1 = (char *)gosterge;
	if (gosterge == NULL)
		return (malloc(new_byt));
	if (new_byt == 0 && gosterge != NULL)
	{
		free(gosterge);
		return (NULL);
	}
	if (new_byt == old_byt)
		return (gosterge);

	diz = malloc((new_byt) * sizeof(char));
	if (diz == NULL)
	{
		free(diz);
		return (NULL);
	}

	if (new_byt > old_byt)
	{
		for (y = 0; y < old_byt; y++)
			diz[y] = gosterge1[y];
	}

	if (new_byt < old_byt)
	{
		for (y = 0; y < new_byt; y++)
			diz[y] = gosterge1[y];
	}
	free(gosterge1);
	return (diz);
}

