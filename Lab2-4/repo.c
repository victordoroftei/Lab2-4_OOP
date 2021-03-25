#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "repo.h"
#include "domain.h"

Repo* constructorRepo()
{
	Repo* repo = (Repo*)malloc(sizeof(Repo));

	if (repo != NULL)	// Aceasta comanda este aici ca sa nu avem warning-ul cu "Dereferencing NULL pointer".
	{
		repo->lungime = 0;
		repo->capacitate = 1;
		repo->continut = (MatPrima**)malloc(repo->capacitate * sizeof(MatPrima*));
	}

	return repo;
}

Repo* copieRepo(Repo* repo)
{
	Repo* reponou = (Repo*)malloc(sizeof(Repo));

	if (reponou != NULL)
	{
		reponou->lungime = repo->lungime;
		reponou->capacitate = repo->capacitate;
		reponou->continut = (MatPrima**)malloc(reponou->capacitate * sizeof(MatPrima*));

		int i;
		for (i = 0; i <= repo->lungime - 1; i++)
			reponou->continut[i] = copieMP(repo->continut[i]);
	}

	return reponou;
}

void destructorRepo(Repo* repo)
{
	int i;
	for (i = 0; i <= repo->lungime - 1; i++)
		destructorMP(repo->continut[i]);

	free(repo->continut);
	free(repo);
}

void realocareRepo(Repo* repo)
{
	/*
		Parametrii de intrare:
			- repo: pointer spre repository-ul de Materii Prime

		Parametrii de iesire:
			-

		Preconditii:
			- repo: repository-ul de Materii Prime

		Postconditii:	
			- repo: repository-ul de Materii Prime cu capacitatea dublata

		Functia realoca memoria in cazul in care urmatorul element ce va fi adaugat depaseste capacitatea maxima.
		Procesul de realocare consta in crearea unei liste cu capacitate dubla fata de cea precedenta, copierea elementelor din repo in aceasta,
		dezalocarea fostului continut din repo si copierea listei noi inapoi in repo.
	*/

	if (repo->capacitate != 0)	// Aceasta comanda este aici, ca sa nu avem warning-ul cu "Buffer Overrun".
	{
		MatPrima** listaNoua = malloc(2 * (repo->capacitate) * sizeof(MatPrima*));

		if (listaNoua != NULL)	// Aceasta comanda este aici ca sa nu avem warning-ul cu "Dereferencing NULL pointer".
		{
			int i;
			for (i = 0; i <= repo->lungime - 1; i++)
				listaNoua[i] = repo->continut[i];

			free(repo->continut);
			repo->continut = listaNoua;
			repo->capacitate *= 2;
		}
	}
}

int repoExistentaMP(Repo* repo, MatPrima* mp)
{
	int i;

	for (i = 0; i <= repo->lungime - 1; i++)
		if (strcmp(repo->continut[i]->nume, mp->nume) == 0)
		{
			if (strcmp(repo->continut[i]->producator, mp->producator) == 0)
				return i;

			else
				return -2;
		}

	return -1;
}

int repoAdaugareMP(Repo* repo, MatPrima* mp)
{
	if (repo->lungime + 1 > repo->capacitate)
		realocareRepo(repo);

	int index = repoExistentaMP(repo, mp);
	if (index == -1)
	{
		repo->continut[repo->lungime] = mp;
		repo->lungime++;

		return -1;}

	else if (index != -2)
	{
		repo->continut[index]->cantitate += mp->cantitate;

		destructorMP(mp);
		return -1;
	}

	destructorMP(mp);
	return 4;
}

void repoModificareMP(Repo* repo, MatPrima* mp, int index)
{
	destructorMP(repo->continut[index]);
	repo->continut[index] = mp;

}

void repoStergereMP(Repo* repo, int index)
{
	int i;

	destructorMP(repo->continut[index]);

	for (i = index; i <= repo->lungime - 1; i++)
		repo->continut[i] = repo->continut[i + 1];

	repo->lungime--;
}

void repoAfisare(Repo* repo)
{
	int i;
	printf("\nLista de materii prime");

	if (repo->lungime == 0)
		printf(" este vida!\n");

	else
	{
		printf(":\n");
		for (i = 0; i <= repo->lungime - 1; i++)
			printf("Nume: %s, Producator: %s, Cantitate: %d\n", repo->continut[i]->nume, repo->continut[i]->producator, repo->continut[i]->cantitate);
	}
}

int getIndexDinNume(Repo* repo, char* nume)
{
	int i;

	for (i = 0; i <= repo->lungime - 1; i++)
		if (strcmp(repo->continut[i]->nume, nume) == 0)
			return i;

	return -1;
}

int getFromPrimaLitera(Repo* repo, char litera, int indecsi[])
{
	int i, lungime = 0;
	for (i = 0; i <= repo->lungime - 1; i++)
		if (repo->continut[i]->nume[0] == litera)
			indecsi[lungime++] = i;
	
	return lungime;
}

int getFromCantitate(Repo* repo, int cantitate, int indecsi[])
{
	int i, lungime = 0;
	for (i = 0; i <= repo->lungime - 1; i++)
		if (repo->continut[i]->cantitate < cantitate)
			indecsi[lungime++] = i;

	return lungime;
}

MatPrima* getMPDinIndex(Repo* repo, int index)
{
	return repo->continut[index];
}