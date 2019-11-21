#include "tareaVista.h"

/* HELPERS */

void mostrarTarea(Tarea t) {
    printf("-----------------------------------------\n");
    printf("Titulo: %s.\n", t.nombre);
    printf("Descripcion: %s.\n", t.descripcion);
    printf("Horas estimadas: %i.\n", t.horas);
    printf("-----------------------------------------\n");
}

/* VISTAS */

void vCrearTarea(int idProyecto) {
    Tarea tarea;

    tarea.idProyecto = idProyecto;
    printf("Titulo:\n");
    gets(tarea.nombre);
    printf("Descripcion:\n");
    gets(tarea.descripcion);
    printf("Horas estimadas:\n");
    scanf("%i", tarea.horas);

    crearTarea(tarea);
}

void vModificarTarea(Tarea t) {
    Tarea tarea = t;
    char opcion;

    printf("Seleccione el valor que desee modificar:\n");
    printf("1. Titulo.\n");
    printf("2. Descripcion.\n");
    printf("3. Horas estimadas.\n");
    printf("Esc. Cancelar.\n");

    getch(opcion);

    switch(opcion) {
        case '1':
            printf("Titulo:\n");
            gets(tarea.nombre);
            break;
        case '2':
            printf("Descripcion:\n");
            gets(tarea.descripcion);
            break;
        case '3':
            printf("Horas estimadas:\n");
            scanf("%i", tarea.horas);
            break;
        default:

            break;
    }

    modificarTarea(t.id, tarea);
}

void vEliminarTarea(Tarea t) {
    char opcion;

    printf("%s\nEsta seguro/a que desea eliminar esta tarea?\n");
    printf("1. Si.");
    printf("2. No.");

    getch(opcion);

    if(opcion == '1') {
        eliminarTarea(t);
    }
}

void vListaTareas(int idProyecto) {
    nodoTarea* lista = listaTareas(idProyecto);

    if(lista) {
        while(lista) {
            mostrarTarea(lista->tarea);
        }
    }
    else {
        printf("-----------------------------------------\n");
        printf("El proyecto seleccionado no tiene tareas creadas");
        printf("-----------------------------------------\n");
    }
}
