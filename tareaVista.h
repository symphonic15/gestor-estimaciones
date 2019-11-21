#ifndef TAREA_VISTAS_H_INCLUDED
#define TAREA_VISTAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modelos.h"
#include "tareaControlador.h"

#define archUsuarios "usuarios.dat"
#define archProyectos "proyectos.dat"
#define archTareas "tareas.dat"

void mostrarTarea(Tarea t);

void vCrearTarea(int idProyecto);
void vModificarTarea(Tarea t);
void vEliminarTarea(Tarea t);
void vListaTareas(int idProyecto);

#endif // TAREA_VISTAS_H_INCLUDED
