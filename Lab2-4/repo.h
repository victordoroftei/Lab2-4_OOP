#pragma once
#include "domain.h"

typedef struct
{
	MatPrima** continut;
	int lungime;
	int capacitate;
}Repo;

int repoAdaugareMP(Repo* repo, MatPrima* mp);
/*
	Parametri de intrare:
		- repo: pointer catre repository-ul de Materii Prime
		- mp: pointer catre Materia Prima care urmeaza sa fie adaugata in repo

	Parametri de iesire:
		-

	Preconditii:
		- repo: lista cu Materii Prime
		- mp: pointer catre Materie Prima

	Postconditii:
		- repo: lista de Materii Prime + materia prima data

	Functia primeste ca parametru un pointer catre o materie prima si il adauga in repository (dupa ce s-a verificat
	disponibilitatea capacitatii), incrementand numarul de elemente.

	Functia returneaza un cod de eroare.
*/

void repoModificareMP(Repo* repo, MatPrima* mp, int index);
/*
	Parametri de intrare:
		- repo: pointer catre repository-ul de Materii Prime
		- mp: pointer catre Materia Prima care urmeaza sa inlocuiasca Materia Prima de pe pozitia index
		- index: pozitia Materiei Prime care urmeaza sa fie inlocuita de Materia Prima cu pointerul mp

	Parametri de iesire:
		-

	Preconditii:
		- repo: lista cu Materii Prime
		- mp: pointer catre Materie Prima
		- index: numar natural, 0 <= index <= lungimea repo-ului

	Postconditii:
		- repo: lista de Materii Prime + materia prima data

	Functia modifica repository-ul de Materii Prime, modificand Materia Prima de pe pozitia index cu
	datele Materiei Prime cu pointerul mp.

*/

int getIndexDinNume(Repo* repo, char* nume);
/*
	Parametri de intrare:
		- repo: pointer catre repository-ul de Materii Prime
		- nume: pointer catre sirul de caractere dupa care cautam Materia Prima mp

	Parametri de iesire:
		-

	Preconditii:
		- repo: lista cu Materii Prime
		- nume: pointer catre un sir de caractere, numele unei posibile Materii Prime din repo

	Functia returneaza indexul Materiei Prime cu numele nume, din repo.
*/

void repoAfisare(Repo* repo);
/*
	Parametri de intrare:
		- repo: pointer catre repository-ul cu Materii Prime

	Parametri de iesire:
		-

	Preconditii:
		-

	Postconditii:
		-

	Functia afiseaza conmtinutul repository-ului cu .
*/

Repo* constructorRepo();
/*
	Parametri de intrare:
		-

	Parametri de iesire:
		-

	Functia construieste un pointer catre un repository gol si il returneaza.
*/

void destructorRepo(Repo* repo);
/*
	Parametri de intrare:
		- repo: pointer catre repository-ul de Materii Prime care urmeaza sa fie distrus (dezalocat)

	Parametri de iesire:
		-

	Functia primeste ca parametru un pointer catre un repository de Materii Prime si il distruge (dezaloca).
*/

int getIndecsiCuPrimaLitera(Repo* repo, char litera, int indecsi[]);
/*
	Parametri de intrare:
		- repo: pointer catre lista cu Materii Prime
		- litera: litera dupa care se va face cautarea
		- indecsi: un vector

	Parametri de iesire:
		- indecsi: vector ce va contine indecsii elementelor a caror nume au prima litera egala cu cea data

	Preconditii:
		- repo: lista de Materii Prime
		- litera: o litera
		- indecsi: un vector

	Postconditii:
		- indecsi: vector ce va contine indecsii elementelor a caror nume au prima litera egala cu cea data

	Functia construieste in vectorul indecsi o lista cu indecsii elementelor a caror nume au prima litera egala cu cea data.
	Functia returneaza lungimea acestui vector.
*/

int getIndecsiCuCantitate(Repo* repo, int cantitate, int indecsi[]);
/*
	Parametri de intrare:
		- repo: pointer catre lista cu Materii Prime
		- cantitate: cantiatea dupa care se va face cautarea
		- indecsi: un vector

	Parametri de iesire:
		- indecsi: vector ce va contine indecsii elementelor a caror nume au cantitatea mai mica decat cea data

	Preconditii:
		- repo: lista de Materii Prime
		- cantitate: un numar intreg
		- indecsi: un vector

	Postconditii:
		- indecsi: vector ce va contine indecsii elementelor a caror nume au cantitatea mai mica decat cea data

	Functia construieste in vectorul indecsi o lista cu indecsii elementelor a caror cantitate este mai mica decat cea data.
	Functia returneaza lungimea acestui vector.
*/

MatPrima* getMPDinIndex(Repo* repo, int index);
/*
	Parametri de intrare:
		- repo: lista de Materii Prime
		- index: integer ce reprezinta indexul dupa care trebuie sa extragem Materia Prima

	Parametri de iesire:
		- 

	Preconditii:
		- repo: lista de Materii Prime
		- index: un numar natural

	Postconditii:
		-
	
	Functia returneaza Materia Prima cu indexul index din lista de Materii Prime.
*/