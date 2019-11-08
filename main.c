#include <stdio.h>
#include <stdlib.h>
#include "modelos.h"
#include "controladores.h"
#include "vistas.h"

int main()
{
    Usuario sesion;
    sesion = vIniciarSesion();

    printf("USUARIO SESION: %s", sesion.usuario);

    return 0;
}
