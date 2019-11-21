#ifndef PROYECTO_CONTROLADOR_H_INCLUDED
#define PROYECTO_CONTROLADOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modelos.h"

#define archUsuarios "usuarios.dat"
#define archProyectos "proyectos.dat"
#define archTareas "tareas.dat"

int buscarUltimoIdPro();
void crearProyecto(Proyecto aux);
int validarProyecto(Proyecto a);
Proyecto buscarProyectoNom(char nom[20]);
void eliminarProyecto(Proyecto a);
void modificarNombreProyecto(Proyecto a, char nombre[20]);
void modificarDescripcionProyecto(Proyecto a, char descripcion[255]);
void modificarValorProyecto(Proyecto a, int valor);
void inicArrayProyectos(Proyecto a[10]);
void archivo2ArrayProyecto(int idUser, Proyecto a[10]);

#endif // PROYECTO_CONTROLADOR_H_INCLUDED
