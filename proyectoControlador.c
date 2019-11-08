#include "proyectoControlador.h"

int buscarUltimoIdPro(){ /// BUSCA ULTIMO ID
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

Proyecto proyectoNulo(){ /// RETORNA PROYECTO VACIO
    Proyecto pro;
    strcpy(pro.descripcion,"");
    strcpy(pro.nombre, "");
    pro.tareas = NULL;
    pro.valorHora = 0;

    return pro;
}

void crearProyecto(Proyecto aux){ /// CREA UN PROYECTO EN EL ARCHIVO
    FILE* pArchProyectos = fopen(archProyectos, "ab");
    aux.id = 1+ buscarUltimoIdPro();
    if(pArchProyectos){
        fwrite(&aux, sizeof(Proyecto), 1, pArchProyectos);
    }
    fclose(pArchProyectos);
}

int validarProyecto(Proyecto a){ /// CONTROLA EXISTENCI DE PROYECTO
    FILE* pArchProyectos = fopen(archProyectos, "rb");
    Proyecto pro;
    int flag = 0;
    if(pArchProyectos){
        while(fread(&pro, sizeof(Proyecto), 1, pArchProyectos) && flag == 0){
            if((strcmp(pro.nombre, a.nombre) == 0)&&(pro.estado == 1)){
                flag = 1;
            }
        }
    }
    fclose(pArchProyectos);
    return flag; /// SI EXISTE RETORNA 1
}

Proyecto buscarProyectoNom(char nom[20]){ /// BUSCA PROYECTO POR NOMBRE
    Proyecto pro;
    FILE* pArchProyectos = fopen(archProyectos, "rb");
    int flag = 0;
    if(pArchProyectos){
        while(fread(&pro, sizeof(Proyecto), 1, pArchProyectos) && flag == 0) {
            if(strcmp(pro.nombre, nom) == 0) {
                flag = 1;
            }
        }
    }
    fclose(pArchProyectos);

    if(flag == 0) pro = proyectoNulo();
    return pro;
}

void eliminarProyecto(Proyecto a){ /// DESACTIVA EL PROYECTO

    a.estado =-1;
}
void modificarNombreProyecto(Proyecto a, char nombre[20]){ /// MODIFICA NOMBRE


    strcpy(a.nombre, nombre);
}
void modificarDescripcionProyecto(Proyecto a, char descripcion[255]){ /// MODIFICA DESCRIPCION

    strcpy(a.descripcion, descripcion);
}
void modificarValorProyecto(Proyecto a, int valor){ /// MODIFICA VALOR HORA

    a.valorHora = valor;
}
void inicArrayProyectos(Proyecto a[10]){ /// DESACTIVA TODOS LOS PROYECTOS DEL ARRAY

    for(int i = 0; i<10; i++){
        a[i].estado = -1;
    }
}
void archivo2ArrayProyecto(int idUser, Proyecto a[10]){ /// TOMA PROYECTOS DEL USUARIO DESDE EL ARCHIVO
    FILE* pArchProyectos = fopen(archProyectos, "rb");
    Proyecto aux;
    int i = 0;
    if(pArchProyectos){
        while(fread(&aux, sizeof(Proyecto), 1, pArchProyectos)&& i<10){
            if(aux.idUsuario == idUser && aux.estado != -1){
                a[i] = aux;
                i++;
            }
        }
    }
    fclose(pArchProyectos);
}
