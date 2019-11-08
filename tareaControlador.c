#include "tareaControlador.h"

nodoTarea* inicLista() {
    return NULL;
}

int buscarUltimoIdTar() {
    int id = 0;
    FILE* pArchTareas = fopen(archTareas, "rb");
    Tarea tarea;
    if(pArchTareas) {
        fseek(pArchTareas,sizeof(Tarea)*-1,SEEK_END);
        fread(&tarea, sizeof(Tarea), 1, pArchTareas);
        id = tarea.id;
    }
    fclose(pArchTareas);
    return id;
}

void crearTarea(Tarea t) {
    t.id = 1 + buscarUltimoIdTar();
    t.estado = 1;
    FILE* pArchTareas = fopen(archTareas, "ab");

    if(pArchTareas) {
        fwrite(&t, sizeof(Tarea), 1, pArchTareas);
    }

    fclose(pArchTareas);
}

int buscarTareaId(int id) {
    Tarea tarea;
    int posicion = -1;
    int flag = 0;

    FILE* pArchTareas = fopen(archTareas, sizeof(Tarea));
    if(pArchTareas) {
        while(fread(&tarea, sizeof(Tarea), 1, pArchTareas) && flag == 0) {
            if(tarea.id == id) {
                posicion = ftell(pArchTareas);
            }
        }
    }
    fclose(pArchTareas);

    return posicion;
}

void borrarTarea(int id) {
    int posicion = buscarTareaId(id);
    t.estado = -1;
    FILE* pArchTareas;

    if(posicion != -1) {
        pArchTareas = fopen(archTareas, "rb+");
        if(pArchTareas) {
            fseek(pArchTareas, posicion, SEEK_SET);
            fwrite(&t, sizeof(Tarea), 1, pArchTareas);
        }
        fclose(pArchTareas);
    }
}

nodoTarea* crearNodoTarea(Tarea t) {
    nodoTarea* nodo = malloc(sizeof(nodoTarea));

    nodo->tarea = t;
    nodo->siguiente = NULL;

    return nodo;
}

nodoTarea* ultimaTareaLista(nodoTarea* lista) {
    if(lista) {
        while(lista->siguiente) {
            lista = lista->siguiente;
        }
    }
    return lista;
}

nodoTarea* insertarTareaLista(nodoTarea* lista, nodoTarea* nodo) {
    nodoTarea* ultimaTarea = ultimaTareaLista(lista);

    if(nodo) {
        ultimaTarea->siguiente = nodo;
    }

    return lista;
}

void listaTareas(Proyecto p) {
    nodoTarea* lista;
    Tarea tarea;
    FILE* pArchTareas = fopen(archTareas, "rb");

    if(pArchTareas) {
        while(fread(&tarea, sizeof(Tarea), 1, pArchTareas)) {
            if(tarea.idProyecto == p.id && tarea.estado == 1) {
                lista = insertarTareaLista(lista, crearNodoTarea(tarea));
            }
        }
    }
    fclose(pArchTareas);
}
