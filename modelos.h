#ifndef MODELOS_H_INCLUDED
#define MODELOS_H_INCLUDED

typedef struct {
    char nombre[20];
    char descripcion[255];
    int horas;
    struct Tarea* siguiente;
} Tarea;

typedef struct {
    char nombre[20];
    char descripcion[255];
    int valorHora;
    struct Tarea* tareas;
} Proyecto;

typedef struct {
    int id;
    char usuario[20];
    char contrasena[20];
    char nombreApellido[20];
    Proyecto proyectos[10];
    struct Usuario* siguiente;
} Usuario;

#endif // MODELOS_H_INCLUDED
