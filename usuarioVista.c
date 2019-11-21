#include "usuarioVista.h"

void vRegistrarUsuario(int rol) {
    Usuario usuario;

    usuario.rol = rol;
    printf("Nombre de usuario:\n");
    gets(usuario.usuario);
    printf("Contrasena:\n");
    gets(usuario.contrasena);
    printf("Nombre y apellido:\n");
    gets(usuario.nombreApellido);
    usuario.siguiente = NULL;

    registrarUsuario(usuario);
}

Usuario vIniciarSesion() {
    Usuario user;
    char usuario[20];
    char contrasena[20];

    printf("Usuario:\n");
    gets(usuario);
    printf("Contrasena:\n");
    gets(contrasena);

    user = iniciarSesion(usuario, contrasena);

    if(strcmp(user.usuario, "") == 0) {
        system("cls");
        printf("Usuario y/o contrasena incorrecta. Por favor, intente nuevamente.\n\n");
        user = vIniciarSesion();
    }

    return user;
}
