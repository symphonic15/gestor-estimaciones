#include "interface.h"

nodo2 * agregarOpcion(nodo2* lista, int id, char[50] texto) {
    if(!lista) {
        lista = crearNodo(1, texto);
    }
    else {
        lista = agregarAlFinal(lista, crearNodo(id, texto));
    }

    return lista;
}

nodo2 * printMenu(nodo2 * lista){
    gotoxy(whereX(), (whereY()+2));
    nodo2 * aux = lista;
    Boton bot;
    if(lista){
        bot = crearBoton(aux->dato.id, aux->dato.cartel);
        lista->dato = bot;
        gotoxy(whereX(), bot.y+3);

        printMenu(aux->ste);
    }
    return lista;
}

int manejarMenu(nodo2 * lista){
    char r = 0;
    int res;
    nodo2 * aux = lista;
    if(aux){
        res = aux->dato.id;
        seleccionarBoton(aux->dato);
        r = getch();
        if(r=='w'){
            if(aux->ante){
                deseleccionarBoton(aux->dato);
                aux = aux->ante;
                seleccionarBoton(aux->dato);
                res = manejarMenu(aux);
            }else{
                deseleccionarBoton(aux->dato);
                aux = buscarUltimoR(aux);
                seleccionarBoton(aux->dato);
                res = manejarMenu(aux);
            }
        }else if(r=='s'){
            if(aux->ste){
                deseleccionarBoton(aux->dato);
                aux = aux->ste;
                seleccionarBoton(aux->dato);
                res = manejarMenu(aux);
            }else{
                deseleccionarBoton(aux->dato);
                aux = buscarPrimero(aux);
                seleccionarBoton(aux->dato);
                res = manejarMenu(aux);
            }
        }
    }
    return res;
}

/*int adminMenu(nodo2* lista){
    int res = 0;
    lista = printMenu(lista);
    Boton bot = manejarMenu(lista);

}*/
