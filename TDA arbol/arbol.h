#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
}nodoArbol;

nodoArbol * inicArbol();
nodoArbol * crearNodoArbol(int dato);
nodoArbol * insertar(nodoArbol * arbol, int dato);
void mostrarPreorder(nodoArbol * arbol);
nodoArbol * buscarDato(nodoArbol * arbol, int dato);
int contarNiveles(nodoArbol * arbol);
nodoArbol * cargarArbol(nodoArbol * arbol, int niveles);




#endif // ARBOLES_H_INCLUDED
