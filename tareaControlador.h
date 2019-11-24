#ifndef TAREA_CONTROLADOR_H_INCLUDED
#define TAREA_CONTROLADOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modelos.h"

#define archUsuarios "usuarios.dat"
#define archProyectos "proyectos.dat"
#define archTareas "tareas.dat"

nodoTarea* tareaInicLista();
Tarea tareaNula();
int tareaUltimoId();
Tarea tareaBuscarPorId(int id);
int tareaBuscarPosPorId(int id);
nodoTarea* crearNodoTarea(Tarea t);
nodoTarea* ultimaTareaLista(nodoTarea* lista);
nodoTarea* insertarTareaLista(nodoTarea* lista, nodoTarea* nodo);
nodoTarea* listaTareas(int idProyecto);
int crearTarea(Tarea tarea);
int eliminarTarea(Tarea tarea);

#endif // TAREA_CONTROLADOR_H_INCLUDED
