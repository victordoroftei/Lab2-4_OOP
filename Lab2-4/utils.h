#pragma once

char* decodareEroare(int cod);
/*
	Parametri de intrare:
		- cod: integer ce reprezinta codul de eroare ce trebuie decodat

	Parametri de iesire: 
		-

	Preconditii:
		- cod: numar intreg

	Postconditii:
		-

	Functia returneaza mesajul de eroare corespunzator codului dat;
*/


void intToString(int cantitate, char* numStr);
/*
	Parametri de intrare:
		- cantitate: integer care reprezinta cantitatea ce trebuie transformata din int in string
		- numStr: pointer catre string-ul transformat din int

	Parametri de intrare:
		- numStr: pointer catre string-ul transformat din int

	Preconditii:
		- cantitate: numar intreg
		- numStr: pointer catre un string

	Postconditii:
		- numStr: pointer catre un string ce contine cantitatea transformata din int in string
	
	Functia transforma cantitatea transmisa ca parametru intr-un string.
*/

int comparatorGeneric(MatPrima* mp1, MatPrima* mp2, char* camp, char* ordine);
/*
	Parametri de intrare:
		- mp1: pointer catre prima Materie Prima
		- mp2: pointer catre a doua Materie Prima
		- camp: pointer catre un sir de caractere ce reprezinta campul dupa care se va face compararea
		- ordine: pointer catre un sir de caractere ce reprezinta ordinea dupa care se va face compararea

	Parametri de iesire:
		-

	Preconditii:
		- mp1, mp2: pointeri catre Materii Prime
		- camp, ordine: pointeri catre un siruri de caractere

	Postconditii:
		-

	Functia returneaza -1, 0 sau 1, daca cele doua materii prime sunt neordonate, egale si, respectiv, ordonate.
*/
