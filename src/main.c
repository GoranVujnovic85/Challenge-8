/*
 ============================================================================
 Name        : Challenge_22.c
 Author      : Goran Vujnovic
 Version     :
 Copyright   : Your copyright notice
 Description :zadatak 3:
              definisati compile switch u main.c koji ce se koristiti u array_list.c da ukljuci/iskljuci deo koda
              u funkcije iz zadatka 1 implementirati da umesto statickog niza koristi jednostruko vezanu listu
              sa compile switchom se bira da li ce da se koristi staticki niz ili lista


              Zadatak_1.
              U array_list.c implementirati funkcije
    *         add - parametri funkcije: vrednost elementa koji se dodaje u niz, adresa niza.
              funkcija dodaje element na kraj niza funkcija vraca OK (0) ako je u redu ERR (1) ako se dodaje na poziciju izvan velicine niza
              delete - parametri funkcije: indeks elementa koji se brise, adresa niza. funkcija vraca 0 ako je element obrisan, 1 ako nema element na tom mestu (0 i 1 definisati kao makroe OK i ERR)
              print - parametri funkcije: adresa niza, funkcija ispisuje sve elemente niza
              array_list.h deklarisati prethodne funkcije
              main.c pozvati implementirane funkcije i proveriti da li funkcionisu ispravno
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"

/* ukljuci/iskljuci deo koda */
#define USE_ARRAY

int main(void)
{
	#ifdef USE_ARRAY

		int array[MAXSIZE];

		int size = 0;

		addArray(10, array, &size);
		addArray(100, array, &size);
		addArray(1000, array, &size);
		addArray(10000, array, &size);

		printArray(array, &size);

		delateArray(2, array, &size);

		printArray(array, &size);

	#endif

	#ifndef USE_ARRAY
	#define USE_LIST

		addList(10);
		addList(100);
		addList(1000);
		addList(10000);

		printList();

		deleteList(1000);

		printList();

	#endif

	return 0;
}
