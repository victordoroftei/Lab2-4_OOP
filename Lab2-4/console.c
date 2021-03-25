#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "service.h"
#include "repo.h"
#include "validator.h"
#include "utils.h"

void console()
{
	/*
		Functia console() serveste pe post de meniu al aplicatiei.
		Aceasta nu are parametri de intrare sau iesire si nici preconditii sau postconditii.
	*/

	system("cls");

	int comanda, run = 1;
	char aux[100];

	Repo* repo = constructorRepo();

	while (run)
	{
		comanda = -1;
		printf("=============== COFETARIE ===============");
		printf("\n1) Adaugare materie prima.");
		printf("\n2) Modificare materie prima.");
		printf("\n3) Stergere materie prima.");
		printf("\n4) Vizualizare materii prime care au numele incepand cu o litera data.");
		printf("\n5) Vizualizare materii prime care au cantitatea mai mica decat un numar dat.");
		printf("\n6) Sortare lista de materii prime dupa nume.");
		printf("\n7) Sortare lista de materii prime dupa cantitatea disponibila.");

		printf("\n0) Inchidere aplicatie.");

		printf("\n\nIntroduceti comanda: ");
		scanf_s("%d", &comanda);
		fgets(aux, 100, stdin);	// Golesc buffer-ul.

		if (comanda == 1)
		{
			int cantitate = -1;
			char nume[105], producator[105];
			printf("Introduceti datele materiei prime (nume, producator si cantitate, separate prin cate un Enter) pe care doriti sa o adaugati:\n");
			fgets(nume, 100, stdin);
			nume[strlen(nume) - 1] = '\0';

			fgets(producator, 100, stdin);
			producator[strlen(producator) - 1] = '\0';

			scanf_s("%d", &cantitate);

			int cod = srvAdaugareMP(repo, nume, producator, cantitate);
			if (cod == -1)
				repoAfisare(repo);
			else
				printf("\n%s\n", decodareEroare(cod));
		}

		else if (comanda == 2)
		{
			char numeOld[105];

			printf("Introduceti numele materiei prime pe care doriti sa o modificati: ");
			fgets(numeOld, 100, stdin);
			numeOld[strlen(numeOld) - 1] = '\0';

			int cod = srvPreModificareMP(repo, numeOld);
			if (cod == -1)
			{
				int cantitate = -1;
				char numeNew[105], producator[105];

				printf("Introduceti noile date (separate prin cate un Enter) pentru materia prima cu numele: %s\n", numeOld);
				fgets(numeNew, 100, stdin);
				numeNew[strlen(numeNew) - 1] = '\0';

				fgets(producator, 100, stdin);
				producator[strlen(producator) - 1] = '\0';

				scanf_s("%d", &cantitate);

				cod = srvModificareMP(repo, numeNew, producator, cantitate, numeOld);

				if (cod == -1)
					repoAfisare(repo);
				else
					printf("\n%s\n", decodareEroare(cod));
			}

			else
				printf("\n%s\n", decodareEroare(cod));
		}

		else if (comanda == 3)
		{
			char nume[105];

			printf("Introduceti numele materiei prime pe care doriti sa o stergeti: ");
			fgets(nume, 100, stdin);
			nume[strlen(nume) - 1] = '\0';

			int cod = srvStergereMP(repo, nume);

			if (cod == -1)
				repoAfisare(repo);
			else
				printf("\n%s\n", decodareEroare(cod));
		}

		else if (comanda == 4)
		{
			char litera = ' ';

			printf("Introduceti litera dupa care doriti sa faceti vizualizarea: ");
			scanf_s("%c", &litera, 1);

			Repo* repoFiltrat = srvVizualizare(repo, litera, 0, "litera");
			
			if (repoFiltrat->lungime == -1)
				printf("\nNu exista nicio Materie Prima cu acest criteriu!\n");

			else
				repoAfisare(repoFiltrat);
			
			destructorRepo(repoFiltrat);
		}

		else if (comanda == 5)
		{
			int cantitate = -1;

			printf("Introduceti cantitatea dupa care doriti sa faceti vizualizarea: ");
			scanf_s("%d", &cantitate);

			Repo* repoFiltrat = srvVizualizare(repo, ' ', cantitate, "cantitate");

			if (repoFiltrat->lungime == -1)
				printf("\nNu exista nicio Materie Prima cu acest criteriu!\n");

			else
				repoAfisare(repoFiltrat);

			destructorRepo(repoFiltrat);
		}

		else if (comanda == 6)
		{
			char ordine[11] = "";
			printf("Introduceti ordinea in care doriti sa faceti sortarea dupa nume ('cresc' / 'descresc'): ");
			fgets(ordine, 100, stdin);
			ordine[strlen(ordine) - 1] = '\0';

			int cod = validareOrdine(ordine);
			if (cod == -1)
			{
				srvSortareGenerica(repo, "nume", ordine, comparatorGeneric);
				repoAfisare(repo);
			}

			else
				printf("\n%s\n", decodareEroare(cod));
		}
		
		else if (comanda == 7)
		{
			char ordine[11] = "";
			printf("Introduceti ordinea in care doriti sa faceti sortarea dupa cantitate ('cresc' / 'descresc'): ");
			fgets(ordine, 100, stdin);
			ordine[strlen(ordine) - 1] = '\0';

			int cod = validareOrdine(ordine);
			if (cod == -1)
			{
				srvSortareGenerica(repo, "cantitate", ordine, comparatorGeneric);
				repoAfisare(repo);
			}

			else
				printf("\n%s\n", decodareEroare(cod));
		}

		else if (comanda == 0)
		{
			printf("\nAplicatia se va inchide...\n");
			destructorRepo(repo);
			return;
		}

		else
			printf("\nComanda invalida! Introduceti alta!\n");
	}
}
