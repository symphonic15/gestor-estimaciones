#include <stdio.h>
#include <stdlib.h>
#include "int/interface.h"
int main()
{
    char arr[50];
    strcpy(arr, "primero");
    nodo2* lista = crearNodo(1, arr);
    strcpy(arr, "segundo");
    lista = agregarAlFinal(lista, crearNodo(2, arr));
    strcpy(arr, "tercero");
    lista = agregarAlFinal(lista, crearNodo(3, arr));
    lista = printMenu(lista);
    seleccionarBoton(lista->dato);
    int a = manejarMenu(lista);
    printf("%i", a);
    return 0;
}
