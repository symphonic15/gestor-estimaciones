#include "proyectoVista.h"

Proyecto vCrearProyecto(int idUsuario){ /// VISTA CREAR PROYECTO
    Proyecto aux;
    printf("\n Ingrese nombre de proyecto: ");
    gets(aux.nombre);
    printf("\n Ingrese descripcion: ");
    gets(aux.descripcion);
    printf("\n Ingrese valor por hora: ");
    scanf("%i",&aux.valorHora);
    aux.estado = 1;
    aux.idUsuario = idUsuario;
    crearProyecto(aux);
    return aux;
}

void vModificarProyecto(int id){
    int res;
    Proyecto pro = buscarPorId(id);
    switch(res){
        case 1:
            vModificarNombreProyecto(pro);
        break;
        case 2:
            vModificarDescripcionProyecto(pro);
            break;
        case 3:
            vModificarValorProyecto(pro);
            break;
        case 4:
            eliminarProyecto(pro);
            break;
        case 5:
            printf("menu volver"); /// volver al menu
    }
    persistirProyecto(pro);
}

void vEliminarProyecto(Proyecto a){ /// VISTA ELIMINA PROYECTO
    char nom;
    printf("\n Eliminar proyecto press s ");
    getc(nom);
    if(nom == 's')eliminarProyecto(a);
}

void vModificarNombreProyecto(Proyecto a){ /// VISTA MODIFICA NOMBRE DE PROYECTO
    char nombre[20];
    printf("\n Ingresar nombre nuevo: ");
    gets(nombre);
    modificarNombreProyecto(a, nombre);
}
void vModificarDescripcionProyecto(Proyecto a){ /// VISTA MODIFICA DESCRIPCION DE PROYECTO
    char descrip[255];
    printf("\n Ingresar descripcion nuevoa: ");
    gets(descrip);
    modificarDescripcionProyecto(a, descrip);
}
void vModificarValorProyecto(Proyecto a){ /// VISTA MODIFICA VALOR HORA DE PROYECTO
    int valor;
    printf("\n Ingresar valor por hora: ");
    scanf("%i",&valor);
    modificarValorProyecto(a, valor);
}

void vMostrarProyecto(Proyecto a){ /// VISTA MUESTRA UN PROYECTO
    printf("\n -------------------------------- \n");
    printf("Proyecto %s \n", a.nombre);
    printf("\n %s \n", a.descripcion);
    printf("\n Valor por hora: %i", a.valorHora);
    printf("\n -------------------------------- \n");
}

void vListarProyectos(Proyecto a[10]){ /// LISTA PROYECTOS DE ARRAY
    for(int i = 0; i<10; i++){
        if(a[i].estado != -1){
            vMostrarProyecto(a[i]);
        }
    }
}

void vListarProUser(Usuario a){ /// VISTA LISTA PROYECTOS DE UN USUARIO
    Proyecto arr[10];
    inicArrayProyectos(arr);
    archivo2ArrayProyecto(a.id, arr);
    vListarProyectos(arr);
}
