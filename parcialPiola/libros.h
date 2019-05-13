#ifndef LIBROS_H
#define LIBROS_H

typedef struct
{
    int id;
    int isEmpty;
    char titulo[51];
    int idAutor;

}Libros;

int inicializarArrayLibros(Libros *arrayLibros, int cant);
int buscarElVacioLibros(Libros *arrayLibros,int cant,int *indice);
int altaLibros(Libros *arrayLibros,Autores *arrayAuto,int cant,int posLibre);
int buscaIdLibros (Libros *array, int cant, int *idEncontrado);
int modificacionLibros(Libros *arrayLibros,Autores *arrayAutores,int cant);
int bajaLibros(Autores *arrayAuto,Libros *arrayLibros,int cant);
int OrdenamientoLibros(Libros *arrayLibros,Autores *arrayAuto,int cant);

#endif // LIBROS_H


