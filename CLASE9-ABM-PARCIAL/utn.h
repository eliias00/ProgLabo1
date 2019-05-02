#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

typedef struct
{
    int id;
    int isEmpty;
    char nombre[50];
    char direccion[50];
    float precio;
    int tipo;
}Pantalla;

int inicializarArray(Pantalla *auxPantalla, int cant);

int buscarLibre(Pantalla *auxPantalla, int cant, int *indice);

int Alta(Pantalla *auxPantalla, int cant, int posLibre,int id);

int modificarPantalla(Pantalla *auxPantalla, int cant);

int buscarPantalla (Pantalla *auxPantalla, int cant, int *pantallaEncontrada);

int pantallaBaja(Pantalla *auxPantalla, int cant);

void listarPantallas(Pantalla *auxPantalla,int cant);
#endif // UTN_H_INCLUDED
