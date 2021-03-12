#pragma once

int validareDateMP(char* nume, char* producator, int cantitate);
/*
	Parametri de intrare:
		- nume: pointer catre numele Materiei Prime ce trebuie validata
		- producator: pointer catre producatorul Materiei Prime ce trebuie validata
		- cantitate: cantitatea Materiei Prime ce trebuie validata

	Parametri de iesire:
		-

	Functia valideaza datele Materiei Prime, returnand un cod de eroare.
*/

int validareExistentaNume(Repo* repo, char* nume);
/*
	Parametri de intrare:
		- repo: pointer catre repository-ul cu Materii Prime
		- nume: pointer catre numele a carui existenta va fi validata

	Parametri de iesire:
		-

	Functia verifica daca exista o Materie Prima cu numele nume in repository-ul repo si
	returneaza un cod de eroare.
*/

int validareOrdine(char* ordine);
/*
	Parametri de intrare:
		- ordine: pointer catre string-ul ce trebuie validat
	
	Parametri de iesire:
		-

	Preconditii:
		- ordine: pointer catre un string

	Postconditii:
		-

	Functia verifica daca ordinea este valida (adica este "cresc" sau "descresc") si returneaza un cod de eroare.
*/