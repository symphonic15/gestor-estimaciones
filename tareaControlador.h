#ifndef TAREA_CONTROLADOR_H_INCLUDED
#define TAREA_CONTROLADOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modelos.h"

#define archUsuarios "usuarios.dat"
#define archTareas "tareas.dat"

int buscarUltimoIdTar();
Proyecto crearTarea(Proyecto proyecto, Tarea* tarea);

#endif // TAREA_CONTROLADOR_H_INCLUDED
