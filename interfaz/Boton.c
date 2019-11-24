#include "Boton.h"

Boton crearBoton(int id, char cartel[50]) {
    color(112);
    int cor, x= 10, y = whereY();
    for(int j = 0; j< 3;j++){
        for(int i = 0; i< 70; i++){
            gotoxy(x + i,y+j);
            if((whereX()-x==3)&&(whereY()-y==1)){
                printf("%s", cartel);
                i+=strlen(cartel)-1;
            }else{
                printf(" ");
            }
            cor =y + j;
        }
    }
    Boton dato;
    strcpy(dato.cartel,cartel);
    dato.id = id;
    dato.x =whereX()-70;
    dato.y = whereY()-2;
    color(9);
    return dato;
}

Boton inicBoton(){
    Boton a;
    strcpy(a.cartel,"");
    a.x = -1;
    a.y = -1;
    return a;
}

void seleccionarBoton(Boton dato){
    color(79);
    int x= dato.x, y = dato.y;
    for(int j = 0; j< 3;j++){
        for(int i = 0; i< 70; i++){
            gotoxy(x + i,y+j);
            if((whereX()-x==3)&&(whereY()-y==1)){
                printf("%s", dato.cartel);
                i+=strlen(dato.cartel)-1;
            }else{
                printf(" ");
            }
        }
    }
    color(9);
}

void deseleccionarBoton(Boton dato){
    color(112);
    int x= dato.x, y = dato.y;
    for(int j = 0; j< 3;j++){
        for(int i = 0; i< 70; i++){
            gotoxy(x + i,y+j);
            if((whereX()-x==3)&&(whereY()-y==1)){
                printf("%s", dato.cartel);
                i+=strlen(dato.cartel)-1;
            }else{
                printf(" ");
            }
        }
    }
    color(9);
}

Boton asignarCoordenadas(Boton dato, int x, int y){
    dato.x = x;
    dato.y = y;
    return dato;
}
