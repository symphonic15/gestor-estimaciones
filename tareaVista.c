#include "tareaVista.h"

/// HELPERS

void mostrarTarea(Tarea tarea) {
    char aux[300];
    strcpy(aux, tarea.nombre);
    strcat(aux, ": ");
    strcat(aux, tarea.descripcion);
    crearTextBox(aux);

    crearTextIntBox("Horas estimadas: ", tarea.horas);
}

/// VISTAS

void vOpcionTarea(int idProyecto, int idUsuario)
{
    int opcion = -1;
    nodo2* opciones = inicLista2();
    opciones = agregarOpcion(opciones, 1, "Tareas activas");
    opciones = agregarOpcion(opciones, 2, "Crear tarea");
    opciones = agregarOpcion(opciones, 3, "Modificar tarea");
    opciones = agregarOpcion(opciones, 4, "Generar estimacion");
    opciones = agregarOpcion(opciones, 5, "Salir");

    while(opcion != 5)
    {
        system("cls");

        printMenu(opciones);
        opcion = manejarMenu(opciones);

        switch(opcion) {
            case 1:
                system("cls");
                vListarTareas(idProyecto);
                break;
            case 2:
                system("cls");
                vCrearTarea(idProyecto);
                break;
            case 3:
                system("cls");
                vModificarTarea(idProyecto);
                break;
            case 4:
                system("cls");
                vGenerarEstimacion(idProyecto);
                break;
            case 5:
                system("cls");
                break;
        }
    }
}

void vListarTareas(int idProyecto) {
    nodoTarea* lista = listaTareas(idProyecto);

    if(lista) {
        while(lista) {
            mostrarTarea(lista->tarea);
            lista = lista->siguiente;
        }
    }
    else {
        crearTextBox("El proyecto seleccionado aun no tiene tareas creadas.");
    }

    getch();
}

void vCrearTarea(int idProyecto) {
    Tarea tarea;

    tarea.idProyecto = idProyecto;
    tarea.estado = 1;
    strcpy(tarea.nombre, responderText("Titulo: ").resp);
    strcpy(tarea.descripcion, responderText("Descripcion: ").resp);
    tarea.horas = responderInt("Horas estimadas: ");

    crearTarea(tarea);
}

void vModificarTarea(int idProyecto) {
    Tarea tarea;
    nodoTarea* lista = tareaInicLista();
    nodo2* opciones = inicLista2();
    int opcion = 0;
    char confirmar;
    char mensaje[80];

    // Selecciona la tarea a modificar
    lista = listaTareas(idProyecto);

    if(lista) {
        while(lista) {
            opciones = agregarOpcion(opciones, lista->tarea.id, lista->tarea.nombre);
            lista = lista->siguiente;
        }

        system("cls");
        printMenu(opciones);
        opcion = manejarMenu(opciones);

        if(opcion != -1) {
            tarea = tareaBuscarPorId(opcion);

            // Selecciona la modificacion a realizar
            opciones = inicLista2();

            opciones = agregarOpcion(opciones, 1, "Modificar titulo");
            opciones = agregarOpcion(opciones, 2, "Modificar descripcion");
            opciones = agregarOpcion(opciones, 3, "Modificar horas estimadas");
            opciones = agregarOpcion(opciones, 4, "Eliminar");

            system("cls");
            printMenu(opciones);
            opcion = manejarMenu(opciones);

            switch(opcion) {
            case 1:
                system("cls");
                strcpy(tarea.nombre, responderText("Nuevo nombre: ").resp);
                if(persistirTarea(tarea) == 1) {
                    system("cls");
                    strcpy(mensaje, "La tarea \"");
                    strcat(mensaje, tarea.nombre);
                    strcat(mensaje, "\" fue modificada exitosamente.");
                    crearTextBox(mensaje);
                    getch();
                }
                else {
                    system("cls");
                    crearTextBox("Hubo un error al modificar la tarea.");
                }
                break;
            case 2:
                system("cls");
                strcpy(tarea.descripcion, responderText("Nueva descripcion: ").resp);
                if(persistirTarea(tarea) == 1) {
                    system("cls");
                    strcpy(mensaje, "La tarea \"");
                    strcat(mensaje, tarea.nombre);
                    strcat(mensaje, "\" fue modificada exitosamente.");
                    crearTextBox(mensaje);
                    getch();
                }
                else {
                    system("cls");
                    crearTextBox("Hubo un error al modificar la tarea.");
                }
                break;
            case 3:
                system("cls");
                tarea.horas = responderInt("Nueva cantidad de horas estimada: ");
                if(persistirTarea(tarea) == 1) {
                    system("cls");
                    strcpy(mensaje, "La tarea \"");
                    strcat(mensaje, tarea.nombre);
                    strcat(mensaje, "\" fue modificada exitosamente.");
                    crearTextBox(mensaje);
                    getch();
                }
                else {
                    system("cls");
                    crearTextBox("Hubo un error al modificar la tarea.");
                }
                break;
            case 4:
                system("cls");
                mostrarTarea(tarea);
                crearTextBox("Presione Enter para eliminar la tarea.");
                confirmar = getch();
                if(confirmar == 13) {
                    if(eliminarTarea(tarea) == 1); {
                        system("cls");
                        strcpy(mensaje, "La tarea \"");
                        strcat(mensaje, tarea.nombre);
                        strcat(mensaje, "\" fue eliminada exitosamente");
                        crearTextBox(mensaje);
                        getch();
                    }
                }
                break;
            }
        }
    } else {
        crearTextBox("El proyecto seleccionado aun no tiene tareas creadas.");
        getch();
    }
}

void vGenerarEstimacion(int idProyecto) {
    Proyecto proyecto = proyectoBuscarPorId(idProyecto);
    nodoTarea* lista = tareaInicLista();
    lista = listaTareas(idProyecto);

    int valorHora;
    int total = 0;

    if(lista) {
        while(lista) {
            total = total + lista->tarea.horas;
            lista = lista->siguiente;
        }

        valorHora = responderInt("Ingrese el valor por hora: ");
        crearTextIntBox("Horas totales del proyecto: ", total);
        total = total*valorHora;
        crearTextIntBox("Valor estimado del proyecto: $", total);
        crearTextBox("Presione una tecla para salir.");
    }
    else {
        crearTextBox("Debe haber al menos una tarea creada en el proyecto.");
    }

    getch();
}
