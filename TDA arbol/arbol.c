
#include "arbol.h"

nodoArbol * inicArbol(){
    return NULL;
}

nodoArbol * crearNodoArbol(int dato){
    nodoArbol * a = (nodoArbol *) malloc(sizeof(nodoArbol));
    a->dato = dato;
    a->der = NULL;
    a->izq = NULL;
    return a;
}

nodoArbol * insertar(nodoArbol * arbol, int dato){
    if(arbol){
        if(dato>arbol->dato){
            arbol->der = insertar(arbol->der, dato);
        }else{
            arbol->izq = insertar(arbol->izq, dato);
        }
    }else{
        arbol = crearNodoArbol(dato);
    }
    return arbol;
}

void mostrarPreorder(nodoArbol * arbol){
    if(arbol){
        printf("- %d -",arbol->dato);
        mostrarPreorder(arbol->izq);
        mostrarPreorder(arbol->der);
    }
}

nodoArbol * buscarDato(nodoArbol * arbol, int dato){
    nodoArbol * rta = NULL;
    if(arbol){
        if(arbol->dato == dato){
            rta = arbol;
        }else if(dato<arbol->dato){
            rta = buscarDato(arbol->izq, dato);
        }else{
            rta = buscarDato(arbol->der, dato);
        }
    }
    return rta;
}

int contarNiveles(nodoArbol * arbol){
    int nivD = 0, nivI = 0, niv = 0;
    if(arbol){
        nivD = 1 + contarNiveles(arbol->izq);
        nivI = 1 + contarNiveles(arbol->der);
        if(nivD>nivI){niv = nivD;}
        else{niv = nivI;}
    }
    return niv;
}

nodoArbol * cargarArbol(nodoArbol * arbol, int niveles){
    int ran;
    if(contarNiveles(arbol)<niveles){
        arbol = insertar(arbol, (rand()%101));
        cargarArbol(arbol, niveles);
    }
    return arbol;
}
