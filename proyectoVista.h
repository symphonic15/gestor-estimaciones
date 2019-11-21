#ifndef PROYECTO_VISTA_H_INCLUDED
#define PROYECTO_VISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modelos.h"
#include "proyectoControlador.h"

#define archUsuarios "usuarios.dat"
#define archProyectos "proyectos.dat"
#define archTareas "tareas.dat"

Proyecto vCrearProyecto();
void vModificarProyecto(int id);
void vEliminarProyecto(Proyecto a);
void vModificarNombreProyecto(Proyecto a);
void vModificarDescripcionProyecto(Proyecto a);
void vModificarValorProyecto(Proyecto a);
void vMostrarProyecto(Proyecto a);
void vListarProyectos(Proyecto a[10]);
void vListarProUser(Usuario a);

#endif // PROYECTO_VISTA_H_INCLUDED
