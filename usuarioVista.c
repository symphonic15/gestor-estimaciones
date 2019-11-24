#include "usuarioVista.h"

/**< HELPERS */

void mostrarUsuario(Usuario usuario) {
    char aux[300];
    strcpy(aux, usuario.nombreApellido);
    strcat(aux, ": ");
    strcat(aux, usuario.usuario);
    strcat(aux, ". (");
    if(usuario.rol == 0) {
        strcat(aux, "Administrador");
    }
    else {
        strcat(aux, "Cliente");
    }
    strcat(aux, ")");
    crearTextBox(aux);
}

/**< VISTAS */

/* Menu de login/signup */
void vMenuUsuario() {
    Usuario sesion;
    int opcion;

    while(1) {
        if(usuariosActivosCantidad() != 0) {
            system("cls");
            nodo2* opciones = inicLista2();
            opciones = agregarOpcion(opciones, 1, "Registrarse");
            opciones = agregarOpcion(opciones, 2, "Iniciar sesion");

            printMenu(opciones);
            opcion = manejarMenu(opciones);

            switch(opcion) {
                case 1:
                    system("cls");
                    sesion = vRegistrarUsuario(1);
                    vMenuProyecto(sesion);
                    break;
                case 2:
                    system("cls");
                    sesion = vIniciarSesion();
                    if(sesion.rol == 0) {
                        vMenuUsuarioAdministrador();
                    }
                    else {
                        vMenuProyecto(sesion);
                    }
                    break;
            }
        }
        else {
            system("cls");
            crearTextBox("Por favor, complete los siguientes datos para crear el primer usuario administrador.");
            vRegistrarUsuario(0);
        }
    }
}

/* Panel de administracion */
void vMenuUsuarioAdministrador() {
    Usuario sesion;
    int opcion;
    char confirmar;

    while(opcion != 4) {
        system("cls");
        nodo2* opciones = inicLista2();
        opciones = agregarOpcion(opciones, 1, "Usuarios registrados");
        opciones = agregarOpcion(opciones, 2, "Registrar usuario");
        opciones = agregarOpcion(opciones, 3, "Modificar usuario");
        opciones = agregarOpcion(opciones, 4, "Cerrar sesion");

        printMenu(opciones);
        opcion = manejarMenu(opciones);

        switch(opcion) {
            case 1:
                system("cls");
                vListarUsuarios();
                break;
            case 2:
                system("cls");
                vCrearUsuario();
                break;
            case 3:
                system("cls");
                vModificarUsuario();
                break;
            case 4:
                system("cls");
                crearTextBox("Presione Enter para cerrar sesion.");
                confirmar = getch();
                if(confirmar == 13) {
                    opcion = 4;
                }
                break;
        }
    }
}

/* Formulario de registro */
Usuario vRegistrarUsuario(int rol) {
    Usuario usuario;
    char contrasena[20];

    usuario.rol = rol;
    usuario.estado = 1;
    strcpy(usuario.usuario, responderText("Nombre de usuario: ").resp);
    strcpy(usuario.contrasena, responderText("Contrasena: ").resp);
    strcpy(usuario.nombreApellido, responderText("Nombre y apellido: ").resp);
    usuario.siguiente = NULL;

    if(registrarUsuario(usuario) > -1) {
        usuario = usuarioBuscarPorNombre(usuario.usuario);
    }
    else {
        system("cls");
        crearTextBox("El nombre de usuario ingresado ya se encuentra en uso. Por favor, ingrese uno diferente.");
        usuario = vRegistrarUsuario(rol);
    }

    return usuario;
}

/* Formulario de inicio de sesion */
Usuario vIniciarSesion() {
    Usuario usuario;
    char nombreUsuario[20];
    char contrasena[20];

    strcpy(nombreUsuario, responderText("Usuario: ").resp);
    strcpy(contrasena, responderText("Contrasena: ").resp);

    usuario = iniciarSesion(nombreUsuario, contrasena);

    if(usuario.id < 0) {
        system("cls");
        crearTextBox("Usuario y/o contrasena incorrecta. Por favor, intente nuevamente.");
        usuario = vIniciarSesion();
    }

    return usuario;
}

/* Lista de usuarios registrados */
void vListarUsuarios() {
    nodoUsuario* lista = usuariosLista();

    if(lista) {
        while(lista) {
            mostrarUsuario(lista->usuario);
            lista = lista->siguiente;
        }
    }

    getch();
}

/* Panel de creacion de usuario (administrador) */
void vCrearUsuario() {
    Usuario usuario;
    nodo2* opciones = inicLista2();
    int opcion = 0;
    char mensaje[80];

    opciones = inicLista2();

    opciones = agregarOpcion(opciones, 1, "Administrador");
    opciones = agregarOpcion(opciones, 2, "Cliente");
    opciones = agregarOpcion(opciones, 3, "Volver");

    system("cls");
    printMenu(opciones);
    opcion = manejarMenu(opciones);

    switch(opcion) {
    case 1:
        system("cls");
        vRegistrarUsuario(0);
        break;
    case 2:
        system("cls");
        vRegistrarUsuario(1);
        break;
    case 3:
        system("cls");
        break;
    }
}

/* Modificacion de usuario */
void vModificarUsuario() {
    Usuario usuario;
    nodoUsuario* lista = usuarioInicLista();
    nodo2* opciones = inicLista2();
    int opcion = 0;
    char confirmar;
    char mensaje[80];

    // Selecciona el usuario a modificar
    lista = usuariosLista();

    if(lista) {
        while(lista) {
            opciones = agregarOpcion(opciones, lista->usuario.id, lista->usuario.usuario);
            lista = lista->siguiente;
        }

        system("cls");
        printMenu(opciones);
        opcion = manejarMenu(opciones);

        if(opcion != -1) {
            usuario = usuarioBuscarPorId(opcion);

            // Selecciona la modificacion a realizar
            opciones = inicLista2();

            opciones = agregarOpcion(opciones, 1, "Modificar nombre de usuario");
            opciones = agregarOpcion(opciones, 2, "Modificar nombre y apellido");
            opciones = agregarOpcion(opciones, 3, "Eliminar");

            system("cls");
            printMenu(opciones);
            opcion = manejarMenu(opciones);

            switch(opcion) {
            case 1:
                system("cls");
                strcpy(usuario.usuario, responderText("Nuevo nombre de usuario: ").resp);
                if(persistirUsuario(usuario) == 1) {
                    system("cls");
                    strcpy(mensaje, "El usuario \"");
                    strcat(mensaje, usuario.usuario);
                    strcat(mensaje, "\" fue modificado exitosamente.");
                    crearTextBox(mensaje);
                    getch();
                }
                else {
                    system("cls");
                    crearTextBox("Hubo un error al modificar el usuario.");
                }
                break;
            case 2:
                system("cls");
                strcpy(usuario.nombreApellido, responderText("Nuevo nombre y apellido: ").resp);
                if(persistirUsuario(usuario) == 1) {
                    system("cls");
                    strcpy(mensaje, "El usuario \"");
                    strcat(mensaje, usuario.usuario);
                    strcat(mensaje, "\" fue modificado exitosamente.");
                    crearTextBox(mensaje);
                    getch();
                }
                else {
                    system("cls");
                    crearTextBox("Hubo un error al modificar el usuario.");
                }
                break;
            case 3:
                system("cls");
                if(usuario.rol != 0) {
                    mostrarUsuario(usuario);
                    crearTextBox("Presione Enter para eliminar el usuario.");
                    confirmar = getch();
                    if(confirmar == 13) {
                        if(eliminarUsuario(usuario) == 1); {
                            system("cls");
                            strcpy(mensaje, "El usuario \"");
                            strcat(mensaje, usuario.usuario);
                            strcat(mensaje, "\" fue eliminado exitosamente");
                            crearTextBox(mensaje);
                            getch();
                        }
                    }
                }
                else {
                    crearTextBox("No es posible eliminar un usuario administrador.");
                    getch();
                }
                break;
            }
        }
    }
}
