#ifndef MODELOS_H_INCLUDED
#define MODELOS_H_INCLUDED

typedef struct {
    int id;
    int idProyecto;
    int estado;
    char nombre[20];
    char descripcion[255];
    int horas;
} Tarea;

typedef struct {
    Tarea tarea;
    struct nodoTarea* siguiente;
} nodoTarea;

typedef struct {
    int id;
    int idUsuario;
    int estado;
    char nombre[20];
    char descripcion[255];
    int valorHora;
    struct nodoTarea* tareas;
} Proyecto;

typedef struct {
    int id;
    int rol;
    char usuario[20];
    char contrasena[20];
    char nombreApellido[20];
    Proyecto proyectos[10];
    struct Usuario* siguiente;
} Usuario;

#endif // MODELOS_H_INCLUDED
