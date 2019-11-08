#include "tareaVista.h"

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

void listaTareas(int idProyecto) {

}
