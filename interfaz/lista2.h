#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Boton.h"

typedef struct
{
    Boton dato;
    struct nodo2 * ste;
    struct nodo2 * ante;
} nodo2;

nodo2 * inicLista2();

nodo2 * crearNodo(int id, char dato[50]);

nodo2 * agregarAlPrincipio(nodo2 * lista, nodo2 * nuevoNodo);

nodo2 * buscarUltimoR(nodo2 * lista);

nodo2 * buscarPrimero(nodo2 * lista);

nodo2 * agregarAlFinal(nodo2 * lista, nodo2 * nuevoNodo);

nodo2 * borrarNodo(nodo2 * lista, char dato[50]);

void mostrarNodo(nodo2 * aux);

void recorrerYmostrar(nodo2 * lista);


#endif // LISTADOBLE_H_INCLUDED
