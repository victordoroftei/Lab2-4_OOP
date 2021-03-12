#pragma once
#include <string.h>
#include <stdlib.h>

#include "domain.h"


MatPrima* constructorMP(char* nume, char* producator, int cantitate)
{
	MatPrima* mp = (MatPrima*)malloc(sizeof(MatPrima));

	mp->producator = (char*)malloc(sizeof(char) * (strlen(producator) + 1));
	mp->nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
	mp->cantitate = cantitate;

	strcpy(mp->nume, nume);
	strcpy(mp->producator, producator);

	return mp;
}

void destructorMP(MatPrima* mp)
{
	free(mp->nume);
	free(mp->producator);
	free(mp);
}