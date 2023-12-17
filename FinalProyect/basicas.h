#ifndef BASICAS_H
#define BASICAS_H
#include <iostream>

#include <iostream>
#include <windows.h>
using namespace std;
class basicas
{
public:
    basicas();
    ~basicas();
    static void imprimirPantalla();
    static void imprimirPantalla2();
    static void gotoxy(int x, int y);
    static int menu(int posX, int posY);
    static int leerEntero(string mensaje);
    static string leerTexto(string mensaje);
    static float leerFloat( string mensaje );
    static bool leerEstado(string mensaje);
    static int menuTrabajadores(int posX, int posY);
    static int menuClientes(int posX, int posY);
    static int menuMesas(int posX, int posY);
    static int menuProductos(int posX, int posY);
    static int menuVentas(int posX, int posY);
    static int menuReportes(int posX, int posY);
};

#endif // BASICAS_H
