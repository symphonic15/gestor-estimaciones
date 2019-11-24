#include "proyectoVista.h"

/**< HELPERS */

/* Recibe un proyecto y lo muestra */
void mostrarProyecto(Proyecto proyecto)
{
    char aux[300];
    strcpy(aux, proyecto.nombre);
    strcat(aux, ":  ");
    strcat(aux, proyecto.descripcion);
    crearTextBox(aux);
}

/**< VISTAS */

/* Menu principal de gestion de proyectos */
void vMenuProyecto(Usuario sesion)
{
    int opcion = -1;
    char confirmar;
    nodo2* opciones = inicLista2();

    opciones = agregarOpcion(opciones, 1, "Proyectos activos");
    opciones = agregarOpcion(opciones, 2, "Seleccionar proyecto");
    opciones = agregarOpcion(opciones, 3, "Crear proyecto");
    opciones = agregarOpcion(opciones, 4, "Modificar proyecto");
    opciones = agregarOpcion(opciones, 5, "Cerrar sesion");

    while(opcion != 6)
    {
        system("cls");

        printMenu(opciones);
        opcion = manejarMenu(opciones);

        switch(opcion) {
        case 1:
            system("cls");
            vListarProyectos(sesion.id);
            break;
        case 2:
            system("cls");
            vSeleccionarProyecto(sesion.id);
            break;
        case 3:
            system("cls");
            vCrearProyecto(sesion.id);
            break;
        case 4:
            system("cls");
            vModificarProyecto(sesion.id);
            break;
        case 5:
            system("cls");
            crearTextBox("Presione Enter para cerrar sesion.");
            confirmar = getch();
            if(confirmar == 13) {
                opcion = 6;
            }
            break;
        }
    }
}

/* Muestra los proyectos activos del usuario */
void vListarProyectos(int idUsuario)
{
    Proyecto proyectos[10];
    proyectoInicArray(proyectos);
    proyectoArchivo2Array(idUsuario, proyectos);

    if(proyectos[0].estado > -1) {
        for(int i = 0; i<10; i++)
        {
            if(proyectos[i].estado == 1)
            {
                mostrarProyecto(proyectos[i]);
            }
        }
    }
    else {
        system("cls");
        crearTextBox("Aun no tienes proyectos creados.");
    }

    getch();
}

/* Selecciona un proyecto y accede al menu de gestion de sus tareas */
void vSeleccionarProyecto(int idUsuario)
{
    Proyecto proyectos[10];
    nodo2* opciones = inicLista2();
    int opcion;

    proyectoInicArray(proyectos);
    proyectoArchivo2Array(idUsuario, proyectos);

    if(proyectos[0].estado > -1) {
        for(int i=0; i<10; i++)
        {
            if(proyectos[i].estado == 1)
            {
                opciones = agregarOpcion(opciones, proyectos[i].id, proyectos[i].nombre);
            }
        }

        printMenu(opciones);
        opcion = manejarMenu(opciones);

        if(opcion == -1) {
            return;
        }

        system("cls");
        vOpcionTarea(opcion, idUsuario);
    }
    else {
        system("cls");
        crearTextBox("Aun no tienes proyectos creados.");
        getch();
    }
}

/* Formulario de creacion de proyecto */
void vCrearProyecto(int idUsuario)
{
    Proyecto proyecto;
    char mensaje[80];

    if(proyectosActivosCantidad(idUsuario) < 10) {
        proyecto.estado = 1;
        proyecto.idUsuario = idUsuario;

        system("cls");
        strcpy(proyecto.nombre, responderText("Ingrese nombre de proyecto: ").resp);
        strcpy(proyecto.descripcion, responderText("Ingrese descripcion: ").resp);

        if(crearProyecto(proyecto) == 1) {
            system("cls");
            strcpy(mensaje, "El proyecto \"");
            strcat(mensaje, proyecto.nombre);
            strcat(mensaje, "\" fue creado exitosamente.");
            crearTextBox(mensaje);
            getch();
        }
    }
    else {
        system("cls");
        crearTextBox("No puedes tener mas de 10 proyectos activos.");
        getch();
    }
}

/* Formulario de modificacion/eliminacion de proyecto */
void vModificarProyecto(int idUsuario)
{
    Proyecto proyecto;
    Proyecto proyectos[10];
    nodo2* opciones = inicLista2();
    int opcion = 0;
    char confirmar;
    char mensaje[80];

    // Selecciona el proyecto a modificar
    proyectoInicArray(proyectos);
    proyectoArchivo2Array(idUsuario, proyectos);

    for(int i=0; i<10; i++) {
        if(proyectos[i].estado == 1) {
            opciones = agregarOpcion(opciones, proyectos[i].id, proyectos[i].nombre);
        }
    }

    system("cls");
    printMenu(opciones);
    opcion = manejarMenu(opciones);

    if(opcion != -1) {
        proyecto = proyectoBuscarPorId(opcion);

        // Selecciona la modificacion a realizar
        opciones = inicLista2();

        opciones = agregarOpcion(opciones, 1, "Modificar nombre");
        opciones = agregarOpcion(opciones, 2, "Modificar descripcion");
        opciones = agregarOpcion(opciones, 3, "Eliminar");

        system("cls");
        printMenu(opciones);
        opcion = manejarMenu(opciones);

        switch(opcion) {
        case 1:
            system("cls");
            strcpy(proyecto.nombre, responderText("Ingrese el nuevo nombre: ").resp);
            persistirProyecto(proyecto);
            break;
        case 2:
            system("cls");
            strcpy(proyecto.descripcion, responderText("Ingrese la nueva descripcion: ").resp);
            persistirProyecto(proyecto);
            break;
        case 3:
            system("cls");
            mostrarProyecto(proyecto);
            crearTextBox("Presione Enter para eliminar el proyecto.");
            confirmar = getch();
            if(confirmar == 13) {
                if(eliminarProyecto(proyecto) == 1); {
                    system("cls");
                    strcpy(mensaje, "El proyecto \"");
                    strcat(mensaje, proyecto.nombre);
                    strcat(mensaje, "\" fue eliminado exitosamente.");
                    crearTextBox(mensaje);
                    getch();
                }
            }
            break;
        }
    }
}
