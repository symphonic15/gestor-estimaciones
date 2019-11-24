#ifndef PROYECTO_VISTA_H_INCLUDED
#define PROYECTO_VISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modelos.h"
#include "proyectoControlador.h"
#include "tareaVista.h"
#include "interfaz/interface.h"

#define archUsuarios "usuarios.dat"
#define archProyectos "proyectos.dat"
#define archTareas "tareas.dat"

void mostrarProyecto(Proyecto proyecto);
void vMenuProyecto(Usuario sesion);
void vSeleccionarProyecto(int idUsuario);
void vCrearProyecto(int idUsuario);
void vModificarProyecto(int idUsuario);
void vEliminarProyecto(int idUsuario);
void vListarProyectos(int idUsuario);

#endif // PROYECTO_VISTA_H_INCLUDED
