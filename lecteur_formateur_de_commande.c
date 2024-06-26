#include "main.h"

/**
 * lire_ligne - Lit une ligne depuis le terminal
 * Return: la ligne lue depuis l'entrée standard
 */
char *lire_ligne(void)
{
	char *ligne = NULL;
	size_t taille_buffer = 0;

	if (getline(&ligne, &taille_buffer, stdin) == -1)
	{
		if (ligne == NULL)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			printf("Erreur lors de la lecture de la ligne depuis l'entrée standard");
			free(ligne);
			exit(EXIT_FAILURE);
		}
	}
	return (ligne);
}


/**
 * diviser_chaine - Divise une ligne en utilisant des separateurs communs
 * @ligne: La ligne à diviser
 * @separateurs: chaine de caractères utilisée pour séparer
 * Return: Tableau de chaines de caractères contenant un mot chacune
 */

char **diviser_chaine(char *ligne, char *separateurs)
{
	int taille_buffer = 64;
	int i = 0;
	char **mots = (char **)malloc(taille_buffer * sizeof(char *));
	char *mot;

	if (!mots)
	{
		fprintf(stderr, "erreur d'allocation : mots\n");
		free(mots);
		exit(EXIT_FAILURE);
	}

	mot = strtok(ligne, separateurs);
	while (mot != NULL)
	{
		if (mot[0] == '#')
			break;
		mots[i] = mot;
		i++;
		if (i >= taille_buffer)
		{
			taille_buffer += taille_buffer;
			mots = (char **)realloc(mots, taille_buffer * sizeof(char *));
			if (!mots)
			{
				fprintf(stderr, "erreur de réallocation : mots");
				free(mots);
				exit(EXIT_FAILURE);
			}
		}
		mot = strtok(NULL, separateurs);
	}
	mots[i] = NULL;
	if (!mots)
	{
		fprintf(stderr, "erreur de réallocation : mots");
		free(mots);
		exit(EXIT_FAILURE);
	}
	return (mots);
}

