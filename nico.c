#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nico.h"

#define MAX_DIGIT_OPTION 2
#define MIN_DIGIT_OPTION 1
#define TRUE 1
#define FALSE 0
#define EDAD_MAX_DIGIT 3
#define EDAD_MIN_DIGIT 1

#define DIGITOS_INT_MIN 1
#define DIGITOS_INT_MAX 6


/**
  *\brief Ordena el array de enteros.
  *\param La cantidad de elementos que tiene el array.
  *\param El array a ordenar.
  *\return El array ordenado de menor a mayor.
**/
int ordenamientoArrayEnteros(int limite,int vec[])
{
    int retorno = -1;
    int i,j,aux;
    for(i=0;i<limite-1;i++)
   {
         for(j=i+1;j<limite;j++)
       {
            if(vec[i]>vec[j])
          {
            aux=vec[i];
            vec[i]=vec[j];
            vec[j]=aux;
            retorno = 0;
          }
       }
    }
    return retorno;
}

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
    int retorno = 0;
    if(msg != NULL &&
       msgError != NULL &&
       minimo<maximo &&
       reintentos >= 0&&
       resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,buffer))
        {
            if(isValidName(buffer))
            {
                strncpy(resultado,buffer,maximo);
                retorno = 1;
            }
        }
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

int getNumber(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado)
{
    int retorno = 0;
    char buffer[4096];
    int bufferInt;
    if(msg != NULL &&
       msgError != NULL &&
       minimo < maximo &&
       reintentos >= 0 &&
       resultado != NULL)
    {
        if(!getString(msg,msgError,1,3,reintentos,buffer))
        {
           if(isValidNumber(buffer))
           {
              bufferInt = atoi(buffer);
              if(isValidRange(minimo,maximo,bufferInt))
              {
                 strncpy(resultado,buffer,maximo);
                 retorno = 1;
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
            return FALSE;
        }
        i++;
    }
    return retorno;
}

int isValidRange(int minimo,int maximo,int number)
{
    if(number >= minimo && number <= maximo)
    {
        return TRUE;
    }
    return FALSE;

}


int getInt(char *msg,char *msgError,int minimo,int maximo,int reintentos)

{
    int retorno = -1;
    int buffer;

    if(msg != NULL &&
       msgError != NULL &&
       minimo < maximo &&
       reintentos >= 0)
    {
       do
       {
            printf("%s",msg);
            scanf("%d",&buffer);
            if(isValidNumberInt(buffer))
            {
                if(isValidRange(minimo,maximo,buffer))
                {

                retorno = buffer;
                break;
                }
            }
            printf("%s",msgError);
            reintentos--;
       }while(reintentos >=0);
    }

    return retorno;

}

int isValidNumberInt(int str)
{
   int retorno = TRUE;
    int i=0;
    while(str != '\0')
    {
        if(!(str != ' ' && (str < 'a' || str > 'z') && (str < 'A' || str > 'Z')))
        {
            return FALSE;
        }
        i++;
    }
    return retorno;
}

int buscarEspacioVacio(int str[],int limite,int espacio_Vacio)

{
    int i;
    for(i=0;i<limite;i++)
    {
        if(str[i] == -1)
        {

            espacio_Vacio = i;
            str[i] = 1;
            return TRUE;
            break;
        }
    }
    return FALSE;
}

int getEdad(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado)
{
    int retorno = 0;
    char buffer[4096];
    int bufferInt;
    if(msg != NULL &&
       msgError != NULL &&
       minimo < maximo &&
       reintentos >= 0 &&
       resultado != NULL)
    {
        if(!getString(msg,msgError,EDAD_MIN_DIGIT,EDAD_MAX_DIGIT,reintentos,buffer))
        {
           if(isValidNumber(buffer))
           {
              bufferInt = atoi(buffer);
              if(isValidRange(minimo,maximo,bufferInt))
              {
                 strncpy(resultado,buffer,MAX_DIGIT_OPTION);
                 retorno = 1;
              }

           }
        }
    }
    return retorno;

}

int getOption(char *msg,char *msgError,int minimo,int maximo,int reintentos,int *resultado)
{
    int retorno = -1;
    char buffer[4096];
    int bufferInt;
    if(msg != NULL &&
       msgError != NULL &&
       minimo < maximo &&
       reintentos >= 0 &&
       resultado != NULL)
    {
        if(!getString(msg,msgError,MIN_DIGIT_OPTION,MAX_DIGIT_OPTION,reintentos,buffer))
        {
           if(isValidNumber(buffer))
           {
              bufferInt = atoi(buffer);
              if(isValidRange(minimo,maximo,bufferInt))
              {
                 strncpy(resultado,buffer,MAX_DIGIT_OPTION);
                 retorno = 0;
              }

           }
        }
    }
    return retorno;

}

int getLegajo(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado)
{
    int retorno = 0;
    char buffer[4096];
    int bufferInt;
    if(msg != NULL &&
       msgError != NULL &&
       minimo < maximo &&
       reintentos >= 0 &&
       resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,buffer))
        {
           if(isValidNumber(buffer))
           {
              bufferInt = atoi(buffer);
              if(isValidRange(minimo,maximo,bufferInt))
              {
                 strncpy(resultado,buffer,MAX_DIGIT_OPTION);
                 retorno = 1;
              }

           }
        }
    }
    return retorno;

}

int isValidLegajo(int numeroLegajo, int str[],int limite)
{
    int i;
    int retorno = TRUE;
    for(i=0;i<limite;i++)
    {
        if(numeroLegajo == str[i])
        {
            retorno = FALSE;
        }
    }
    return retorno;
}

int bajaLegajo(int str[],char compare,int limite,int resultado)
{
  //int aux;
  //aux = atoi(compare);
  int i;
  int aux;
  aux = atoi(compare);
  for(i=0;i<limite;i++)
  {

      if(str[i] == aux)
      {
          resultado = i;
          return 1;
          break;
      }
  }
  return 0;
}

int getString2(char *msg,
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

            printf(msg);
            scanf("%s", buffer);
            buffer[strlen(buffer)-1] = '\0';
            if(strlen(buffer)>= minimo && strlen(buffer) <= maximo)
            {
                strncpy(resultado,buffer,maximo);
                retorno = 0;

            }
            else
            {
                reintentos--;
                printf("%s",msgError);
            }



       }
    return retorno;

}
