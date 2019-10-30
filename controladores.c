#include "controladores.h"

Usuario usuarioNulo() {
    Usuario user;

    strcpy(user.usuario, "");
    strcpy(user.contrasena, "");
    strcpy(user.nombreApellido, "");
    user.siguiente = NULL;

    return user;
}

Usuario buscarUsuario(char usuario[20]) {
    Usuario user;
    int flag = 0;

    FILE* pArchUsuarios = fopen(archUsuarios, "rb");
    while(fread(&user, sizeof(Usuario), 1, pArchUsuarios) && flag == 0) {
        if(strcmp(user.usuario, usuario) == 0) {
            flag = 1;
        }
    }
    fclose(pArchUsuarios);

    if(flag == 0) user = usuarioNulo();

    return user;
}

void registrarUsuario(Usuario usuario) {
    FILE* pArchUsuarios = fopen(archUsuarios, "ab");
    fwrite(&usuario, sizeof(Usuario), 1, pArchUsuarios);
}

Usuario iniciarSesion(char usuario[20], char contrasena[20]) {
    Usuario user = buscarUsuario(usuario);

    // Si el usuario existe
    if(strcmp(user.usuario, "") == 0 || strcmp(user.contrasena, contrasena) != 0) {
        user = usuarioNulo();
    }

    return user;
}
