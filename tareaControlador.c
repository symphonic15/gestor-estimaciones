#include "tareaControlador.h"

/**< HELPERS */

/* Devuelve una tarea con datos nulos */
Tarea tareaNula() {
    Tarea tarea;
    tarea.id = -1;
    tarea.idProyecto = -1;
    tarea.estado = -1;
    tarea.horas = -1;
    strcpy(tarea.nombre, "");
    strcpy(tarea.descripcion, "");

    return tarea;
}

/* Devuelve el id de la ultima tarea creada */
int tareaUltimoId() {
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

/* Busca tarea por su id y la devuelve */
Tarea tareaBuscarPorId(int id) {
    Tarea tarea = tareaNula();
    int flag = 0;

    FILE* pArchTareas = fopen(archTareas, "rb");
    if(pArchTareas) {
        while(flag == 0 && fread(&tarea, sizeof(Tarea), 1, pArchTareas)) {
            if(tarea.id == id) {
                flag == 1;
            }
        }
    }
    fclose(pArchTareas);

    return tarea;
}

/* Busca tarea por su id y devuelve su posicion en el archivo */
int tareaBuscarPosPorId(int id) {
    Tarea tarea;
    int posicion = -1;
    int flag = 0;

    FILE* pArchTareas = fopen(archTareas, "rb");
    if(pArchTareas) {
        while(flag == 0 && fread(&tarea, sizeof(Tarea), 1, pArchTareas)) {
            if(tarea.id == id) {
                posicion = ftell(pArchTareas)-sizeof(Tarea);
                flag == 1;
            }
        }
    }
    fclose(pArchTareas);

    return posicion;
}

/* Inicializa una lista de tareas */
nodoTarea* tareaInicLista() {
    return NULL;
}

/* Recibe una tarea y devuelve un nodo con esta */
nodoTarea* crearNodoTarea(Tarea t) {
    nodoTarea* nodo = malloc(sizeof(nodoTarea));

    nodo->tarea = t;
    nodo->siguiente = NULL;

    return nodo;
}

/* Inserta un nodo en una lista de tareas */
nodoTarea* insertarTareaLista(nodoTarea* lista, nodoTarea* nodo) {
    if(nodo) {
        nodo->siguiente = lista;
    }
    lista = nodo;

    return lista;
}

/* Recibe un id de proyecto y almacena en una lista todas las tareas cargadas en este */
nodoTarea* listaTareas(int idProyecto) {
    nodoTarea* lista = tareaInicLista();
    Tarea tarea;
    FILE* pArchTareas = fopen(archTareas, "rb");

    if(pArchTareas) {
        while(fread(&tarea, sizeof(Tarea), 1, pArchTareas)) {
            if(tarea.idProyecto == idProyecto && tarea.estado == 1) {
                lista = insertarTareaLista(lista, crearNodoTarea(tarea));
            }
        }
    }
    fclose(pArchTareas);

    return lista;
}

/**< CONTROLADORES */

/* Recibe una tarea y la persiste en el archivo */
int persistirTarea(Tarea tarea) {
    int flag = -1;
    int pos = tareaBuscarPosPorId(tarea.id);

    FILE* pArchTareas;

    // Si la tarea existe, la modifico
    if(pos > -1) {
        pArchTareas = fopen(archTareas, "rb+");
        if(pArchTareas) {
            fseek(pArchTareas, pos, SEEK_SET);
            fwrite(&tarea, sizeof(Tarea), 1, pArchTareas);
            flag = 1;
        }
        fclose(pArchTareas);
    }
    // Si la tarea no existe, la creo
    else {
        pArchTareas = fopen(archTareas, "ab");
        if(pArchTareas) {
            fwrite(&tarea, sizeof(Tarea), 1, pArchTareas);
            flag = 1;
        }
        fclose(pArchTareas);
    }

    return flag;
}

/* Recibe una nueva tarea y la guarda en el archivo */
int crearTarea(Tarea tarea) {
    int flag = -1;
    tarea.id = tareaUltimoId() + 1;
    flag = persistirTarea(tarea);

    return flag;
}

/* Recibe una tarea y la deshabilita en el archivo */
int eliminarTarea(Tarea tarea) {
    int flag = -1;
    tarea.estado = -1;
    flag = persistirTarea(tarea);

    return flag;
}
