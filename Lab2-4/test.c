#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "domain.h"
#include "repo.h"
#include "service.h"
#include "validator.h"
#include "utils.h"

void testDomain()
{
	/*
		Functia are rolul de a testa domeniul aplicatiei.
		Functia aceasta nu are parametri de intrare sau iesire si nici preconditii sau postconditii.
	*/

	MatPrima* mp = constructorMP("Faina", "Ferma din Sat", 500);

	assert(strcmp(mp->nume, "Faina") == 0);
	assert(strcmp(mp->producator, "Ferma din Sat") == 0);
	assert(mp->cantitate == 500);

	MatPrima* mpnou = copieMP(mp);
	assert(strcmp(mpnou->nume, "Faina") == 0);
	assert(strcmp(mpnou->producator, "Ferma din Sat") == 0);
	assert(mpnou->cantitate == 500);

	destructorMP(mpnou);
	destructorMP(mp);
}

void testRepo()
{
	/*
		Functia are rolul de a testa functionalitatile repository-ului aplicatiei.
		Functia aceasta nu are parametri de intrare sau iesire si nici preconditii sau postconditii.
	*/

	// testRepoAdaugareMP();

	Repo* repo = constructorRepo();

	assert(repo->lungime == 0);
	assert(repo->capacitate == 1);
	assert(repo->continut != NULL);
	assert(repo != NULL);

	repoAdaugareMP(repo, constructorMP("Oua", "Gaina Vesela", 15));
	repoAdaugareMP(repo, constructorMP("Zahar Pudra", "Fabrica din Zanzibar", 2000));

	assert(repo->lungime == 2);
	assert(strcmp(repo->continut[0]->nume, "Oua") == 0);
	assert(strcmp(repo->continut[0]->producator, "Gaina Vesela") == 0);
	assert(repo->continut[0]->cantitate == 15);

	assert(strcmp(repo->continut[1]->nume, "Zahar Pudra") == 0);
	assert(strcmp(repo->continut[1]->producator, "Fabrica din Zanzibar") == 0);
	assert(repo->continut[1]->cantitate == 2000);

	repoAdaugareMP(repo, constructorMP("Oua", "Gaina Vesela", 30));
	assert(strcmp(repo->continut[0]->nume, "Oua") == 0);
	assert(strcmp(repo->continut[0]->producator, "Gaina Vesela") == 0);
	assert(repo->continut[0]->cantitate == 45);

	repoAdaugareMP(repo, constructorMP("Oua", "Gaina Trista", 30));
	assert(repo->lungime == 2);

	repoAdaugareMP(repo, constructorMP("Lapte", "Milka", 30000));
	assert(repo->lungime == 3);
	assert(strcmp(repo->continut[2]->nume, "Lapte") == 0);
	assert(strcmp(repo->continut[2]->producator, "Milka") == 0);
	assert(repo->continut[2]->cantitate == 30000);

	// testGetIndexDinNume();

	int index = getIndexDinNume(repo, "Oua");
	assert(index == 0);

	index = getIndexDinNume(repo, "Zahar Pudra");
	assert(index == 1);

	index = getIndexDinNume(repo, "Vanilie");
	assert(index == -1);

	// testRepoModificareMP();

	repoModificareMP(repo, constructorMP("Oua", "Ferma din Sat", 20), 0);

	assert(strcmp(repo->continut[0]->nume, "Oua") == 0);
	assert(strcmp(repo->continut[0]->producator, "Ferma din Sat") == 0);
	assert(repo->continut[0]->cantitate == 20);

	repoModificareMP(repo, constructorMP("Faina", "Moara de la Sat", 500), 1);

	assert(strcmp(repo->continut[1]->nume, "Faina") == 0);
	assert(strcmp(repo->continut[1]->producator, "Moara de la Sat") == 0);
	assert(repo->continut[1]->cantitate == 500);

	// testRepoExistentaMP();

	MatPrima* mp = constructorMP("Oua", "Ferma din Sat", 20);
	assert(repoExistentaMP(repo, mp) == 0);
	destructorMP(mp);

	mp = constructorMP("Oua", "Ferma din Oras", 20);
	assert(repoExistentaMP(repo, mp) == -2);
	destructorMP(mp);

	mp = constructorMP("Lapte Praf", "Ferma din Oras", 20);
	assert(repoExistentaMP(repo, mp) == -1);
	destructorMP(mp);

	repoAfisare(repo);

	// testGetFromPrimaLitera();

	int indecsi[101];

	assert(getFromPrimaLitera(repo, 'F', indecsi) == 1);
	assert(indecsi[0] == 1);

	// testGetMPDinIndex();

	mp = getMPDinIndex(repo, 0);

	assert(mp->cantitate == 20);
	assert(strcmp(mp->producator, "Ferma din Sat") == 0);
	assert(strcmp(mp->nume, "Oua") == 0);

	// testRepoStergereMP();

	repoStergereMP(repo, 0);

	assert(repo->lungime == 2);
	assert(strcmp(repo->continut[0]->nume, "Faina") == 0);
	assert(strcmp(repo->continut[0]->producator, "Moara de la Sat") == 0);
	assert(repo->continut[0]->cantitate == 500);

	assert(strcmp(repo->continut[1]->nume, "Lapte") == 0);
	assert(strcmp(repo->continut[1]->producator, "Milka") == 0);
	assert(repo->continut[1]->cantitate == 30000);

	repoStergereMP(repo, 1);

	assert(repo->lungime == 1);
	assert(strcmp(repo->continut[0]->nume, "Faina") == 0);
	assert(strcmp(repo->continut[0]->producator, "Moara de la Sat") == 0);
	assert(repo->continut[0]->cantitate == 500);

	// testCopieRepo();

	Repo* reponou = copieRepo(repo);
	assert(reponou->lungime == 1);
	assert(strcmp(reponou->continut[0]->nume, "Faina") == 0);
	assert(strcmp(reponou->continut[0]->producator, "Moara de la Sat") == 0);
	assert(reponou->continut[0]->cantitate == 500);

	destructorRepo(reponou);

	repoStergereMP(repo, 0);
	assert(repo->lungime == 0);
	repoAfisare(repo);

	destructorRepo(repo);
}

void testService()
{
	/*
		Functia are rolul de a testa functionalitatile service-ului aplicatiei.
		Functia aceasta nu are parametri de intrare sau iesire si nici preconditii sau postconditii.
	*/

	// testSrvAdaugareMP();

	Repo* repo = constructorRepo();

	int cod = srvAdaugareMP(repo, "Lapte", "Vaca din Sat", 3000);

	assert(repo->lungime == 1);
	assert(strcmp(repo->continut[0]->nume, "Lapte") == 0);
	assert(strcmp(repo->continut[0]->producator, "Vaca din Sat") == 0);
	assert(repo->continut[0]->cantitate == 3000);
	assert(cod == -1);

	// testSrvPreModificareMP();

	assert(srvPreModificareMP(repo, "Lapte") == -1);
	assert(srvPreModificareMP(repo, "Oua") == 3);

	// testSrvModificareMP();

	cod = srvModificareMP(repo, "Zahar", "Ferma locala", 22500, "Lapte");

	assert(cod == -1);
	assert(repo->lungime == 1);
	assert(strcmp(repo->continut[0]->nume, "Zahar") == 0);
	assert(strcmp(repo->continut[0]->producator, "Ferma locala") == 0);
	assert(repo->continut[0]->cantitate == 22500);

	cod = srvModificareMP(repo, "", "Ferma Mica", 100, "Zahar");
	assert(cod == 5);

	srvAdaugareMP(repo, "Vanilie", "Tarile Calde", 2050);
	cod = srvModificareMP(repo, "Vanilie", "Zanzibar", 350, "Zahar");
	assert(cod == 6);

	cod = srvModificareMP(repo, "Portocale", "Ferma din Spania", 1000, "Lapteee");
	assert(cod == 7);

	cod = srvModificareMP(repo, "Vanilie", "Zanzibar", 350, "Vanilie");
	assert(cod == -1);

	cod = srvModificareMP(repo, "Portocale", "Ferma din Spania", 1000, "Portocale");
	assert(cod == 7);

	cod = srvModificareMP(repo, "Vanilie", "", 1000, "Vanilie");
	assert(cod == 5);

	// testSrvSortareGenerica();

	srvSortareGenerica(repo, "nume", "cresc", comparatorGeneric);
	assert(strcmp(repo->continut[0]->nume, "Vanilie") == 0);
	assert(strcmp(repo->continut[0]->producator, "Zanzibar") == 0);
	assert(repo->continut[0]->cantitate == 350);

	assert(strcmp(repo->continut[1]->nume, "Zahar") == 0);
	assert(strcmp(repo->continut[1]->producator, "Ferma locala") == 0);
	assert(repo->continut[1]->cantitate == 22500);

	assert(repo->lungime == 2);

	// testSrvVizualizare();

	Repo* repoFiltrat = srvVizualizare(repo, 'X', 0, "litera");
	assert(repoFiltrat->lungime == -1);
	destructorRepo(repoFiltrat);

	repoFiltrat = srvVizualizare(repo, 'Z', 0, "litera");
	assert(repoFiltrat->lungime == 1);

	assert(strcmp(repoFiltrat->continut[0]->nume, "Zahar") == 0);
	assert(strcmp(repoFiltrat->continut[0]->producator, "Ferma locala") == 0);
	assert(repoFiltrat->continut[0]->cantitate == 22500);
	destructorRepo(repoFiltrat);

	repoFiltrat = srvVizualizare(repo, 'X', 100, "cantitate");

	assert(repoFiltrat->lungime == -1);
	destructorRepo(repoFiltrat);

	repoFiltrat = srvVizualizare(repo, 'X', 30000, "cantitate");
	assert(repoFiltrat->lungime == 2);

	assert(strcmp(repoFiltrat->continut[0]->nume, "Vanilie") == 0);
	assert(strcmp(repoFiltrat->continut[0]->producator, "Zanzibar") == 0);
	assert(repoFiltrat->continut[0]->cantitate == 350);

	assert(strcmp(repoFiltrat->continut[1]->nume, "Zahar") == 0);
	assert(strcmp(repoFiltrat->continut[1]->producator, "Ferma locala") == 0);
	assert(repoFiltrat->continut[1]->cantitate == 22500);
	destructorRepo(repoFiltrat);

	// testSrvStergereMP();

	srvStergereMP(repo, "Zahar");
	assert(repo->lungime == 1);

	srvStergereMP(repo, "Vanilie");
	assert(repo->lungime == 0);

	destructorRepo(repo);
}

void testValidator()
{
	/*
		Functia are rolul de a testa validatorii aplicatiei.
		Functia aceasta nu are parametri de intrare sau iesire si nici preconditii sau postconditii.
	*/

	// testValidareDateMP();

	assert(validareDateMP("", "Ferma", 100) == 0);
	assert(validareDateMP("Malai", "", 7000) == 1);
	assert(validareDateMP("Zahar", "Trestia fericita", -100) == 2);
	assert(validareDateMP("", "", -1) == 0);
	assert(validareDateMP("Zahar", "Trestia fericita", 10000) == -1);

	// testValdareExistentaNume();

	Repo* repo = constructorRepo();

	repoAdaugareMP(repo, constructorMP("Faina", "Foarte Alba", 8000));
	assert(validareExistentaNume(repo, "Faina") == -1);
	assert(validareExistentaNume(repo, "Oua") == 3);

	repoAdaugareMP(repo, constructorMP("Oua", "Gaina Alba", 8000));
	assert(validareExistentaNume(repo, "Oua") == -1);

	destructorRepo(repo);

	// testValidareOrdine();

	assert(validareOrdine("cresc") == -1);
	assert(validareOrdine("xiogfs") == 8);
}

void testUtils()
{
	// testDecodareEroare();

	assert(strcmp(decodareEroare(0), "Numele Materiei Prime este invalid! ") == 0);
	assert(strcmp(decodareEroare(-1), "") == 0);

	char string[21] = "";

	// testIntToString();

	intToString(5670, string);
	assert(strcmp(string, "5670") == 0);

	// testComparatorGeneric();

	MatPrima* mp1 = constructorMP("Oua", "Gaina Alba a Vecinului", 300);
	MatPrima* mp2 = constructorMP("Laptic", "Vacuta Milka", 2500);

	assert(comparatorGeneric(mp1, mp2, "nume", "cresc") == -1);
	assert(comparatorGeneric(mp1, mp2, "nume", "descresc") == 1);
	assert(comparatorGeneric(mp2, mp1, "nume", "cresc") == 1);
	assert(comparatorGeneric(mp2, mp1, "nume", "descresc") == -1);
	assert(comparatorGeneric(mp1, mp1, "nume", "descresc") == 0);
	assert(comparatorGeneric(mp1, mp2, "cantitate", "cresc") == 1);
	assert(comparatorGeneric(mp1, mp2, "cantitate", "descresc") == -1);
	assert(comparatorGeneric(mp2, mp1, "cantitate", "cresc") == -1);
	assert(comparatorGeneric(mp2, mp1, "cantitate", "descresc") == 1);
	assert(comparatorGeneric(mp1, mp1, "cantitate", "descresc") == 0);


	destructorMP(mp1);
	destructorMP(mp2);
}

void rulareTeste()
{
	/*
		Functia are rolul de a apela toate categoriile de teste. Aceasta functie va fi apelata in main, inainte de a se porni consola.
		Functia aceasta nu are parametri de intrare sau iesire si nici preconditii sau postconditii.
	*/

	testDomain();
	testRepo();
	testService();
	testValidator();
	testUtils();
}
