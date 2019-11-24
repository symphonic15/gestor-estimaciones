#ifndef USUARIO_VISTA_H_INCLUDED
#define USUARIO_VISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modelos.h"
#include "usuarioControlador.h"
#include "interfaz/interface.h"

#define archUsuarios "usuarios.dat"
#define archProyectos "proyectos.dat"
#define archTareas "tareas.dat"

void vMenuUsuario();
Usuario vRegistrarUsuario(int rol);
Usuario vIniciarSesion();

#endif // USUARIO_VISTA_H_INCLUDED
