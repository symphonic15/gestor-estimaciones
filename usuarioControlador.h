#ifndef USUARIO_CONTROLADOR_H_INCLUDED
#define USUARIO_CONTROLADOR_H_INCLUDED

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#include "modelos.h"

#define archUsuarios "usuarios.dat"
#define archProyectos "proyectos.dat"
#define archTareas "tareas.dat"

int usuarioUltimoId();
Usuario usuarioNulo();
Usuario usuarioBuscarPorId(int id);
Usuario usuarioBuscarPorNombre(char usuario[20]);
int usuarioBuscarPosPorId(int id);
nodoUsuario* crearNodoUsuario(Usuario usuario);
nodoUsuario* insertarUsuarioLista(nodoUsuario* lista, nodoUsuario* nodo);
nodoUsuario* listaUsuarios();
int persistirUsuario(Usuario usuario);
int registrarUsuario(Usuario usuario);
Usuario iniciarSesion(char usuario[20], char contrasena[20]);

#endif // USUARIO_CONTROLADOR_H_INCLUDED
