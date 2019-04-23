#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define LIBRE -1
#define OCUPADO 1







int getString(char *msg,
              char *msgError,
              int minimo,
              int maximo,
              int reintentos,
              char *resultado)
{

    int retorno = -1;
    char buffer[4096];
    if(msg != NULL &&
       msgError != NULL &&
       minimo<maximo &&
       reintentos >= 0&&
       resultado != NULL)
        {
            do
            {
                printf("%s",msg);
                fflush(stdin);
                fgets(buffer,sizeof(buffer),stdin);
                buffer[strlen(buffer)-1] = '\0';
                if(strlen(buffer)>= minimo && strlen(buffer) <= maximo)
                {
                    strncpy(resultado,buffer,maximo);
                    retorno = 0;
                    break;
                }
                reintentos--;
                printf("%s",msgError);
            }while(reintentos >= 0);
        }
        return retorno;
}

int getName(char *msg,
            char *msgError,
            int minimo,
            int maximo,
            int reintentos,
            char *resultado)
{
    char buffer[4096];
    int retorno = -1;
    if(msg != NULL &&
       msgError != NULL &&
       minimo<maximo &&
       reintentos >= 0&&
       resultado != NULL)
    {
        do {
            if(!getString(msg,msgError,minimo,maximo,reintentos,buffer))
                {
                    if(isValidName(buffer))
                    {
                        strlwr(buffer);
                        buffer[0] = toupper(buffer[0]);
                        strncpy(resultado,buffer,maximo);
                        retorno = 0;
                    }
                    else
                    {
                        printf(msgError);
                    }
                }
            }while(retorno!=0);
    }
    return retorno;
}

int isValidName(char str[])
{

    int retorno = TRUE;
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] != ' ' && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return FALSE;
        }
        i++;
    }
    return retorno;

}

int getNumber(char *msg,char *msgError,int desde,int hasta,int minimo,int maximo,int reintentos,char *resultado)
{
    int retorno = -1;
    char buffer[4096];
    int bufferInt;
    if(msg != NULL &&
       msgError != NULL &&
       desde < hasta &&
       minimo < maximo &&
       reintentos >= 0 &&
       resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,buffer))
        {
           if(isValidNumber(buffer))
           {
              bufferInt = atoi(buffer);
              if(isValidRange(desde,hasta,bufferInt))
              {
                 strncpy(resultado,buffer,maximo);
                 retorno = 0;
              }

           }
        }
    }
    return retorno;

}

int isValidNumber(char strNumber[])
{
    int retorno = TRUE;
    int i = 0;
    while(strNumber[i] != '\0')
    {
        if(strNumber[i] < '0' || strNumber[i] > '9')
        {
            retorno = FALSE;
        }
        i++;
    }
    return retorno;
}

int isValidRange(int desde,int hasta,int numero)
{
    if(numero >= desde && numero <= hasta)
    {
        return TRUE;
    }
    return FALSE;

}

int buscarPrimerOcurrencia(ePersonas arrayPersonas[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(arrayPersonas[i].estado == valor)
        {
            return i;
            break;
        }
    }
    return -1;
}

void inicializarArrayPersonas(ePersonas arrayPersonas[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        arrayPersonas[i].estado = valor;
    }
}

void cargarPersona(ePersonas arrayPersonas[],int cantidadPersonas,int valorOcupado,int maxCaracter)
{
    int i;
    char auxLegajo[20];

    i = buscarPrimerOcurrencia(arrayPersonas,cantidadPersonas,valorOcupado);
    if(i!=-1)
    {
        getName("Ingrese Nombre: ","\ncaracter incorrecto\n",1,maxCaracter,3,arrayPersonas[i].nombre);
        getName("Ingrese Apellido: ","\ncaracter incorrecto\n",1,maxCaracter,3,arrayPersonas[i].apellido);
        getNumber("ingrese legajo","caracter incorrecto",1,5,1,10,3,auxLegajo);
        //printf("ingrese legajo: ");
        //scanf("%s",auxLegajo);
        arrayPersonas[i].legajo = atoi(auxLegajo);
        arrayPersonas[i].estado = OCUPADO;
        //ingresas mas datos a guardar

    }
    else
    {
        printf("\nNo hay espacio\n");
    }
}
/*void mostrarPersona(ePersonas arrayPersonas,int posicion)
{
    printf("%s %s",arrayPersonas[posicion].nombre,arrayPersonas[posicion].apellido);
    //agregar mas datos
}*/

void mostrarListaPersonas(ePersonas arrayPersonas[], int cantidadElementos,int valorOcupado)
{
    int i;
    for(i=0; i<cantidadElementos; i++)
    {
        if(arrayPersonas[i].estado!=valorOcupado)
        {
            //mostrarPersona(arrayPersonas,i);
        }

    }
}


void hardcodearDatosPersonas(ePersonas arrayPersonas[], int cantidadElementos)
{
    int i;
    int legajos[]={1,2,3,4,5};
    char nombres[][50]={"Maria","Pedro","Jose","Pedro","Pablo"};
    char sexo[]={'F','M','M','M','M'};
    float sueldosBruto[]={1000,2000,3000,4000,5000};

    for(i=0; i<cantidadElementos; i++)
    {
        //cargar los datos en la estructura

    }
}

void borrarPersona(ePersonas arrayPersonas[], int cantidadElementos,int maxCaracter)
{

    int i;
    int loEncontro = FALSE;
    char auxLegajo[maxCaracter];
    int legajo;
    getNumber("Ingrese el legajo a dar de baja: ","caracter incorrecto",1,cantidadElementos,1,maxCaracter,3,auxLegajo);
    legajo = atoi(auxLegajo);
    for(i=0; i<cantidadElementos; i++)
    {
        if(legajo == arrayPersonas[i].legajo)
        {

            arrayPersonas[i].estado = LIBRE;
            printf("Baja exitosa");

            loEncontro = TRUE;
            break;//modifcar
        }

    }

    if(loEncontro==FALSE)
    {
        printf("El dato no existe");
    }

}

void ordenarPersonasApellido(ePersonas arrayPersonas[],int cantidadElementos,ePersonas auxiliarPersonas)
{
    int i,j;

    for(i=0; i < cantidadElementos - 1; i++)
                {
                    if(arrayPersonas[i].estado == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < cantidadElementos; j++)
                    {
                        if(arrayPersonas[j].legajo == -1)
                        {
                            continue;
                        }
                        if(strcmp(arrayPersonas[i].apellido,arrayPersonas[j].apellido) > 0)
                        {
                            auxiliarPersonas = arrayPersonas[j];
                            arrayPersonas[j] = arrayPersonas[i];
                            arrayPersonas[i] = auxiliarPersonas;
                        }
                    }
                }
}

