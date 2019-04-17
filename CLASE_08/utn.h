#define TRUE 1
#define FALSE 0

int getString ( char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);
//-------------------------------------

int getName (   char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);


int isValidName (char* cadena);


int inicializarArray(char array [][20],int cant);

int buscarEspacioArray(char array [][20],int cant);

int funcionMostrarArray( char array[][20],int cant);

int agregarNombre(char array[][20],int cant);
