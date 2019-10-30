#include "vistas.h"

void vRegistrarUsuario() {
    Usuario usuario;

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
        printf("Usuario y/o contrasena incorrecta");
    }
}
