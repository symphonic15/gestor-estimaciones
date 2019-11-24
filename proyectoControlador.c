#include "proyectoControlador.h"

/**< HELPERS */

/* Devuelve la cantidad de proyectos activos del usuario */
int proyectosActivosCantidad(int idUsuario) {
    int i = 0;
    Proyecto proyecto;
    FILE* pArchProyectos = fopen(archProyectos, "rb");

    if(pArchProyectos) {
        while(fread(&proyecto, sizeof(Proyecto), 1, pArchProyectos)) {
            if(proyecto.idUsuario == idUsuario && proyecto.estado != -1) {
                i++;
            }
        }
    }
    fclose(pArchProyectos);

    return i;
}

/* Devuelve el id del ultimo proyecto creado */
int proyectoUltimoId() {
    int id = 0;
    FILE* pArchProyectos = fopen(archProyectos, "rb");
    Proyecto pro;
    if(pArchProyectos){
        fseek(pArchProyectos,sizeof(Proyecto)*-1,SEEK_END);
        fread(&pro, sizeof(Proyecto), 1, pArchProyectos);
        id = pro.id;
    }
    fclose(pArchProyectos);
    return id;
}

/* Devuelve proyecto con datos nulos */
Proyecto proyectoNulo() {
    Proyecto proyecto;
    proyecto.id = -1;
    proyecto.idUsuario = -1;
    proyecto.estado = -1;
    strcpy(proyecto.descripcion, "");
    strcpy(proyecto.nombre, "");
    proyecto.tareas = NULL;

    return proyecto;
}

/* Busca proyecto por su id y lo devuelve */
Proyecto proyectoBuscarPorId(int id) {
    Proyecto proyecto;
    int flag = 0;

    FILE* pArchProyectos = fopen(archProyectos, "rb");
    if(pArchProyectos){
        while(flag == 0 && fread(&proyecto, sizeof(Proyecto), 1, pArchProyectos)) {
            if(proyecto.id == id) {
                flag = 1;
            }
        }
    }
    fclose(pArchProyectos);

    if(flag == 0) {
        proyecto = proyectoNulo();
    }

    return proyecto;
}

/* Busca proyecto por su id y devuelve su posicion en el archivo */
int proyectoBuscarPosPorId(int id) {
    int flag = 0;
    int pos = -1;
    Proyecto proyecto;
    FILE* pArchProyecto = fopen(archProyectos, "rb");

    if(pArchProyecto) {
        while(flag == 0 && fread(&proyecto, sizeof(Proyecto), 1, pArchProyecto)){
            if(proyecto.id==id){
                flag = 1;
                pos = ftell(pArchProyecto) - sizeof(Proyecto);
            }
        }
    }
    fclose(pArchProyecto);

    return pos;
}

/* Recibe un arreglo de proyectos y lo inicializa con proyectos nulos */
void proyectoInicArray(Proyecto proyectos[10]) {
    for(int i = 0; i<10; i++) {
        proyectos[i] = proyectoNulo();
    }
}

/* Recibe un arreglo de proyectos y le inserta todos los asociados al usuario */
void proyectoArchivo2Array(int idUsuario, Proyecto proyectos[10]) {
    Proyecto aux;
    int i = 0;
    FILE* pArchProyectos = fopen(archProyectos, "rb");
    if(pArchProyectos) {
        while(i <= 10 && fread(&aux, sizeof(Proyecto), 1, pArchProyectos)) {
            if(aux.idUsuario == idUsuario && aux.estado != -1) {
                proyectos[i] = aux;
                i++;
            }
        }
    }
    fclose(pArchProyectos);
}

/**< CONTROLADORES */

/* Recibe un proyecto y lo persiste en el archivo */
int persistirProyecto(Proyecto proyecto) {
    int flag = -1;
    int pos = proyectoBuscarPosPorId(proyecto.id);

    FILE* pArchProyectos;

    // Si el proyecto existe, lo modifico
    if(pos > -1) {
        pArchProyectos = fopen(archProyectos, "rb+");
        if(pArchProyectos) {
            fseek(pArchProyectos, pos, SEEK_SET);
            fwrite(&proyecto, sizeof(Proyecto), 1, pArchProyectos);
            flag = 1;
        }
        fclose(pArchProyectos);
    }
    // Si el proyecto no existe, lo creo
    else {
        pArchProyectos = fopen(archProyectos, "ab");
        if(pArchProyectos) {
            fwrite(&proyecto, sizeof(Proyecto), 1, pArchProyectos);
            flag = 1;
        }
        fclose(pArchProyectos);
    }

    return flag;
}

/* Recibe un nuevo proyecto y lo guarda en el archivo */
int crearProyecto(Proyecto proyecto) {
    int flag = -1;
    proyecto.id = proyectoUltimoId() + 1;
    flag = persistirProyecto(proyecto);

    return flag;
}

/* Recibe un proyecto y lo deshabilita en el archivo */
int eliminarProyecto(Proyecto proyecto) {
    int flag = -1;
    proyecto.estado = -1;
    flag = persistirProyecto(proyecto);

    return flag;
}
