

int ordenamientoArrayEnteros(int limite,int vec[]);
int getString(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado);
int getName(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado);
int isValidName(char str[]);
int getNumber(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado);
int isValidNumber(char strNumber[]);
int isValidRange(int minimo,int maximo,int number);
int getInt(char *msg,char *msgError,int minimo,int maximo,int reintentos,int *resultado);
int isValidNumberInt(int strNumber);
int buscarEspacioVacio(int str[],int limite,int espacio_Vacio);
int getEdad(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado);
int getOption(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado);
int getLegajo(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado);
int isValidLegajo(char numeroLegajo[], int str[],int limite);
int bajaLegajo(int str[],char compare,int limite,int resultado);
