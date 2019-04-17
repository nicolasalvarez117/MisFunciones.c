#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define CANTIDAD_CLIENTES 5

#define CANTIDAD_CARACTERES 20


int main()
{
  char arrayNombres[CANTIDAD_CLIENTES][CANTIDAD_CARACTERES];
  char arrayApellido[CANTIDAD_CLIENTES][CANTIDAD_CARACTERES];
  int  arrayEdad[CANTIDAD_CLIENTES];
  int  arrayLegajo[CANTIDAD_CLIENTES];

  char auxiliarNombres[CANTIDAD_CARACTERES];
  char auxiliarApellido[CANTIDAD_CARACTERES];
  char auxiliarEdad[4];
  char auxiliarlegajo[4];
  int i,j;

  char bufferOpcion[2];
  int opcion;
  char bufferOpcion2[2];
  int opcion_Modificar;
  int estado[CANTIDAD_CLIENTES];
  int empty;

  for(i=0;i<CANTIDAD_CLIENTES;i++)
  {
      estado[i]= -1;
  }
  do
  {
    getOption("1: ALTA\n2: Baja\n3: Modificacion\n4: Ordenar\n 5: Listar\n6: Salir\n","opcion incorrecta\n",1,6,3,bufferOpcion);

        opcion = atoi(bufferOpcion);
        switch(opcion)
        {
            case 1:

                system("cls");
                if(!buscarEspacioVacio(estado,CANTIDAD_CLIENTES,empty))
                {
                    printf("no hay espacio libre");
                    break;
                }
                if(getName("Ingrese nombre: ","Error,Nombre invalido",2,CANTIDAD_CARACTERES,3,auxiliarNombres))
                {
                    printf("nombre incorrecto\n");
                    break;
                }
                if(getName("Ingrese apellido: ","Error,Apellido invalido",2,CANTIDAD_CARACTERES,3,auxiliarApellido))
                {
                    printf("apellido incorrecto\n");
                    break;
                }
                if(getEdad("ingrese la edad: ","edad incorrecta",1,120,3,auxiliarEdad))
                {
                    printf("Edad incorrecta");
                    break;
                }
                if(getLegajo("ingrese legajo: ","error,legajo incorrecto",1,CANTIDAD_CLIENTES,3,auxiliarlegajo))
                {
                    if(isValidLegajo(auxiliarlegajo,arrayLegajo,CANTIDAD_CLIENTES))
                    {
                        printf("legajo en uso");
                        break;
                    }
                }

                strncpy(arrayNombres[empty],auxiliarNombres,CANTIDAD_CARACTERES);
                strncpy(arrayApellido[empty],auxiliarApellido,CANTIDAD_CARACTERES);
                arrayEdad[empty] = atoi(auxiliarEdad);
                arrayLegajo[empty] = atoi(auxiliarlegajo);

                for(i=0;i<CANTIDAD_CLIENTES;i++)
                {
                    printf("\n%d",estado[i]);
                }
                break;

            case 2:

                getLegajo("ingrese el legajo a dar de baja: ","legajo incorrecto",
                          1,CANTIDAD_CLIENTES,3,auxiliarlegajo);
                if(bajaLegajo(arrayLegajo,auxiliarlegajo,CANTIDAD_CLIENTES,opcion_Modificar))
                {
                    printf("el legajo no esta en uso");
                    break;
                }
                //estado[opcion_Modificar] = -1;
                printf("%d",opcion_Modificar);
                break;
            /*case 3:
                system("cls");
                for(i=0;i<CANTIDAD_CLIENTES;i++)
                {
                    printf("nombre: %s apellido: %s edad: %d legajo: %d",
                           arrayNombres[i],arrayApellido[i],arrayEdad[i],arrayLegajo[i]);
                }
                getNumber("Que numero de legajo desea modificar? ","legajo incorrecto",
                          1,CANTIDAD_CLIENTES,3,bufferOpcion2);
                empty = atoi(bufferOpcion2);
                do
                {
                    system("cls");
                    getOption("1: Modificar Nombre\n2: Modificar apellido\n3: Modificar Edad\n4: Modificar legajo\n5: salir",
                              "opcion incorrecta",1,5,3,bufferOpcion2);
                              opcion = atoi(bufferOpcion2);
                    switch(opcion)
                    {
                    case 1:

                        if(getName("Ingrese nombre: ","Error,Nombre invalido",2,CANTIDAD_CARACTERES,3,auxiliarNombres))
                        {
                            printf("nombre incorrecto\n");
                            break;
                        }
                        strncpy(arrayNombres[empty-1],auxiliarNombres,CANTIDAD_CARACTERES);
                        printf("Nombre modificado");
                        break;
                    case 2:

                        if(getName("Ingrese apellido: ","Error,Apellido invalido",2,CANTIDAD_CARACTERES,3,auxiliarApellido))
                        {
                            printf("apellido incorrecto\n");
                            break;
                        }
                        strncpy(arrayApellido[empty-1],auxiliarApellido,CANTIDAD_CARACTERES);
                        printf("apellido modificado");
                        break;
                    case 3:
                        if(getEdad("ingrese la edad: ","edad incorrecta",1,120,3,auxiliarEdad))
                        {
                            printf("Edad incorrecta");
                            break;
                        }
                        arrayEdad[empty-1] = atoi(auxiliarEdad);
                        printf("Edad modificada");
                        break;
                    case 4:
                        if(getLegajo("ingrese legajo: ","error,legajo incorrecto",1,CANTIDAD_CLIENTES,3,auxiliarlegajo))
                        {
                            if(isValidLegajo(auxiliarlegajo,arrayLegajo,CANTIDAD_CLIENTES))
                            {
                                printf("legajo en uso");
                                break;
                            }
                        }
                        arrayLegajo[empty-1] = atoi(auxiliarlegajo);
                        printf("legajo modificado");
                        break;
                    }
                    }while(opcion != 5);*/
        }






  }while(opcion != 6);
  return 0;
}
