#ifndef VALIDACIONES_C_INCLUDED
#define VALIDACIONES_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio_ext.h>
#include "validaciones.h"
#define TRUE 1
#define FALSE 0

int isValidInt(int numero, int minimo, int maximo)
{

    if(numero >= minimo && numero <= maximo)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int isValidFloat(float numero, float minimo, float maximo)
{
    if(numero >= minimo && numero <= maximo)
    {
        return 1;
    }
    return 0;
}

int isValidChar(char letra, char minimo, char maximo)
{
    if(letra>=minimo && letra <= maximo)
    {
        return TRUE;
    }
    return FALSE;
}

int isValidName (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a'))
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}

int isValidApellido (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a'))
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}

int isValidDni(char* cadena)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    int contadorPunto=0;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'0' || cadena[i]>'9') && (cadena[i]!='.'))
        {
            retorno=0;
        }
        if (cadena[i]=='.')
        {
            contadorPunto++;
        }
        if(contadorPunto>2)
        {
            retorno=FALSE;
        }
        if ((cadena[1]=='.' && cadena[5]=='.') || (cadena[2]=='.' && cadena[6]=='.'))
        {
            retorno=1;
        }
    }
    return retorno;
}

int isNumber (char* pString)
{
    int i=0;
    while(pString[i]!='\0')
    {
        if(pString[i]<'0' || pString[i]>'9')
        {
            return FALSE;
        }
        i++;
    }
    return TRUE;
}

int isValidFloatNumber(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int isValidNumber(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')//
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int isCuit (char* pString)
{
    int retorno=FALSE;
    int i=0;
    while(pString[i]!='\0')
    {
        if((pString[i]!='-')&&(pString[i]<'0' || pString[i]>'9'))
        {
            return FALSE;
        }
        else if((pString[2]=='-')&&(pString[10]=='-' || pString[11]=='-'))
        {
            retorno=TRUE;
        }
        i++;
    }
    return retorno;
}

int isTelefono (char* pString)
{
    int i=0;
    int contadorGuion=0;
    while(pString[i]!='\0')
    {
        if((pString[i]!=' ')&&(pString[i]!='-')&&(pString[i]<'0' || pString[i]>'9'))
        {
            return FALSE;
        }
        if(pString[i]=='-')
        {
            contadorGuion++;
        }
        i++;
    }
    if(contadorGuion==1)
        {
            return TRUE;
        }
    return FALSE;
}
/*
int isEmail(char* cadena)
{
    int retorno=TRUE;
    int contadorArroba=0;
    int i;
    for (i=0;i<50;i++)
    {
       while (cadena[i]!='\0')
        {
            if ((cadena[i]=='-')&&(cadena[i]=='_')&& (cadena[i]=='.')
                && (cadena[i]>='0' || cadena[i]<='9') && (cadena[i]>='A'||cadena[i]<='Z') &&
                (cadena[i]>='a' || cadena[i]<='z') && (cadena[i]=='@'))
            {
                retorno=TRUE;
                break;
            }
            if(cadena[i]=='@')
            {
                contadorArroba++;
            }
        }
    }
    if(contadorArroba==0 || contadorArroba>1)
    {
        retorno=FALSE;
    }
    return retorno;
}*/

int isValidEmail(char* cadena)
{
    int contador=0;
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'-' && cadena[i]!='+') || (cadena[i]>'9' && cadena[i]<'@') ||
           (cadena[i]>'Z' && cadena[i]!='_' && cadena[i]<'a')|| cadena[i]>'z')
        {
            retorno=0;
            break;
        }

        if (cadena[i]=='@')
        {
            contador++;
        }
    }

    if (contador==0 || contador>1)
    {
        retorno=0;
    }
    return retorno;
}

int isValidSex(char letra, char maximo, char minimo)
{
    int retorno = TRUE;

    if((letra != 'f') && (letra != 'F') && (letra != 'm') && (letra != 'M'))
    {
        retorno = FALSE;
    }
    return retorno;
}

/*
int isValidEmail(char* cadena)
{
    int retorno=TRUE;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    int contadorArroba=0;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'-' && cadena[i]!='+') || (cadena[i]>'9' && cadena[i]<'@') ||
           (cadena[i]>'Z' && cadena[i]!='_' && cadena[i]<'a')|| cadena[i]>'z')
        {
            retorno=FALSE;
        }
        if(cadena[i]=='@')
        {
            contadorArroba++;
        }
    }
        if(contadorArroba==1)
        {
            retorno=TRUE;
        }
    return retorno;
}
int isValidEmail(char* cadena)
{
    int retorno=TRUE;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    int contadorArroba=0;
    for(i=0;cadena[i]!='\0';i++)
    {
        if (cadena[i]=='@')
        {
            contadorArroba++;
            if (contadorArroba==1 && cadena[i]=='_' && cadena[i]=='-' && cadena[i]=='.' &&
                (cadena[i]>=0 || cadena[i]<=9) && (cadena[i]>'Z' || cadena[i]<'A') &&
                (cadena[i]>'z' || cadena[i]<'a'))
            {
                retorno=TRUE;
                break;
            }else
                {
                    retorno=FALSE;
                }
        }
    }
    return retorno;
}*/

int isValidAlphanumeric(char* cadena)
{
    int retorno=TRUE;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;cadena[i]!='\0';i++)
    {
        if(cadena[i]<'0' || (cadena[i]>'9' && cadena[i]<'A') || (cadena[i]>'Z' && cadena[i]<'a') || cadena[i]>'z' )
        {
            retorno=FALSE;
            break;
        }
    }
    return retorno;
}

int isValidFecha(char *cadena)
{
    int retorno=TRUE;
    int i;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'0' || cadena[i]>'9') && (cadena[i]!= '/' ))
        {
            retorno=FALSE;
        }
    }
    return retorno;
}

int isValidCUIT(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    int j;
    char buffer[14];
    strncpy(buffer,stringRecibido,14);

    for(i=0;buffer[i]!='\0';i++)
    {
        if((buffer[i]<'0' || buffer[i]>'9') && (buffer[i]!='-')) // chequeo que solo sean numeros o -
        {
            retorno=0;
            break;
        }

        if(buffer[i]=='-')  //elimino los -
        {
            for(j=i;buffer[j]!='\0';j++)
            {
                strncpy(&buffer[j],&buffer[j+1],1);
            }
        }
    }

    int digitos[10]={2,3,4,5,6,7,2,3,4,5};
    int acumulado = 0;
    int verificador;

    for(i=0;i < strlen(buffer-1); i++)
    {
        acumulado+=buffer[i]*digitos[i];
    }

    verificador=11-(acumulado%11);
	if(verificador == 11)
	{
		verificador = 0;
	}

	if(buffer[11]!=verificador)
    {
        retorno=0;
    }

    //if(stringRecibido[2]!='-' || stringRecibido[11]!='-' || stringRecibido[0]!='2' || stringRecibido[1]!='0' || stringRecibido[1]!='3' || stringRecibido[1]!='4' || stringRecibido[1]!='7')
    return retorno;
}
int getEntero(char* msg,char* msgError,int minimo,int maximo,int reintentos,int *resultado)
{
    char buffer[4096];

    int retorno = -1;

    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>0)
    {
        do
        {
            printf("%s",msg);
            scanf("%s",buffer);
            if(isValidEntero(buffer))
            {
                *resultado=atoi(buffer);
                retorno =0;
                break;
            }else{

                printf("%s",msgError);
            }
            reintentos--;
            }while(reintentos>=0);
    }
    return retorno;



}

int isValidEntero(char* cadena)
{
    int retorno = 0;
    int i;
    if(cadena != NULL)
    {
        for(i=0; cadena[i]!='\0'; i++)
        {
            if(cadena[i] >= '0' && cadena[i]<='9')
            {
                retorno = 1;
            }
        }
    }
    return retorno;
}
#endif // VALIDACIONES_C_INCLUDED
