#pragma once

typedef struct
{
	char* nume;
	char* producator;
	int cantitate;

}MatPrima;

MatPrima* constructorMP(char* nume, char* producator, int cantitate);
/*
	Parametrii de intrare:
		- nume: pointer catre numele Materiei Prime
		- producator: pointer catre numele Materiei Prime
		- cantitate: integer ce reprezinta cantitatea Materiei Prime

	Parametrii de iesire:
		-

	Preconditii:
		- nume, producator: pointeri catre string-uri
		- cantitate: numar natural nenul

	Postconditii:
		-

	Functia construieste un pointer catre o variabila de tipul MatPrima cu datele luate din parametri si il returneaza.
*/

void destructorMP(MatPrima* mp);
/*
	Parametrii de intrare:
		- mp: pointer catre Materia Prima care urmeaza sa fie distrusa (dezalocata)

	Parametrii de iesire:
		-

	Preconditii:
		- mp: pointer catre o Materie Prima

	Postconditii:
		-

	Functia primeste ca parametru un pointer catre o materie prima si o distruge (dezaloca).
*/

/*
	
*/
MatPrima* copieMP(MatPrima* mp);