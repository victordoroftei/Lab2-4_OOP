#include <string.h>
#include "domain.h"

char* decodareEroare(int cod)
{
	if (cod == -1)
		return "";

	char* erori[] =
	{
		/* 0) */ "Numele Materiei Prime este invalid! ",
		/* 1) */ "Producatorul Materiei Prime este invalid! ",
		/* 2) */ "Cantitatea Materiei Prime este invalida! ",
		/* 3) */ "Nu exista deja o Materie Prima cu acest nume in lista! ",
		/* 4) */ "Exista deja o Materie Prima cu acest nume si producator in lista, deci nu se poate adauga! ",
		/* 5) */ "Datele noii Materii Prime sunt invalide! ",
		/* 6) */ "Nu se poate face modificarea, deoarece deja exista o Materie Prima cu acest nume! ",
		/* 7) */ "Nu exista o Materie Prima cu acest nume in lista, deci nu se poate efectua modificarea! ",
		/* 8) */ "Ordinea data este invalida! Aceasta trebuie sa fie 'cresc' sau 'descresc'! "
	};

	return erori[cod];
}

void intToString(int cantitate, char* numStr)
{
	int cifre[21], nrCifre = 0, i;
	strcpy(numStr, "");

	while (cantitate)
	{
		cifre[nrCifre++] = cantitate % 10;
		cantitate /= 10;
	}

	for (i = nrCifre - 1; i >= 0; i--)
		numStr[nrCifre - i - 1] = (char)cifre[i] + '0';
}

int comparatorGeneric(MatPrima* mp1, MatPrima* mp2, char* camp, char* ordine)
{
	int intOrdine = strcmp(ordine, "cresc");
	if (strcmp(camp, "nume") == 0)
	{
		char* camp1 = mp1->nume;
		char* camp2 = mp2->nume;
		int comp = strcmp(camp1, camp2);

		if (comp < 0)
		{
			if (intOrdine == 0)
				return 1;

			else
				return -1;}

		else if (comp == 0)
			return 0;

		else
		{
			if (intOrdine == 0)
				return -1;

			else
				return 1;}}

	else
	{
		if (mp1->cantitate < mp2->cantitate)
		{
			if (intOrdine == 0)
				return 1;

			else
				return -1;}

		else if (mp1->cantitate == mp2->cantitate)
			return 0;

		else
		{
			if (intOrdine == 0)
				return -1;

			else
				return 1;
		}
	}
}