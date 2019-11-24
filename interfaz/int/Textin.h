#ifndef TEXTIN_H_INCLUDED
#define TEXTIN_H_INCLUDED

typedef struct{
    char resp[50];
}Textin;

void crearTextBox(char pregunta[50]);
Textin responderText(char pregunta[50]);
int responderInt(char pregunta[50]);


#endif // TEXTIN_H_INCLUDED
