#ifndef TAREA_CONTROLADOR_H_INCLUDED
#define TAREA_CONTROLADOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modelos.h"

#define archUsuarios "usuarios.dat"
#define archProyectos "proyectos.dat"
#define archTareas "tareas.dat"

nodoTarea* inicLista();
int buscarUltimoIdTarea();
int buscarTareaPorId(int id);

void crearTarea(Tarea t);
void modificarTarea(int id, Tarea t);
void eliminarTarea(Tarea t);
nodoTarea* crearNodoTarea(Tarea t);
nodoTarea* ultimaTareaLista(nodoTarea* lista);
nodoTarea* insertarTareaLista(nodoTarea* lista, nodoTarea* nodo);
nodoTarea* listaTareas(int idProyecto);

#endif // TAREA_CONTROLADOR_H_INCLUDED
