#pragma once
#include <string.h>
#include <stdlib.h>

#include "domain.h"


MatPrima* constructorMP(char* nume, char* producator, int cantitate)
{
	MatPrima* mp = (MatPrima*)malloc(sizeof(MatPrima));

	if (mp != NULL)
	{
		mp->producator = (char*)malloc(sizeof(char) * (strlen(producator) + 1));
		mp->nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
		mp->cantitate = cantitate;

		if (mp->nume != NULL)
			strcpy_s(mp->nume, strlen(nume) + 1, nume);
			
		if(mp->producator != NULL)
			strcpy_s(mp->producator, strlen(producator) + 1, producator);
	}

	return mp;
}

void destructorMP(MatPrima* mp)
{
	free(mp->nume);
	free(mp->producator);
	free(mp);
}

MatPrima* copieMP(MatPrima* mp)
{
	MatPrima* mpnou = constructorMP(mp->nume, mp->producator, mp->cantitate);

	return mpnou;
}