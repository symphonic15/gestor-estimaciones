#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "modelos.h"
#include "usuarioVista.h"
#include "proyectoVista.h"
#include "tareaVista.h"
#include "interfaz/interface.h"

int main()
{
    // Maximizo la consola por defecto
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

    // Ejecuto el menu inicial
    vMenuUsuario();

    return 0;
}
