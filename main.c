#include <stdio.h>
#include <stdlib.h>
#include "modelos.h"
#include "interfaz.h"

int main()
{
    Usuario sesion;
    sesion = vIniciarSesion();

    printf("USUARIO SESION: %s", sesion.usuario);

    return 0;
}
