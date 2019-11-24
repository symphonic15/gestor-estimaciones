#include "Textin.h"



void crearTextBox(char pregunta[50]){
    color(176);
    int cor, x= 10, y = whereY();
    for(int j = 0; j< 3;j++){
        for(int i = 0; i< 70; i++){
            gotoxy(x + i,y+j);
            if((whereX()-x==3)&&(whereY()-y==1)){
                printf("%s", pregunta);
                i+=strlen(pregunta)-1;
            }else{
                printf(" ");
            }
            cor =y + j;
        }
    }
    color(9);
}
Textin responderText(char pregunta[50]){
    Textin respuesta;
    crearTextBox(pregunta);

    return respuesta;
}
int responderInt(char pregunta[50]){
    int res;
    crearTextBox(pregunta);
    return res;
}
