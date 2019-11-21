#ifndef USUARIO_CONTROLADOR_H_INCLUDED
#define USUARIO_CONTROLADOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modelos.h"

#define archUsuarios "usuarios.dat"
#define archProyectos "proyectos.dat"
#define archTareas "tareas.dat"

Usuario usuarioNulo();
Usuario buscarUsuario(char usuario[20]);
void registrarUsuario(Usuario usuario);
Usuario iniciarSesion(char usuario[20], char contrasena[20]);

#endif // USUARIO_CONTROLADOR_H_INCLUDED
