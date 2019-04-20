#define EMPLEADOS 2
#define CARACTERES 20
#define VACIO -1
typedef struct
{
    char nombre[EMPLEADOS];
    char telefono[EMPLEADOS];
    int isEmpty;
} sEmpleados;


int inicializarArray(sEmpleados array[],int limite);

int buscarEspacioArray(sEmpleados array[],int limite);

//int funcionMostrarArray(sEmpleados array[],int limite);

int altaNombre(sEmpleados array[],int limite);

void functionMenu(sEmpleados array[]);
