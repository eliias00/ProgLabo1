#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "validaciones.h"
#define EMPLEADOS 2
#define CARACTERES 20

///dejar el ABM echo
/// ordenarlo

int main()
{
    sEmpleados arrayEmpleados[EMPLEADOS];

    inicializarArray(arrayEmpleados,EMPLEADOS);
    functionMenu(arrayEmpleados);

    return 0;
}
