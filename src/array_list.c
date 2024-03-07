#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"


/* definicija strukture podataka u jednostruko povezanoj listi */
typedef struct List
{
	int value;
	struct List* next;

}List;

/* pokazivac na prvi element liste (globalna varijabla) */
List* head = NULL;

/* funkcija dodaje element u niz */
int addArray(int value, int* array, int* size)
{
	if(*size >= MAXSIZE)
	{
		return ERR;
	}

	array[*size] = value;
	(*size)++;

	return OK;
}

/* funkcija dodaje element u listu */
int addList(int value)
{
	List* new = (List*)malloc(sizeof(List));

	if(new == NULL)
	{
		printf("Memory allocated failed!\n");
		return ERR;
	}

	new->value = value;
	new->next = NULL;

	if (head == NULL)
	{
		head = new;
	}
	else
	{
		List* current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new;
	}

	return OK;
}

/* funkcija brise element iz niza */
int delateArray(int indeks, int* array, int* size)
{
	if(indeks < 0 || indeks >= *size)
	{
		return ERR;
	}

	array[indeks] = array[indeks + 1];
	(*size)--;

	return OK;
}

/* funkcija brise element iz liste */
int deleteList(int value)
{
    List* current = head;
    List* previous = NULL;

    // Traženje elementa u listi
    while (current != NULL && current->value != value)
    {
        previous = current;
        current = current->next;
    }

    // Ako element nije pronađen
    if (current == NULL)
    {
        return ERR;
    }

    // Ako je pronađen element na početku liste
    if (previous == NULL)
    {
        head = current->next;
    }
    else
    {
        // Ako je pronađen element negde u sredini ili na kraju liste
        previous->next = current->next;
    }

    // Oslobađanje memorije zauzete za element koji se briše
    free(current);

    return OK;
}

/* funkcija stampa elemente niza */
void printArray(int* array, int* size)
{
	printf("Array: ");
	for(int i = 0; i < *size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

/* funkcija stampa elemente liste */
void printList()
{
	List* current = head;
	printf("List: ");
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}


