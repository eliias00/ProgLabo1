#include "generico.h"
int generadorId(LinkedList* pLista);
int buscaId (LinkedList* pLista, int *idEncontrado);
int controller_cantidadGenericoda(LinkedList* pLista);
int controller_importeGenericodo(LinkedList* pLista);
int controller_loadFromText(char* path, LinkedList* pLista);
int controller_saveAsText(char* path, LinkedList* registro);
int controller_sort(LinkedList* pLista);
