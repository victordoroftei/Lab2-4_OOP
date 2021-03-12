#include <stdio.h>
#include <string.h>

#include "repo.h"

int validareDateMP(char* nume, char* producator, int cantitate)
{
	if (strcmp(nume, "") == 0)
		return 0;

	if (strcmp(producator, "") == 0)
		return 1;

	if (cantitate <= 0)
		return 2;

	return -1;
}

int validareExistentaNume(Repo* repo, char* nume)
{
	int i;

	for (i = 0; i <= repo->lungime - 1; i++)
	{
		if (strcmp(repo->continut[i]->nume, nume) == 0)
			return -1;
	}

	return 3;
}

int validareOrdine(char* ordine)
{
	if (strcmp(ordine, "cresc") == 0 || strcmp(ordine, "descresc") == 0)
		return -1;

	return 8;
}