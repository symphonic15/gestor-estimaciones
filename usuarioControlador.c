#include "usuarioControlador.h"

/**< HELPERS */

/* Devuelve la cantidad de usuarios registrados */
int usuariosActivosCantidad() {
    int i = 0;
    Usuario usuario;
    FILE* pArchUsuarios = fopen(archUsuarios, "rb");

    if(pArchUsuarios) {
        while(fread(&usuario, sizeof(Usuario), 1, pArchUsuarios)) {
            if(usuario.estado != -1) {
                i++;
            }
        }
    }
    fclose(pArchUsuarios);

    return i;
}

/* Devuelve ultimo id registrado en archivo */
int usuarioUltimoId() {
    int id = 0;
    FILE* pArchUsuarios = fopen(archUsuarios, "rb");
    Usuario usuario;
    if(pArchUsuarios) {
        fseek(pArchUsuarios,sizeof(Usuario)*-1,SEEK_END);
        fread(&usuario, sizeof(Usuario), 1, pArchUsuarios);
        id = usuario.id;
    }
    fclose(pArchUsuarios);
    return id;
}

/* Devuelve usuario con datos nulos */
Usuario usuarioNulo() {
    Usuario user;

    user.id = -1;
    strcpy(user.usuario, "");
    strcpy(user.contrasena, "");
    strcpy(user.nombreApellido, "");
    user.siguiente = NULL;

    return user;
}

/* Busca usuario por su id y lo devuelve */
Usuario usuarioBuscarPorId(int id) {
    Usuario usuario;
    int flag = 0;

    FILE* pArchUsuarios = fopen(archUsuarios, "rb");
    if(pArchUsuarios){
        while(flag == 0 && fread(&usuario, sizeof(Proyecto), 1, pArchUsuarios)) {
            if(usuario.id == id) {
                flag = 1;
            }
        }
    }
    fclose(pArchUsuarios);

    if(flag == 0) {
        usuario = usuarioNulo();
    }

    return usuario;
}

/* Busca usuario por nombre y lo devuelve */
Usuario usuarioBuscarPorNombre(char usuario[20]) {
    Usuario user;
    int flag = 0;

    FILE* pArchUsuarios = fopen(archUsuarios, "rb");
    if(pArchUsuarios) {
        while(flag == 0 && fread(&user, sizeof(Usuario), 1, pArchUsuarios)) {
            if(strcmp(user.usuario, usuario) == 0) {
                flag = 1;
            }
        }
    }
    fclose(pArchUsuarios);

    if(flag == 0) {
        user = usuarioNulo();
    }

    return user;
}

/* Busca un usuario por su id y devuelve su posicion en el archivo */
int usuarioBuscarPosPorId(int id) {
    Usuario usuario;
    int posicion = -1;
    int flag = 0;

    FILE* pArchUsuarios = fopen(archUsuarios, "rb");
    if(pArchUsuarios) {
        while(flag == 0 && fread(&usuario, sizeof(Usuario), 1, pArchUsuarios)) {
            if(usuario.id == id) {
                posicion = ftell(pArchUsuarios)-sizeof(Usuario);
                flag == 1;
            }
        }
    }
    fclose(pArchUsuarios);

    return posicion;
}

/* Inicializa una lista de usuarios */
nodoUsuario* usuarioInicLista() {
    return NULL;
}

nodoUsuario* usuarioCrearNodo(Usuario usuario) {
    nodoUsuario* nodo = malloc(sizeof(nodoUsuario));

    nodo->usuario = usuario;
    nodo->siguiente = NULL;

    return nodo;
}

nodoUsuario* usuarioInsertarLista(nodoUsuario* lista, nodoUsuario* nodo) {
    if(nodo) {
        nodo->siguiente = lista;
    }
    lista = nodo;

    return lista;
}

nodoUsuario* usuariosLista() {
    nodoUsuario* lista = usuarioInicLista();
    Usuario usuario;
    FILE* pArchUsuarios = fopen(archUsuarios, "rb");

    if(pArchUsuarios) {
        while(fread(&usuario, sizeof(Usuario), 1, pArchUsuarios)) {
            if(usuario.estado == 1) {
                lista = usuarioInsertarLista(lista, usuarioCrearNodo(usuario));
            }
        }
    }
    fclose(pArchUsuarios);

    return lista;
}

/**< CONTROLADORES */

/* Recibe un usuario y lo guarda en el archivo */
int persistirUsuario(Usuario usuario) {
    int flag = -1;
    int pos = usuarioBuscarPosPorId(usuario.id);

    FILE* pArchUsuarios;

    // Si el usuario existe, lo modifico
    if(pos > -1) {
        pArchUsuarios = fopen(archUsuarios, "rb+");
        if(pArchUsuarios) {
            fseek(pArchUsuarios, pos, SEEK_SET);
            fwrite(&usuario, sizeof(Usuario), 1, pArchUsuarios);
            flag = 1;
        }
        fclose(pArchUsuarios);
    }
    // Si el usuario no existe, lo creo
    else {
        pArchUsuarios = fopen(archUsuarios, "ab");
        if(pArchUsuarios) {
            fwrite(&usuario, sizeof(Usuario), 1, pArchUsuarios);
            flag = 1;
        }
        fclose(pArchUsuarios);
    }

    return flag;
}

/* Recibe un usuario y lo guarda en el archivo */
int registrarUsuario(Usuario usuario) {
    int flag = -1;
    if(usuarioBuscarPorNombre(usuario.usuario).id < 0) {
        usuario.id = usuarioUltimoId() + 1;
        flag = persistirUsuario(usuario);
    }

    return flag;
}

/* Recibe un usuario y lo deshabilita en el archivo */
int eliminarUsuario(Usuario usuario) {
    int flag = -1;
    usuario.estado = -1;
    flag = persistirUsuario(usuario);

    return flag;
}

/* Recibe un nombre de usuario y contraseña y devuelve los datos del usuario si son correctos */
Usuario iniciarSesion(char usuario[20], char contrasena[20]) {
    Usuario user = usuarioBuscarPorNombre(usuario);

    // Si el usuario no existe o la contrasena es incorrecta
    if(strcmp(user.usuario, "") == 0 || strcmp(user.contrasena, contrasena) != 0) {
        user = usuarioNulo();
    }

    return user;
}
