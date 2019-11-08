#ifndef USUARIO_VISTA_H_INCLUDED
#define USUARIO_VISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modelos.h"
#include "controladores.h"

void vRegistrarUsuario();
Usuario vIniciarSesion();
Tarea vCrearTarea(Proyecto p);
#endif // USUARIO_VISTA_H_INCLUDED
