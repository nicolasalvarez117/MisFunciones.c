#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "nico.h"

#define PERSONAS 5
#define MAX_CARACTER 50

void inicializarArrayClientes(ePersonas clientes[],int cantidadDeElementos,int valor);
int buscarPrimerOcurrencia(ePersonas clientes[],int cantidadDeElementos,int valor);
int isValidLegajo2(int numeroLegajo, ePersonas clientes[],int limite);

int main()
{
    ePersonas clientes[PERSONAS];
    aux auxiliarCopy[PERSONAS];
   char auxiliarNombre[50];
   char auxiliarApellido[50];
   char auxiliarLegajo[50];
   int auxLegajo;
   char auxiliarEdad[20];
   int auxEdad;
   int ifEmpty;

   int i,j;
   char auxOpcion[10];
   int opcion;


   inicializarArrayClientes(clientes,PERSONAS,-1);

   while(opcion != 6)
   {
       if(!getNumber("\n\n1: ALTA\n2: BAJA\n3: MODIFICACION\n4: ORDENAR POR APELLIDO\n5: LISTAR\n6: SALIR","\nOpcion incorrecta",1,6,3,auxOpcion))
       {
           printf("opcion incorrecta");
           break;
       }
       opcion = atoi(auxOpcion);

       switch(opcion)
       {
       case 1:
        system("cls");
        ifEmpty = buscarPrimerOcurrencia(clientes,PERSONAS,-1);
        if(ifEmpty == -1)
        {
            printf("no hay espacio disponible");
            break;
        }
        if(!getName("ingrese nombre: ","nombre incorrecto",2,10,3,auxiliarNombre))
        {
            printf("El nombre debe contener solo letras");
            break;
        }
        if(!getName("ingrese apellido: ","apellido incorrecto",2,10,3,auxiliarApellido))
        {
            printf("el apellido debe contener solo letras");
            break;
        }
        if(!getEdad("ingrese edad: ","edad incorrecta",1,120,3,auxiliarEdad))
        {
            printf("la edad debe contener solo numeros");
            break;
        }
        if(!getLegajo("ingrese el legajo: ","legajo incorrecto",1,PERSONAS,3,auxiliarLegajo))
        {
            printf("el legajo debe contener solo numeros");
            break;
        }
        if(isValidLegajo2(atoi(auxiliarLegajo),clientes,PERSONAS))
        {
            strncpy(clientes[ifEmpty].nombre,auxiliarNombre,MAX_CARACTER);
            strncpy(clientes[ifEmpty].apellido,auxiliarApellido,MAX_CARACTER);
            clientes[ifEmpty].edad = atoi(auxiliarEdad);
            clientes[ifEmpty].legajo = atoi(auxiliarLegajo);
            break;
        }

        printf("\nlegajo existente");
        break;


       case 2:
        for(i=0;i<PERSONAS;i++)
        {
            if(clientes[i].legajo != -1)
            {
                printf("%s %s %d legajo: %d\n",clientes[i].nombre,clientes[i].apellido,clientes[i].edad,clientes[i].legajo);
            }
        }
            if(!getLegajo("\nIngrese el legajo a dar de baja: ","legajo incorrecto",1,PERSONAS,3,auxiliarLegajo))
            {
                printf("el legajo debe contener solo numeros");
                break;
            }
            ifEmpty = buscarPrimerOcurrencia(clientes,PERSONAS,atoi(auxiliarLegajo));
            if(ifEmpty == -1)
            {
                printf("el legajo no esta en uso");
                break;
            }
            clientes[ifEmpty].legajo = -1;
            printf("Baja exitosa");
            break;
       case 3:
           for(i=0;i<PERSONAS;i++)
            {
                if(clientes[i].legajo != -1)
                {
                    printf("%s %s %d legajo: %d",clientes[i].nombre,clientes[i].apellido,clientes[i].edad,clientes[i].legajo);
                }
            }
            if(!getLegajo("\nIngrese el legajo a modificar: ","legajo incorrecto",1,PERSONAS,3,auxiliarLegajo))
            {
                printf("el legajo debe contener solo numeros");
                break;
            }
            ifEmpty = buscarPrimerOcurrencia(clientes,PERSONAS,atoi(auxiliarLegajo));
            if(ifEmpty == -1)
            {
                printf("el legajo no existe");
                break;
            }
        while(opcion != 5)
        {
            if(!getNumber("\n1: Mod_Nombre\n2: Mod_Apellido\n3: Mod_Edad\n4: Mod_Legajo\n5: Salir\n","opcion incorrecta",1,5,3,auxOpcion))
            {
                printf("Opcion incorrecta");
                break;
            }
            opcion = atoi(auxOpcion);
            switch(opcion)
            {
            case 1:
                if(!getName("ingrese nombre: ","nombre incorrecto",2,10,3,auxiliarNombre))
                {
                    printf("El nombre debe contener solo letras");
                    break;
                }
                strcpy(auxiliarApellido,clientes[ifEmpty].apellido);
                strcpy(clientes[ifEmpty].nombre,auxiliarNombre);
                strcpy(clientes[ifEmpty].apellido,auxiliarApellido);
                clientes[ifEmpty].edad = clientes[ifEmpty].edad;
                clientes[ifEmpty].legajo = clientes[ifEmpty].legajo;
                printf("\nModificacion exitosa");
                break;
            case 2:
                if(!getName("ingrese apellido: ","apellido incorrecto",2,10,3,auxiliarApellido))
                {
                    printf("el apellido debe contener solo letras");
                    break;
                }
                strcpy(auxiliarNombre,clientes[ifEmpty].nombre);
                strcpy(clientes[ifEmpty].apellido,auxiliarApellido);
                strcpy(clientes[ifEmpty].nombre,auxiliarNombre);
                clientes[ifEmpty].edad = clientes[ifEmpty].edad;
                clientes[ifEmpty].legajo = clientes[ifEmpty].legajo;
                printf("\nModificacion exitosa");
                break;
            case 3:
                if(!getEdad("ingrese edad: ","edad incorrecta",1,120,3,auxiliarEdad))
                {
                    printf("la edad debe contener solo numeros");
                    break;
                }
                strcpy(auxiliarApellido,clientes[ifEmpty].apellido);
                strcpy(auxiliarNombre,clientes[ifEmpty].nombre);
                strcpy(clientes[ifEmpty].nombre,auxiliarNombre);
                strcpy(clientes[ifEmpty].apellido,auxiliarApellido);
                clientes[ifEmpty].edad = atoi(auxiliarEdad);
                clientes[ifEmpty].legajo = clientes[ifEmpty].legajo;
                printf("\nModificacion exitosa");
                break;
            case 4:
                if(!getLegajo("ingrese legajo: ","edad incorrecta",1,120,3,auxiliarLegajo))
                {
                    printf("el legajo debe contener solo numeros");
                    break;
                }
                strcpy(auxiliarApellido,clientes[ifEmpty].apellido);
                strcpy(auxiliarNombre,clientes[ifEmpty].nombre);
                strcpy(clientes[ifEmpty].nombre,auxiliarNombre);
                strcpy(clientes[ifEmpty].apellido,auxiliarApellido);
                clientes[ifEmpty].edad = clientes[ifEmpty].edad;
                clientes[ifEmpty].legajo = auxiliarLegajo;
                printf("\nModificacion exitosa");
                break;
            case 5:
                opcion = 5;

            }

        case 4:
            for(i=0;i<PERSONAS-1;i++)
            {
                for(j=i+1;j<PERSONAS;j++)
                {
                    if(strcmp(clientes[i].apellido,clientes[j].apellido) > 0)
                    {
                        auxiliarCopy = clientes[i];
                        clientes[i] = clientes[j];
                        clientes[j] = auxiliarCopy;
                    }
                }
            }




   }

}
}
}

/**
 * \brief Inicializa un array de Personas con el valor recibido
 * \param array Es el array a ser inicializado
 * \param cantidadDeElementos Indica la logitud del array
 * \param valor Es el valor que sera cargado en cada posición
 * \return void
 *
 */
void inicializarArrayClientes(ePersonas clientes[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        clientes[i].legajo = valor;
    }
}

/**
 * \brief Busca la primer ocurrencia de un valor en un array de Personas
 * \param array Es el array en el cual buscar
 * \param cantidadDeElementos Indica la logitud del array
 * \param valor Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 *
 */
int buscarPrimerOcurrencia(ePersonas clientes[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(clientes[i].legajo == valor)
        {
            return i;
        }
    }
    return -1;
}

int isValidLegajo2(int numeroLegajo, ePersonas clientes[],int limite)
{
    int i;
    int retorno = 1;
    for(i=0;i<limite;i++)
    {
        if(numeroLegajo == clientes[i].legajo)
        {
            retorno = 0;
        }
    }
    return retorno;
}
