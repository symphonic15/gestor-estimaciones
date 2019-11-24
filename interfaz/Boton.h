#ifndef BOTON_H_INCLUDED
#define BOTON_H_INCLUDED
typedef struct{
    char cartel[50];
    int id;
    int x;
    int y;
}Boton;

Boton crearBoton(int id, char cartel[50]);
Boton inicBoton();
void seleccionarBoton(Boton dato);
void deseleccionarBoton(Boton dato);
Boton asignarCoordenadas(Boton dato, int x, int y);


#endif // BOTON_H_INCLUDED
