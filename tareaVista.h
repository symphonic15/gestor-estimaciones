#ifndef TAREA_VISTAS_H_INCLUDED
#define TAREA_VISTAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modelos.h"
#include "tareaControlador.h"
#include "proyectoVista.h"
#include "interfaz/interface.h"

#define archUsuarios "usuarios.dat"
#define archProyectos "proyectos.dat"
#define archTareas "tareas.dat"

void mostrarTarea(Tarea tarea);
void vOpcionTarea(int idProyecto, int idUsuario);
int vMenuModificacionTar();
void vListarTareas(int idProyecto);
void vCrearTarea(int idProyecto);
void vGenerarEstimacion(int idProyecto);
void vEliminarTarea(int idProyecto);
void vModificarTarea(int idProyecto);
void vModificarTareaDatos(Tarea t);

#endif // TAREA_VISTAS_H_INCLUDED
