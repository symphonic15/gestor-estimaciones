#include "Textin.h"

void crearTextBox(char pregunta[50]){
    color(112);
    int x= 10, y = whereY()+2;
    for(int j = 0; j< 3;j++){
        for(int i = 0; i< (strlen(pregunta)+5); i++){
            gotoxy(x + i,y+j);
            if((whereX()-x==3)&&(whereY()-y==1)){
                printf("%s", pregunta);
                i+=strlen(pregunta)-1;
            }else{
                printf(" ");
            }
        }
    }
    color(9);
}
void crearTextIntBox(char pregunta[50], int dato){
    color(112);
    int x= 10, y = whereY()+2;
    for(int j = 0; j< 3;j++){
        for(int i = 0; i< (strlen(pregunta)+12); i++){
            gotoxy(x + i,y+j);
            if((whereX()-x==3)&&(whereY()-y==1)){
                printf("%s ", pregunta);
                printf("%i", dato);
                i+=strlen(pregunta)+5;
            }else{
                printf(" ");
            }
        }
    }
    color(9);
}
void crearPreBox(char pregunta[50]){
    color(112);
    int x= 10, y = whereY()+2;
    int xf, yf;
    for(int j = 0; j< 3;j++){
        for(int i = 0; i< 70; i++){
            gotoxy(x + i,y+j);
            if((whereX()-x==3)&&(whereY()-y==1)){
                printf("%s", pregunta);
                i+=strlen(pregunta)-1;
                xf = whereX();
                yf = whereY();
            }else{
                printf(" ");
            }
        }
    }
    gotoxy(xf,yf);
}
Textin responderText(char pregunta[50]){
    Textin respuesta;
    crearPreBox(pregunta);
    fflush(stdin);
    gets(respuesta.resp);
    color(9);
    return respuesta;
}
int responderInt(char pregunta[50]){
    int res;
    crearPreBox(pregunta);
    fflush(stdin);
    scanf("%i", &res);
    color(9);
    return res;
}
