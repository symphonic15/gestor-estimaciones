#ifndef PROYECTO_CONTROLADOR_H_INCLUDED
#define PROYECTO_CONTROLADOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modelos.h"

#define archUsuarios "usuarios.dat"
#define archProyectos "proyectos.dat"
#define archTareas "tareas.dat"

int proyectosActivosCantidad(int idUsuario);
int proyectoUltimoId();
Proyecto proyectoNulo();
Proyecto proyectoBuscarPorId(int id);
int proyectoBuscarPosPorId(int id);
void proyectoInicArray(Proyecto proyectos[10]);
void proyectoArchivo2Array(int idUsuario, Proyecto proyectos[10]);
int persistirProyecto(Proyecto proyecto);
int crearProyecto(Proyecto proyecto);
int eliminarProyecto(Proyecto proyecto);

#endif // PROYECTO_CONTROLADOR_H_INCLUDED
