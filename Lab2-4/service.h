#pragma once
#include "repo.h"

int srvAdaugareMP(Repo* repo, char* nume, char* producator, int cantitate);
/*
	Parametri de intrare:
		- repo: pointer catre repository-ul de Materii Prime
		- name: pointer catre sirul de caractere ce reprezinta numele Materiei Prime ce treubie adaugata
		- producator: pointer catre sirul de caractere ce reprezinta producatorul Materiei Prime ce treubie adaugata
		- cantitate: integer ce reprezinta cantitatea Materiei Prime ce trebuie adaugata

	Parametri de iesire:
		-

	Preconditii:
		- repo: lista de Materii Prime
		- nume, producator: string-uri
		- cantitate: numar natural nenul

	Postconditii:
		- repo: lista de Materii Prime + o materie prima cu datele nume, producator, cantitate adaugata la lista

	Functia primeste de la consola datele pentru materia prima ce trebuie adaugata si
	apeleaza functii de validare si din repository (pt. adaugare).
	Functia returneaza un cod de eroare.
*/

int srvPreModificareMP(Repo* repo, char* numeOld);
/*
	Parametri de intrare:
		- repo: pointer catre repository-ul de Materii Prime
		- numeOld: pointer catre sirul de caractere al Materii Prime ce va fi inlocuita

	Parametri de iesire:
		-

	Preconditii:
		- repo: lista de Materii Prime
		- numeOld: string

	Postconditii:
		-

	Functia apeleaza functii de validare si returneaza un cod de eroare.
*/

int srvModificareMP(Repo* repo, char* nume, char* producator, int cantitate, char* numeOld);
/*
	Parametri de intrare:
		- repo: pointer catre repository-ul de Materii Prime
		- nume: pointer catre sirul de caractere ce reprezinta numele nou al Materiei Prime ce treubie modificata
		- producator: pointer catre sirul de caractere ce reprezinta producatorul nou al Materiei Prime ce treubie modificata
		- cantitate: integer ce reprezinta cantitatea noua a Materiei Prime ce trebuie modificata
		- numeOld: pointer catre sirul de caractere al Materii Prime ce va fi inlocuita

	Parametri de iesire:
		-

	Preconditii
		- repo: lista de Materii Prime
		- nume, producator: string-uri
		- numeOld: string ce reprezinta numele unei materii prime care exista deja in repo
		- cantitate: numar natural nenul

	Postconditii:
		- repo: lista de Materii Prime, Materia Prima cu numele numeOld avand datele schimbate (nume, producator, cantitate)

	Functia primeste de la consola numele Materiei Prime ce trebuie modificata, precum si datele noi pentru aceasta, si
	apeleaza functii de validare si din repository (pt. modificare).
	Functia returneaza un cod de eroare.
*/

int srvStergereMP(Repo* repo, char* nume);
/*
	Parametri de intrare:
		- repo: pointer catre repository-ul de Materii Prime
		- nume: pointer catre sirul de caractere ce reprezinta numele nou al Materiei Prime ce treubie modificata
		- producator: pointer catre sirul de caractere ce reprezinta producatorul nou al Materiei Prime ce treubie modificata
		- cantitate: integer ce reprezinta cantitatea noua a Materiei Prime ce trebuie modificata
		- numeOld: pointer catre sirul de caractere al Materii Prime ce va fi inlocuita

	Parametri de iesire:
		- repo: pointer catre repository-ul de Materii Prime, cu elementul cu numele dat sters

	Preconditii:
		- repo: lista de Materii Prime
		- nume: numele unei materii prime, sir de caractere

	Postconditii:
		- repo: lista de Materii Prime, cu cea cu numele nume eliminata


	Functia primeste de la consola un repository si un nume, si sterge Materia Prima cu acel nume din repo.
	Functia returneaza un cod de eroare.
*/

Repo* srvVizualizare(Repo* repo, char litera, int cantitate, char* criteriu);
/*
	Parametri de intrare:
		- repo: pointer catre lista de Materii Prime
		- litera: litera dupa care se va face vizualizarea
		- cantitate: integer, cantitatea dupa care se va face vizualizarea
		- criteriu: pointer catre string-ul ce va fi criteriul de vizualizare

	Parametri de iesire:
		-

	Preconditii:
		- repo: lista de Materii Prime
		- litera: o litera
		- cantitate: un numar intreg
		- criteriu: pointer catre un string ce poate fi "litera" sau "cantitate"

	Postconditii:
		-

	Functia returneaza o copie a repository-ului ce contine doar elementele filtrate.
*/

void srvSortareGenerica(Repo* repo, char* camp, char* ordine, int (*comparator)());
/*
	Parametri de intrare:
		- repo: pointer catre lista de Materii Prime
		- camp: pointer catre un string, ce reprezinta campul dupa care se va face sortarea ("nume" / "cantitate")
		- ordine: pointer catre un string, ce reprezinta ordinea dupa care se va face sortarea ("cresc" / "descresc")
		- comparator: pointer catre functia de comparare

	Parametri de iesire:
		- repo: pointer catre lista de Materii Prime sortata dupa campul camp in ordinea data

	Precontidii:
		- repo: lista de Materii Prime
		- camp: campul dupa care se va face sortarea ("nume" / "cantitate")
		- ordine: ordinea dupa care se va face sortarea ("cresc" / "descresc")

	Functia sorteaza repo-ul in functie de campul dat, in ordinea data.
*/