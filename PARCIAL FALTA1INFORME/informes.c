#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "orquesta.h"
#include "validaciones.h"
#include "musico.h"
#include "instrumento.h"
#include "informes.h"
#define LLENO 1
#define VACIO -1
void informes(Orquesta *arrayOrq,Instrumento *arrayIns,Musico *arrayMus,int cantOrq,int cantMus,int cantIns)
{
    int informe;


    printf("                   ::::::::::::::::::::\n");
    printf("                   :  1) INFORME: A   :\n");
    printf("                   :  2) INFORME: B   :\n");
    printf("                   :  3) INFORME: C   :\n");
    printf("                   :  4) INFORME: D   :\n");
    printf("                   :  5) INFORME: E   :\n");
    printf("                   :  6) INFORME: F   :\n");
    printf("                   :  7) INFORME: G   :\n");
    printf("                   :  8) INFORME: H   :\n");
    printf("                   ::::::::::::::::::::\n");

    printf("ingrese un informe... ");
    scanf("%d",&informe);

    switch(informe)
    {
    case 1:
        informeA( arrayOrq,cantOrq);
        break;
    case 2:
        informeB(arrayMus,cantMus,arrayIns,arrayOrq,cantOrq,cantIns);
        break;
    case 3:
        informeC(arrayOrq,cantOrq,arrayMus,cantMus);
        break;
    case 4:
        informeD( arrayOrq,cantOrq,arrayIns,cantIns,arrayMus,cantMus);
        break;
    case 5:
        informeE(arrayOrq,cantOrq,arrayMus,cantMus,arrayIns,cantIns);
        break;
    case 7:
        informeG(arrayOrq,cantOrq,arrayMus,cantMus,arrayIns,cantIns);
        break;
    case 8:
        informeH(arrayMus,cantMus,arrayIns,cantIns);
        break;
    }
}
void informeA(Orquesta *arrayOrq,int cantOrq)
{
    char auxLugar[50];
    int i;

    getDireccion(auxLugar,"ingrese un lugar: ","error, vuelva a ingresar\n\n",1,51,1);
    for(i=0; i<cantOrq; i++)
    {
        if(arrayOrq[i].isEmpty==LLENO && strcmp(arrayOrq[i].lugar,auxLugar)==0)
        {
            printf("id:%d nombre:%s tipo:%d lugar:%s \n",
                   arrayOrq[i].id,
                   arrayOrq[i].nombre,
                   arrayOrq[i].tipo,
                   arrayOrq[i].lugar);
        }
    }
}
void informeB(Musico *arrayMus,int cantMus,Instrumento *arrayIns,Orquesta *arrayOrq,int cantOrq,int cantIns)
{
    int i;
    int j;
    int k;

    for(i=0; i<cantMus; i++)
    {
        if(arrayMus[i].isEmpty==LLENO && arrayMus[i].edad < 25)
        {
            for(j=0; j<cantOrq; j++)
            {
                if(arrayOrq[j].id==arrayMus[i].idOrq)
                {
                    for(k=0; k<cantIns; k++)
                    {
                        if(arrayIns[k].id==arrayMus[i].idIns)
                        {
                            if(arrayIns[i].tipo==1)
                            {
                                printf(" id:%d nombre:%s apellido:%s edad:%d nombre de la orquesta:%s nombre de intrumento:cuerdas\n",
                                       arrayMus[i].id,
                                       arrayMus[i].nombre,
                                       arrayMus[i].apellido,
                                       arrayMus[i].edad,
                                       arrayOrq[j].nombre);
                                break;
                            }
                            if(arrayIns[i].tipo==2)
                            {
                                printf(" id:%d nombre:%s apellido:%s edad:%d nombre de la orquesta:%s nombre de intrumento:viento-madera\n",
                                       arrayMus[i].id,
                                       arrayMus[i].nombre,
                                       arrayMus[i].apellido,
                                       arrayMus[i].edad,
                                       arrayOrq[j].nombre);
                                break;
                            }
                            if(arrayIns[i].tipo==3)
                            {
                                printf(" id:%d nombre:%s apellido:%s edad:%d nombre de la orquesta:%s nombre de intrumento:viento-metal\n",
                                       arrayMus[i].id,
                                       arrayMus[i].nombre,
                                       arrayMus[i].apellido,
                                       arrayMus[i].edad,
                                       arrayOrq[j].nombre);
                                break;
                            }
                            if(arrayIns[i].tipo==4)
                            {
                                printf(" id:%d nombre:%s apellido:%s edad:%d nombre de la orquesta:%s nombre de intrumento:percusion\n",
                                       arrayMus[i].id,
                                       arrayMus[i].nombre,
                                       arrayMus[i].apellido,
                                       arrayMus[i].edad,
                                       arrayOrq[j].nombre);
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
}
void informeC(Orquesta *arrayOrq,int cantOrq,Musico *arrayMus,int cantMus)
{
    int i;
    int j;
    int k;
    int cont=0;
    for(i=0; i<cantOrq; i++)
    {
        if(arrayOrq[i].isEmpty==LLENO)
        {
            for(j=0; j<cantMus; j++)
            {
                if(arrayOrq[i].id==arrayMus[j].idOrq)
                {
                    cont++;
                }
            }
        }
    }
    for(k=0; k<cantOrq; k++)
    {
        if(cont<6 && arrayOrq[k].isEmpty==LLENO)
        {
            printf("id:%d nombre:%s tipo:%d lugar:%s \n",
                   arrayOrq[k].id,
                   arrayOrq[k].nombre,
                   arrayOrq[k].tipo,
                   arrayOrq[k].lugar);
        }
    }
}
void informeD(Orquesta *arrayOrq,int cantOrq,Instrumento *arrayIns,int cantIns,Musico *arrayMus,int cantMus)
{
    char idAut[50];
    int auxAut;
    int i;
    int j;
    int k;
    getInt("ingrese el id de la orquesta: ","\nerror,vuelva a intentar",0,20,1,idAut);
    auxAut=atoi(idAut);

    for(i=0; i<cantOrq; i++)
    {
        if(arrayOrq[i].isEmpty==LLENO && auxAut==arrayOrq[i].id)
        {
            for(j=0; j<cantMus; j++)
            {
                if(arrayMus[j].isEmpty==LLENO && arrayOrq[i].id==arrayMus[j].idOrq)
                {
                    for(k=0; k<cantIns; k++)
                    {
                        if(arrayIns[k].isEmpty==LLENO &&arrayMus[j].idIns==arrayIns[k].id)
                        {
                            if(arrayIns[k].tipo==1)
                            {
                                printf("nombre:cuerdas tipo:%d nombre de musico:%s\n",
                                       arrayIns[k].tipo,
                                       arrayMus[j].nombre);
                            }
                            if(arrayIns[k].tipo==2)
                            {
                                printf("nombre:viento-madera tipo:%d nombre de musico:%s\n",
                                       arrayIns[k].tipo,
                                       arrayMus[j].nombre);
                            }
                            if(arrayIns[k].tipo==3)
                            {
                                printf("nombre:viento-metal tipo:%d nombre de musico:%s\n",
                                       arrayIns[k].tipo,
                                       arrayMus[j].nombre);
                            }
                            if(arrayIns[k].tipo==4)
                            {
                                printf("nombre:percusion tipo:%d nombre de musico:%s\n",
                                       arrayIns[k].tipo,
                                       arrayMus[j].nombre);
                            }
                        }
                    }
                }
            }
        }
    }
}
void informeE(Orquesta *arrayOrq,int cantOrq,Musico *arrayMus,int cantMus,Instrumento *arrayIns,int cantIns)
{
    int i;
    int j;
    int k;
    int l;
    int contCue=0;
    int contPer=0;
    int contVie=0;
    for(i=0; i<cantOrq; i++)
    {
        if(arrayOrq[i].isEmpty==LLENO)
        {
            for(j=0; j<cantMus; j++)
            {
                if(arrayOrq[i].id==arrayMus[j].idOrq)
                {
                    for(k=0; k<cantIns; k++)
                    {
                        if(arrayMus[j].idIns==arrayIns[k].id)
                        {
                            if(arrayIns[k].tipo==1)
                            {
                                contCue++;
                            }
                            if(arrayIns[k].tipo==2||arrayIns[k].tipo==3)
                            {
                                contVie++;
                            }
                            if(arrayIns[k].tipo==4)
                            {
                                contPer++;
                            }
                        }
                    }
                }
            }
        }
    }
    for(l=0; l<cantOrq; l++)
    {
        if(contCue >=4 && contVie >=4 && contPer >= 1)
        {
            printf("nombre:%s lugar:%s tipo:%d\n",arrayOrq[l].nombre,arrayOrq[l].lugar,arrayOrq[l].tipo);
            break;
        }
    }
}
void informeG(Orquesta *arrayOrq,int cantOrq,Musico *arrayMus,int cantMus, Instrumento *arrayIns,int cantIns)
{
    int i;
    int j;
    int k;
    int contIns=0;
    float contOrq=0;
    float resul;
    for(i=0; i<cantMus; i++)
    {
        if(arrayMus[i].isEmpty==LLENO)
        {
            for(j=0; j<cantIns; j++)
            {
                if(arrayMus[i].idIns==arrayIns[j].id)
                {
                    contIns++;
                }
            }
        }
    }
    for(k=0; k<cantOrq; k++)
    {
        if(arrayOrq[k].isEmpty==LLENO)
        {
            contOrq++;
        }
    }
    resul=contIns/contOrq;
    printf("Promedio: %.2f",resul);
}
void informeH(Musico *arrayMus,int cantMus,Instrumento *arrayIns,int cantIns)
{
    int i;
    int j;
    int d;
    int a;
    Musico aux;
    printf("  ordenado alfabeticamente ascendente por apellido:\n");
    for(i = 1; i<cantMus; i++)
    {
        aux = arrayMus[i];
        j = i;
        while(j > 0 && strcmp( aux.apellido, arrayMus[j - 1].apellido)<0)
        {
            arrayMus[j] = arrayMus[j - 1];
            j--;
        }
        arrayMus[j] = aux;
    }
    for (d=0; d<cantMus; d++)
    {
        if(arrayMus[d].isEmpty==LLENO )
        {
            for(a=0; a<cantIns; a++)
            {
                if(arrayMus[d].idIns==arrayIns[a].id && arrayIns[a].isEmpty==LLENO)
                {
                    if(arrayIns[a].tipo!=2 && arrayIns[a].tipo!=3 )
                    {
                        printf("nombre:%s apellido:%s edad:%d tipo de intstrumento:%d\n",
                               arrayMus[d].nombre,
                               arrayMus[d].apellido,
                               arrayMus[d].edad,
                               arrayIns[a].tipo);
                    }
                }
            }
        }
    }
}
