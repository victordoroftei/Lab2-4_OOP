#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <crtdbg.h>

#include "console.h"
#include "test.h"

/*

	Creati o aplicatie care permite gestiunea stocului de materii prime folosite intr-o cofetarie.

	Fiecare materie prima din stoc are un nume unic, un producator si cantitate.

	Aplicatia permite:

		a) adaugare de materie prima (daca exista deja in stoc se actualizeaza cantitatea)

		b) modificare materie prima

		c) stergere materie prima

		d) Vizualizare materii prime care satisfac un criteriu (nume incepe cu o litera data, cantitatea disponibila e mai mica decat un numar dat)

		e) Vizualizare materii prime din stoc ordonat dupa nume sau cantitate disponibila (crescator/descrescator)

*/

int main()
{
	/*
		Functia nu are parametri de intrare sau de iesire, si nici preconditii si postconditii.
		Aceasta apeleaza functia de rulare a tuturor testelor, dar si functia ce functioneaza pe post de consola.
	*/

	rulareTeste();
	//console();
	
	_CrtDumpMemoryLeaks();
	return 0;
}