#include <string.h>

#include "repo.h"
#include "validator.h"
#include "utils.h"

int srvAdaugareMP(Repo* repo, char* nume, char* producator, int cantitate)
{
	int cod = validareDateMP(nume, producator, cantitate);

	if (cod == -1)
	{
		MatPrima* mp = constructorMP(nume, producator, cantitate);

		repoAdaugareMP(repo, mp);
	}

	return cod;
}

int srvPreModificareMP(Repo* repo, char* numeOld)
{
	return validareExistentaNume(repo, numeOld);
}

int srvModificareMP(Repo* repo, char* nume, char* producator, int cantitate, char* numeOld)
{
	if (strcmp(numeOld, nume) == 0)
	{
		if (validareDateMP(nume, producator, cantitate) == -1)
		{
			MatPrima* mp = constructorMP(nume, producator, cantitate);

			int index = getIndexDinNume(repo, numeOld);
			if (index == -1)
			{
				destructorMP(mp);
				return 7;
			}

			repoModificareMP(repo, mp, index);

			return -1;}

		else
			return 5;}

	else
	{
		if (validareExistentaNume(repo, nume) != -1)
		{
			if (validareDateMP(nume, producator, cantitate) == -1)
			{
				MatPrima* mp = constructorMP(nume, producator, cantitate);

				int index = getIndexDinNume(repo, numeOld);
				if (index == -1)
				{
					destructorMP(mp);
					return 7;
				}

				repoModificareMP(repo, mp, index);

				return -1;}

			else
				return 5;}

		else
			return 6;
	}
}

int srvStergereMP(Repo* repo, char* nume)
{
	int cod = validareExistentaNume(repo, nume);
	if (cod == -1)
	{
		int index = getIndexDinNume(repo, nume);
		repoStergereMP(repo, index);
	}
	
	return cod;

}

Repo* srvVizualizare(Repo* repo, char litera, int cantitate, char* criteriu)
{
	int indecsi[1001], lungime = 0, i;
	Repo* repoFiltrat = constructorRepo();

	if (strcmp(criteriu, "litera") == 0)
	{
		lungime = getFromPrimaLitera(repo, litera, indecsi);
		if (lungime == 0)
		{
			repoFiltrat->lungime = -1;
			return repoFiltrat;
		}
	}

	else
	{
		lungime = getFromCantitate(repo, cantitate, indecsi);
		if (lungime == 0)
		{
			repoFiltrat->lungime = -1;
			return repoFiltrat;
		}
	}

	MatPrima* mp;
	for (i = 0; i <= lungime - 1; i++)
	{
		mp = copieMP(getMPDinIndex(repo, indecsi[i]));

		repoAdaugareMP(repoFiltrat, mp);
	}

	return repoFiltrat;
}

void srvSortareGenerica(Repo* repo, char* camp, char* ordine, int (*comparator)())
{
	int i, j;
	MatPrima* aux;

	for(i = 0; i <= repo->lungime - 2; i++)
		for(j = i + 1; j <= repo->lungime - 1; j++)
			if (comparator(repo->continut[i], repo->continut[j], camp, ordine) == -1)
			{
				aux = repo->continut[i];
				repo->continut[i] = repo->continut[j];
				repo->continut[j] = aux;
			}
}