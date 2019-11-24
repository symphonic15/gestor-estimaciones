#include "lista2.h"

nodo2 * inicLista()
{
    return NULL;
}

nodo2 * crearNodo(int id, char dato[50])
{
    nodo2* aux= (nodo2 *)malloc(sizeof(nodo2));
    strcpy(aux->dato.cartel, dato);
    aux->dato.id = id;
    aux->ante=NULL;
    aux->ste=NULL;
    return aux;
}

nodo2 * agregarAlPrincipio(nodo2 * lista, nodo2 * nuevoNodo)
{
    nuevoNodo->ste=lista;
    if(lista!=NULL)
    {
        lista->ante=nuevoNodo;
    }
    return nuevoNodo;
}

nodo2 * buscarUltimoR(nodo2 * lista)
{
    nodo2 * rta=NULL;
    if(lista!=NULL)
    {
        if(lista->ste==NULL)
        {
            rta=lista;
        }
        else
        {
            rta=buscarUltimoR(lista->ste);
        }
    }
    return rta;
}

nodo2 * buscarPrimero(nodo2 * lista){
    nodo2 * rta = inicLista();
    if(lista!=NULL){
        if(!lista->ante){
            rta = lista;
        }else{
            rta = buscarPrimero(lista->ante);
        }
    }
    rta;
}

nodo2 * agregarAlFinal(nodo2 * lista, nodo2 * nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nodo2 * ultimo = buscarUltimoR(lista);
        ultimo->ste = nuevoNodo;
        nuevoNodo->ante = ultimo;
    }
    return lista;
}

nodo2 * borrarNodo(nodo2 * lista, char dato[50])
{
    nodo2 * aBorrar=NULL;
    nodo2 * seg=NULL;

    if(lista!=NULL)
    {
        if(strcmp(lista->dato.cartel, dato)==0)
        {
            aBorrar=lista;

            lista=lista->ste;
            if(lista!=NULL)
                lista->ante=NULL;

            free(aBorrar);
        }
        else
        {
            seg=lista->ste;
            while(seg!=NULL && strcmp(seg->dato.cartel,dato)!=0)
            {
                seg=seg->ste;
            }

            if( seg!= NULL)
            {
                nodo2 * anterior=seg->ante;

                anterior->ste = seg->ste;

                if(seg->ste)
                {
                    nodo2 * siguiente = seg->ste;
                    siguiente->ante=anterior;
                }
                free(seg);
            }

        }
    }

    return lista;

}

void mostrarNodo(nodo2 * aux)
{
    printf(" %s", aux->dato.cartel);
}

void recorrerYmostrar(nodo2 * lista)
{
    printf("\nContenido de la lista: ");
    nodo2 * seg = lista;
    while (seg != NULL)
    {
        mostrarNodo(seg);
        seg= seg->ste;
    }
    printf("\n");
}

