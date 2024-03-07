#ifndef array_list_h
#define array_list_h

/* definicije simboličkih konstanti */
#define OK  0
#define ERR 1
#define MAXSIZE 20

/* deklaracija funkcija */
extern int addArray(int value, int* array, int* size);
extern int delateArray(int indeks, int* array, int* size);
extern void printArray(int* array, int* size);

extern int addList(int value);
extern void printList();
extern int deleteList(int value);

#endif
