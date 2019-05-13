#ifndef INFORMES_H
#define INFORMES_H

int informeC(Prestamos *arrayP,Socios *arrayS,int cant);
int informeD(Prestamos *arrayP,Socios *arrayS,Libros *arrayL,int cant);
void informeE(Libros *arrayL,Prestamos *arrayP,int cant);
int informeF(Socios *arrayS,Prestamos *arrayP,int cant);
int informeG(Libros *arrayL,int cant,Prestamos *arrayP);
int informeH(Socios *arrayS,int cant,Prestamos *arrayP);
void informeI(Libros *array,int cantidad);
void informeJ(Socios *array,int cant);

#endif
