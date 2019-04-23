typedef struct
{
  char nombre[50];
  char apellido[50];
  int estado;
  int legajo;


}ePersonas;






int getString(char *msg,
              char *msgError,
              int minimo,
              int maximo,
              int reintentos,
              char *resultado);

int getName(char *msg,
            char *msgError,
            int minimo,
            int maximo,
            int reintentos,
            char *resultado);

int isValidName(char str[]);

int getNumber(char *msg,
              char *msgError,
              int desde,
              int hasta,
              int minimo,
              int maximo,
              int reintentos,
              char *resultado);
int isValidNumber(char strNumber[]);
int isValidRange(int desde,int hasta,int number);

int buscarPrimerOcurrencia(ePersonas arrayPersonas[],int cantidadDeElementos,int valor);
void inicializarArrayPersonas(ePersonas arrayPersonas[],int cantidadDeElementos,int valor);
void cargarPersona(ePersonas arrayPersonas[],int cantidadPersonas,int valorOcupado,int maxCaracter);
void mostrarListaPersonas(ePersonas arrayPersonas[], int cantidadElementos,int valorOcupado);
void mostrarPersona(ePersonas arrayPersonas,int posicion);
void hardcodearDatosPersonas(ePersonas arrayPersonas[], int cantidadElementos);
void borrarPersona(ePersonas arrayPersonas[], int cantidadElementos,int maxCaracter);
void ordenarPersonasApellido(ePersonas arrayPersonas[],int cantidadElementos,ePersonas auxiliarPersonas);







